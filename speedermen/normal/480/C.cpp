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
#define mmax 150010
#define eps 1e-9

int n, k, a, b;
ll inc[6010], ninc[6010];

void add(int l, int r, int x, ll val) {
	ninc[l] += val; ninc[x] -= val;
	ninc[x + 1] += val; ninc[r + 1] -= val;
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
	//ios :: sync_with_stdio(false);
	scanf("%d%d%d%d", &n, &a, &b, &k);
	inc[a] = 1; inc[a + 1] = -1;
	for(int i = 0; i < k; ++i) {
		memset(ninc, 0, sizeof(ninc));
		ll bal = 0;
		for(int c = 1; c <= b - 1; ++c) {
			int len = (b - c); 
			bal += inc[c];
			add(max(c - len + 1, 1), min(c + len - 1, b - 1), c, bal % inf);
		}
		bal += inc[b];
		for(int c = b + 1; c <= n; ++c) {
			int len = (c - b); 
			bal += inc[c];
			add(max(c - len + 1, b + 1), min(c + len - 1, n), c, bal % inf);
		}
		memcpy(inc, ninc, sizeof(inc));
	}
	ll bal = 0, ans = 0;
	for(int i = 1; i <= n; ++i) {
		bal += inc[i];
		if(i != b)
			ans += bal % inf;
	}
	cout << ans % inf << endl;
	getchar(); getchar();
	return 0;
}