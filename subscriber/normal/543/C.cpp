#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, m;
string s[22];
int a[22][22];

int dp[3000333];

int be[22];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i< n; i++) cin >> s[i];
	forn(i, n) forn(j, m) cin >> a[i][j];

	for (int i = 0; i < pw(n); i++) dp[i] = 1e9;
	dp[0] = 0;

	int fr = 0;

	for (int i = 0; i < m; i++) {
		for (char c = 'a'; c <= 'z'; c++) {
			int mask = 0;
			vector<int> e;
			for (int j = 0; j < n; j++) if (s[j][i] == c) {
				mask |= pw(j);
				e.pb(a[j][i]);
			}
			if (mask == 0) continue;
			if (e.size() == 1) {
				fr |= mask;
				continue;
			}

			sort(e.begin(), e.end());
			int cost = 0;
			for (int j = 0; j < e.size() - 1; j++) cost += e[j];

			for (int j = 0; j < pw(n); j++) dp[j | mask] = min(dp[j | mask], dp[j] + cost);
		}
	}
	for (int i = 0; i < n; i++) {
		be[i] = 1e9;
		for (int j = 0; j < m; j++) be[i] = min(be[i], a[i][j]);
	}

	int ans = 1e9;
	for (int i = 0; i < pw(n); i++) {
		int re = pw(n) - 1 - (i | fr);

		int cost = dp[i];
		for (int j = 0; j < n; j++) if (re & pw(j)) cost += be[j];
		ans = min(ans, cost);
	}		
	cout << ans << endl;
	return 0;

}