#include <bits/stdc++.h>
#define ll long long
#define maxn 1015 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int rk[maxn][maxn];
int sa[maxn][maxn];
int tr[maxn][maxn], tl[maxn]; //  
int nx[maxn][10]; // 
int w[maxn][10]; //  
int ra[maxn], rl;
char inp[maxn];
int dp[maxn][maxn]; // >= c 
vi read() {
	scanf("%s", inp);
	int l = strlen(inp);
	vi res(l);
	for (int i = 0; i < l; i++)
		res[i] = inp[l - 1 - i] - '0';
	return res;
}
int c[10];
int calw(int id, int pl, int num) {
	if (num == 0 && tl[id] <= pl && rl <= pl + 1) return 0;
	return c[num % 10];
}
int main() {
	vi a = read();
	rl = a.size();
	for (int j = 0; j < rl; j++) {
		ra[j] = a[j];
		if (a[j] == '?' - '0') ra[j] = -1;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vi b = read();
		tl[i] = b.size();
		for (int j = 0; j < tl[i]; j++)
			tr[i][j] = b[j];
	}
	for (int i = 0; i < 10; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < maxn; i++) {
		vector<pi> q;
		for (int j = 0; j < n; j++) {
			int ur = 0;
			if (i) ur = rk[i - 1][j];
			ur = tr[j][i] * (n + 1) + ur;
			q.pb(mp(ur, j)); 
		}
		sort(q.begin(), q.end());
		for (int j = 0; j < n; j++)
			sa[i][j] = q[j].se;
		
		for (int j = 0; j < n; ) {
			int k = j;
			while (k < n && q[k].fi == q[j].fi) 
				k++;
			for (int l = j; l < k; l++)
				rk[i][q[l].se] = j;
			j = k;
		}
		/*
		for (int j = 0; j < n; j++) {
			int id = q[j].se;
			rk[i][id] = j;
			sa[i][j] = id;
		}*/
	}
	for (int i = maxn - 5; i >= 0; i--) {
		for (int j = n; j >= 0; j--) {
			//  dp
			for (int k = 0; k < 10; k++) {
				if (j == n) {
					int ms = n, ws = 0;
					for (int s = 0; s < n; s++) {
						int nq = tr[s][i] + k;
						if (nq >= 10) ms = min(ms, rk[i][s]);
						ws += calw(s, i, nq);
					}
					w[j][k] = ws;
					nx[j][k] = ms;
				}
				else {
					w[j][k] = w[j + 1][k];
					nx[j][k] = nx[j + 1][k];
					if (i) {
						int nid = sa[i - 1][j];
						int bg = tr[nid][i] + 1 + k;
						if (bg >= 10) nx[j][k] = min(nx[j][k], rk[i][nid]);
						w[j][k] -= calw(nid, i, bg - 1);
						w[j][k] += calw(nid, i, bg); 
					}
				}
			//	
			} 
			for (int k = 0; k < 10; k++) {
				if (i >= rl && k) continue;
				if (i == rl - 1 && (k == 0)) continue;
				if (ra[i] != -1 && (ra[i] != k)) continue;
				dp[i][j] = max(dp[i][j], dp[i + 1][nx[j][k]] + w[j][k]);
			}
		}
	}
	cout << dp[0][n] << endl; 
	return 0;
}
/*
5 3
2
1 3
2 3
1
1 3

*/