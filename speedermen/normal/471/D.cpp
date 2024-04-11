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
#define nmax 500010
#define mmax 400010
#define eps 1e-7

const int P = 239, mod = 239017;

int a[nmax], n, w;
ll hp[nmax], H[nmax];
int b[nmax];

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("message.in", "r", stdin); freopen("message.out", "w", stdout);
	cin >> n >> w;
	if(w == 1) {
		cout << n << endl;
		exit(0);
	}
	hp[0] = 1;
	for(int i = 1; i < nmax; ++i)
		hp[i] = (P * 1LL * hp[i - 1]) % mod;
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i < n; ++i) {
		a[i] -= a[i + 1];
		if(a[i] < 0)
			a[i] += mod;
	}
	for(int i = 1; i <= w; ++i)
		scanf("%d", &b[i]);
	for(int i = 1; i < w; ++i) {
		b[i] -= b[i + 1];
		if(b[i] < 0)
			b[i] += mod;
	}
	for(int i = 1; i < n; ++i)
		H[i] = (a[i] * 1LL * hp[i] + H[i - 1]) % mod;
	ll HH = 0;
	for(int i = 1; i < w; ++i)
		HH = (b[i] * 1LL * hp[i] + HH) % mod;
	int ans = 0;
	for(int i = 1; i + w - 2 < n; ++i) {
		ll h = (H[i + w - 2] - H[i - 1] + mod) % mod;
		if(h == (HH * 1LL * hp[i - 1]) % mod) {
			++ans;
		}
	}
	cout << ans << endl;
	//while(1);
	return 0;
}