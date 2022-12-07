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

int q[N], q1, q2;

int dp[N][2], cnt[N][2];

int n;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	int sz;
	cin >> sz;
	vector<int> e[2];
	e[0].resize(sz);
	for (int i = 0; i < sz; i++) cin >> e[0][i];

	cin >> sz;
	e[1].resize(sz);
	for (int i = 0; i < sz; i++) cin >> e[1][i];

	dp[0][0] = 1;
	dp[0][1] = 1;

	q[q1++] = 0;
	q[q1++] = 0;
	q[q1++] = 0;
	q[q1++] = 1;

	while (q1 != q2) {
		int x = q[q2++];
		int h = q[q2++];


		if (dp[x][h] == 1) {
			for (int i = 0; i < e[h ^ 1].size(); i++) {
				int y = x - e[h ^ 1][i];
				if (y < 0) y += n;

				if (dp[y][h ^ 1] == 0) {
					dp[y][h ^ 1] = 2;
					q[q1++] = y;
					q[q1++] = h ^ 1;
				}
			}
		} else {
			for (int i = 0; i < e[h ^ 1].size(); i++) {
				int y = x - e[h ^ 1][i];
				if (y < 0) y += n;

				if (dp[y][h ^ 1] != 0) continue;
				cnt[y][h ^ 1]++;
				if (cnt[y][h ^ 1] == e[h ^ 1].size()) {
					dp[y][h ^ 1] = 1;
					q[q1++] = y;
					q[q1++] = h ^ 1;
				}
			}
			
		}
	}
	for (int w = 0; w < 2; w++) {
		for (int i = 1; i < n; i++) {
			if (dp[i][w] == 2) cout << "Win "; else
			if (dp[i][w] == 1) cout << "Lose "; else cout << "Loop ";
		}
		cout << endl;
	}

	return 0;
}