#include <bits/stdc++.h>
#define ll long long
#define maxn 3000005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int tp[2][maxn];
int dp[2][maxn], bg[2][maxn];
int st[maxn], fl[maxn], sm[maxn];
vi dr, uu;
vi x[2];
int main() {
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < 2; j++)
			dp[j][i] = -1;
	int n, m[2], t;
	cin >> n >> m[0] >> m[1] >> t;
	for (int i = 0; i < 2; i++) {
		x[i].resize(m[i]);
		for (int j = 0; j < m[i]; j++) 
			scanf("%d", &x[i][j]), 
			dr.pb(x[i][j] - 1), 
			dr.pb(x[i][j] + 1), 
			dr.pb(x[i][j]);
	}
	dr.pb(0), dr.pb(n + 1);
	sort(dr.begin(), dr.end());
	for (int i = 0; i < dr.size(); i++)
		if (i == 0 || dr[i - 1] != dr[i])
			uu.pb(dr[i]);
	for (int i = 0; i < 2; i++)	
		for (auto v : x[i])
			tp[i][lower_bound(uu.begin(), uu.end(), v) - uu.begin()] = 1;
//	cout << "!" << endl;
	dp[0][0] = dp[1][0] = bg[0][0] = bg[1][0] = 0;
	for (int i = 0; i < uu.size() - 1; i++) {
		int u[2];
		u[0] = dp[0][i], u[1] = dp[1][i];
		int dis = uu[i + 1] - uu[i];
		for (int j = 0; j < 2; j++) {
			if (u[j] < 0) continue;
			if (!tp[j][i + 1]) {
				if (dp[j][i + 1] < u[j] + dis)
					dp[j][i + 1] = u[j] + dis, 
					bg[j][i + 1] = j;
				if (!tp[j ^ 1][i + 1]) {
					int nans = min(t - 1, u[j] + dis - 1) + 1;
					if (dp[j ^ 1][i + 1] < nans)
						dp[j ^ 1][i + 1] = nans, 
						bg[j ^ 1][i + 1] = j;
 				}
 			}
 			else {
 				if (u[j] < t) continue;
				int nans = u[j] - t + dis;
				if (dp[j][i + 1] < nans)
					dp[j][i + 1] = nans, 
					bg[j][i + 1] = j;
				if (!tp[j ^ 1][i + 1]) {
					int ca = min(t - 1, u[j] - t + dis - 1) + 1;
					if (dp[j ^ 1][i + 1] < ca)
						dp[j ^ 1][i + 1] = ca, 
						bg[j ^ 1][i + 1] = j;
				}	
			}	
		}
	
	}
	if (dp[0][uu.size() - 1] < 0) printf("No\n");
	else {
		printf("Yes\n");
		int cpl = 0;
		for (int i = uu.size() - 1; i >= 0; i--) {
	//		cout << i << ' ' << cpl << endl;
			st[i] = cpl;
			if (cpl != bg[cpl][i]) fl[i] = 1;
			cpl = bg[cpl][i];
		}
		vi fn;
		for (int i = 0; i < uu.size(); i++)
			if (fl[i]) fn.pb(uu[i]);
		cout << fn.size() << endl;
		for (auto v : fn) {
			printf("%d ", v); 
		} 
		printf("\n");
		for (int i = uu.size() - 1; i >= 0; i--) {
			sm[i] = tp[st[i]][i];
		
			 
			if (st[i + 1] == st[i]) sm[i] += sm[i + 1];
			else sm[i] += tp[st[i]][i + 1];	
	//		cout << st[i] << ' ' << i << ' ' << sm[i] << ' ' << tp[st[i]][i] << endl;
		}
	//	cout << "???" << endl;
		vector<pi> cu;
		int cw = 0, cr = 0, ms = sm[0]; // cr :   cw :  
		for (int i = 0; i < uu.size() - 1; i++) {
			int npl = uu[i];
			while (cr < ms) {
				if (npl + max(0, t - cw) < uu[i + 1]) {
					int epl = npl + max(0, t - cw);
					cw += epl - npl, npl = epl;
					cu.pb(mp(npl, st[i] + 1));
					cr++;
					cw -= t;
				}
				else break;
			}
			if (st[i + 1] == st[i]) cw += uu[i + 1] - npl;
			else {
				cr = 0;
				cw += uu[i + 1] - npl - 1;
				cw = min(cw, t - 1) + 1;
				ms = sm[i + 1];
			}
		}
		cout << cu.size() << endl;
		for (auto v : cu) {
			printf("%d %d\n", v.fi, v.se);
		}
	}
	return 0;
}
/*
10 8 5 2
3 4 5 6 7 8 9 10
1 2 5 7 9 
*/