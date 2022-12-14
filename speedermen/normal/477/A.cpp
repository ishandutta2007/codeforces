#pragma comment(linker, "/STACK:100000000")
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <complex>
#include <string>
#include <bitset>
#include <vector>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef complex < double > cd;
 
const bool db = false;
 
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define sd second
#define fs first
 
#define inf 1000000007
#define nmax 100010
#define mmax 20010
#define eps 1e-9

int a, b;
int last[10], cnt[10];

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll G(ll s, ll cnt, ll d) {
	s %= inf; d %= inf;
	return (s + s + d * (cnt - 1)) % inf * cnt % inf * ((inf + 1) / 2) % inf;
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("tree.in", "r", stdin); freopen("tree.out", "w", stdout);
	scanf("%d%d", &a, &b);
	if(b == 1) {
		cout << 0 << endl;
		return 0;
	}
	ll res = 0, cur = 0;
	memset(last, -1, sizeof(last));
	for(int r = 1; r < b; ++r)
		res = (res + G(r * 1LL * b + r, a, r * 1LL * b)) % inf;
	/*for(int r = 1; r <= a * a * b; ++r) {
		if(r % b != 0) {
			if((r / b) % (r % b) == 0 && 1 <= (r / b) / (r % b) && (r / b) / (r % b) <= a) {
				cur += r;
				if(last[r % b] != -1) {
					if(r - last[r % b] != r % b * b)
						cout << last[r % b] << " " << r << endl;
				}
				last[r % b] = r; ++ cnt[r % b];
			}
		}
	}*/
	cout << res << endl;
	cin.get(); cin.get();
	return 0;
}