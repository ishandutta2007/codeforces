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

ll n, l, x, y;
ll a[nmax];
vector < ll > len;
set < ll > s;

vector < pair < ll, ll > > ok(ll x) {
	ll l = 1, r = 1;
	vector < pair < ll, ll > > res;
	while(r <= n) {
		while(r + 1 <= n && a[r + 1] - a[l] <= x)
			++r;
		if(a[r] - a[l] == x)
			res.pb(mp(l, r));
		if(++r == n + 1)
			break;
		while(a[r] - a[l] > x)
			++l;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
	//ios :: sync_with_stdio(false);
	cin >> n >> l >> x >> y;
	for(int i = 1; i <= n; ++i)
		cin >> a[i], s.insert(a[i]);
	bool A = (0 != ok(x).size()), B = (0 != ok(y).size());
	if(A + B == 2) {
		cout << 0 << endl;
	} else if(A + B == 1) {
		if(!B) cout << 1 << "\n" << y << endl;
		if(!A) cout << 1 << "\n" << x << endl;
	} else {
		if(ok(x + y).size()) {
			vector < pair < ll, ll > > V = ok(y + x);
			for(int i = 0; i < V.size(); ++i) {
				ll L = V[i].fs, R = V[i].sd;
				if(a[L] + x <= l) {
					cout << 1 << endl;
					cout << a[L] + x << endl;
					return 0;
				}
			}
		}
		if(ok(y - x).size()) {
			vector < pair < ll, ll > > V = ok(y - x);
			for(int i = 0; i < V.size(); ++i) {
				ll L = V[i].fs, R = V[i].sd;
				if(a[L] - x >= 0) {
					cout << 1 << endl;
					cout << a[L] - x << endl;
					return 0;
				}
				if(a[R] + x <= l) {
					cout << 1 << endl;
					cout << a[R] + x << endl;
					return 0;
				}
			}
		}
		cout << 2 << endl;
		cout << x << " " << y << endl;
	}
	getchar(); getchar();
	return 0;
}