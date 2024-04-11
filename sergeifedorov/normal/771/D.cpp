#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 80;

string s;
int n;
int dp[nmax][nmax][nmax][nmax];
int ka, kv, kk;
int pa[nmax], pv[nmax], pk[nmax];
int ca[nmax], cv[nmax], ck[nmax];

int get(int rk, int rv, int ra, int pos) {
	return max(0, ca[pos] - ra) + max(0, cv[pos] - rv) + max(0, ck[pos] - rk);
}

void go(int &a, int b, int c) {
	if (b < 0 || c < 0) return;
	if (a == -1 || a > b + c)
		a = b + c;
}

int main ()
{
	//  freopen("input.txt", "rt", stdin);
	//  freopen("output.txt", "wt", stdout);
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		ca[i] = ka;
		cv[i] = kv;
		ck[i] = kk;
		if (s[i] == 'V') {
			pv[kv] = i;
			kv ++;
		} else if (s[i] == 'K') {
			pk[kk] = i;
			kk ++;
		} else {
			pa[ka] = i;
			ka ++;
		}
	}
	memset(dp, 255, sizeof dp);
	dp[0][0][0][0] = 0;
	for (int rk = 0; rk <= kk; rk ++)
		for (int rv = 0; rv <= kv; rv ++)
			for (int ra = 0; ra <= ka; ra++)
				for (int lu = 0; lu < 3; lu ++) 
					if (dp[rk][rv][ra][lu] != -1) {
						if (lu != 1 && rk != kk)
							go(dp[rk + 1][rv][ra][0], dp[rk][rv][ra][lu], get(rk, rv, ra, pk[rk]));
						if (rv != kv)
							go(dp[rk][rv + 1][ra][1], dp[rk][rv][ra][lu], get(rk, rv, ra, pv[rv]));
						if (ra != ka)
							go(dp[rk][rv][ra + 1][2], dp[rk][rv][ra][lu], get(rk, rv, ra, pa[ra]));
					}
	int res = -1;
	go(res, dp[kk][kv][ka][0], 0);
	go(res, dp[kk][kv][ka][1], 0);
	go(res, dp[kk][kv][ka][2], 0);
	cout << res << endl;

	return 0;
}