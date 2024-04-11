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

int n;
string s;

pair<pair<int, int>, int> p[N];

int c[22][N];

int dp[5005][5005], ic[5005][5005];

int it;
int gg[N];


bool ge(int len, int x, int y) {
	int w = gg[len];

	return mp(c[w][x], c[w][x + len - pw(w)]) >= mp(c[w][y], c[w][y + len - pw(w)]);
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> s;
	for (int i = 0; i < n; i++) p[i] = mp(mp(s[i], 0), i);
	sort(p, p + n);
	int e = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && p[i].F != p[i - 1].F) e++;
		c[0][p[i].S] = e;
	}
	it = 0;
	while (pw(it) < n) {
		it++;
		for (int i = 0; i < n; i++) if (i + pw(it - 1) < n) p[i] = mp(mp(c[it - 1][i], c[it - 1][i + pw(it - 1)]), i); else
			p[i] = mp(mp(c[it - 1][i], -1), i);
		sort(p, p + n);			
		e = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 && p[i].F != p[i - 1].F) e++;
			c[it][p[i].S] = e;
		}
	}
	gg[1] = 0;
	for (int i = 2; i <= n; i++) gg[i] = gg[i / 2] + 1;
	for (int i = 0; i < n; i++) dp[0][i] = 1;
	for (int i = 0; i < n; i++) for (int j = i; j < n; j++) {
		if (j > 0) ic[i][j] = (ic[i][j - 1] + ic[i][j]) % M;
		dp[i][j] = (dp[i][j] + ic[i][j]) % M;

		if (s[i] == '0') dp[i][j] = 0;
		
		int l = j + 1;
		int r = l + (j - i);
		if (r >= n) continue;

	 	if (ge(j - i + 1, i, l)) r++;

//	 	cout << i << " " << j << " " << l << " " << r << endl;
	 	
	 	ic[l][r] = (ic[l][r] + dp[i][j]) % M;

	}
	int ans = 0;
	for (int i = 0; i < n; i++) ans = (ans + dp[i][n - 1]) % M;
	cout << ans << endl;
	return 0;
}