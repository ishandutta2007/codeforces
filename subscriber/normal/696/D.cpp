#include<bits/stdc++.h>
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

int n;
long long l;
int cost[N], cc[N], p[N];
int q[N], q1, q2;
int sp[N][33];

long long dp[66][222][222];
long long my[222][222], r[222][222];
int st;


int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> l;
	for (int i = 0; i < n; i++) cin >> cost[i];

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int h = 0;

		for (int j = 0; j < s.size(); j++) {
			int ch = s[j] - 'a';
			if (sp[h][ch] > 0) h = sp[h][ch]; else {
				st++;
				sp[h][ch] = st;
				h = st;
			}
		}
		cc[h] += cost[i];
	}

	q[q1++] = 0;
	q[q1++] = 0;
	q[q1++] = 0;

	while (q1 != q2) {
		int x = q[q2++];
		int pr = q[q2++];
		int ch = q[q2++];
		if (pr != 0) {
			int t = p[pr];
			while (t > 0 && sp[t][ch] == 0) t = p[t];
			if (sp[t][ch]) p[x] = sp[t][ch]; else p[x] = 0;
		}
		for (int i = 0; i < 26; i++) if (sp[x][i] > 0) {
			q[q1++] = sp[x][i];
			q[q1++] = x;
			q[q1++] = i;
		}
	}
	for (int i = 0; i < q1; i += 3) cc[q[i]] += cc[p[q[i]]];

	int k = st + 1;

	for (int i = 0; i < 50; i++) for (int j = 0; j < k; j++) for (int l = 0; l < k; l++) dp[i][j][l] = -2.1e18;

	for (int i = 0; i < k; i++) for (int ch = 0; ch < 26; ch++) {
		int t = i;
		while (t > 0 && sp[t][ch] == 0) t = p[t];
		if (sp[t][ch] == 0) t = 0; else t = sp[t][ch];
		dp[0][i][t] = max(dp[0][i][t], 1ll * cc[t]);
	}
	for (int i = 1; i < 50; i++) 
	for (int x = 0; x < k; x++) for (int y = 0; y < k; y++) for (int z = 0; z < k; z++)
		dp[i][x][z] = max(dp[i][x][z], dp[i - 1][x][y] + dp[i - 1][y][z]);

	for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) my[i][j] = -2.1e18;
	my[0][0] = 0;

	for (int i = 0; i < 50; i++) if (l & pw(i)) {
		for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) r[i][j] = -2.1e18;
		for (int x = 0; x < k; x++) for (int y = 0; y < k; y++) for (int z = 0; z < k; z++)
			r[x][z] = max(r[x][z], my[x][y] + dp[i][y][z]);
		
		for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) my[i][j] = r[i][j];
	}	
	long long ans = 0;
	for (int i = 0; i < k; i++) ans = max(ans, my[0][i]);
	cout << ans << endl;


	return 0;
}