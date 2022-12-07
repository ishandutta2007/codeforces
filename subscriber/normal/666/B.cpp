#include<stdio.h>
#include<ctime>
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
vector<int> v[3033];
int d[3033][3033];

int q[6666], q1, q2;


long long rd() {
	long long r = 0;
	for (int i = 0; i < 20; i++) r = r * 2 + rand() % 2;
	return r;
}

int dp[3033][4], pr[3033][4];
int p[3033];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	srand((int)time(0));
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].pb(y);
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = 1e9 + 1;
	for (int s = 0; s < n; s++) {
		q1 = q2 = 0;
		q[q1++] = s;
		d[s][s] = 0;
		while (q1 != q2) {
			int x = q[q2++];
			for (int i = 0; i < v[x].size(); i++) {
				int to = v[x][i];
				if (d[s][to] < 1e9) continue;
				d[s][to] = d[s][x] + 1;
				q[q1++] = to;
			}
		}
	}
	int ans = -1;
	vector<int> out;

	int st = clock();
	while ((clock() - st) / 1. / CLOCKS_PER_SEC < 4.7) {
		for (int i = 0; i < n; i++) p[i] = i;
		for (int i = 0; i < n; i++) {
			int t = rd() % (i + 1);
			swap(p[i], p[t]);
		}
		for (int i = 0; i < n; i++) for (int j = 0; j <= 3; j++) dp[i][j] = -1;
		for (int i = 0; i < n; i++) dp[i][0] = 0;

		for (int i = 0; i < n; i++) for (int k = i + 1; k < n; k++) {
			int gg = d[p[i]][p[k]];
			if (gg >= 1e9) continue;
			for (int j = 0; j < 3; j++) if (dp[i][j] >= 0) {
				int val = dp[i][j] + gg;
				if (val > dp[k][j + 1]) {
					dp[k][j + 1] = val;
					pr[k][j + 1] = i;
				}
			}
		}							
		int be = -1;
		int x = -1;
		for (int i = 0; i < n; i++) if (dp[i][3] > be) {
			be = dp[i][3];
			x = i;
		}			
		if (be <= ans) continue;
		ans = be;
		out.clear();
		for (int j = 3; j > 0; j--) {
			out.pb(p[x]);
			x = pr[x][j];
		}
		out.pb(p[x]);
		reverse(out.begin(), out.end());
	}
//	cout << ans << endl;
	for (int i = 0; i < 4; i++) {
		cout << out[i] + 1;
		if (i + 1 == 4) cout << endl; else cout << " ";

	}

	return 0;
}