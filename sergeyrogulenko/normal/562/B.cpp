#pragma comment(linker, "/STACK:100000000")
#define _CRT_SECURE_NO_DEPRECATE

#include<set>
#include<map>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<bitset>
#include<cmath>
#include<complex>
#include<ctime>
#include<iostream>
#include<sstream>
#include<vector>

#define next nexthui
#define prev prevhui
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n)-1; i >= 0; i--)
#define fs first
#define sc second
#define all(x) x.begin(), x.end()
#define sqr(x) ((x)*(x))
#define last(x) ((int)x.size()-1)

using namespace std;

typedef long long int64;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = (1 << 30) - 1;
const int64 INF64 = (1LL << 62) - 1;
const ldb EPS = 1e-9;

const int NMAX = 1000 * 1000;

int n;
int s[NMAX + 50];
int ans[NMAX + 50];
vector<int> d[NMAX + 50];

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	memset(ans, 0, sizeof(ans));
	forn(i, n) {
		int x;
		scanf("%d", &x);
		s[x]++;
	}
	for (int i = 2; i <= NMAX; i++)
		if (d[i].size() == 0) {
			int v = i;
			while (v <= NMAX) {
				d[v].push_back(i);
				v += i;
			}
		}
	int res = 0;
	for (int i = 1; i <= NMAX; i++) {
		ans[i] = s[i];
		forn(j, d[i].size()) {
			ans[i] = max(ans[i], s[i] + ans[i / d[i][j]]);
		}
		res = max(res, ans[i]);
	}
	cout << res << endl;
}