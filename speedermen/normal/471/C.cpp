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
#define nmax 200010
#define mmax 400010
#define eps 1e-7

ll dp[1000010], n;

ll f(ll d) {
	return d * (d + 1) + d * (d - 1) / 2;
}

bool ok(ll d, ll i) {
	return d % 3 == 0;
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("message.in", "r", stdin); freopen("message.out", "w", stdout);
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= 1000000; ++i)
		if(n >= f(i))
			ans += ok(n - f(i), i);
	cout << ans << endl;
	//while(1);
	return 0;
}