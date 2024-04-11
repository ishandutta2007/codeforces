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
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, p;
int c[4444], h[4444], t[4444];

int gr;
vector<int> ids[4444];
int mi[4444], ma[4444];

vector<vector<int> > dp1[4004], dp2[4004];

pair<int, int> q[4444];


int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);

	cin >>  n >> p;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &c[i], &h[i], &t[i]);
		t[i] = t[i] + p - 1;
	}		
	
	for (int i = 0; i < n; i++) q[i] = mp(t[i] / p, i);

	sort(q, q + n);

	for (int i = 0; i < n; ) {	
		int j = i;
		while (j < n && q[i].F == q[j].F) {
			ids[gr].pb(q[j].S);
			j++;
		}
		i = j;
		gr++;
	}

	for (int i = 0; i < gr; i++) {

		for (int j = 0; j < ids[i].size(); j++) for (int k = j + 1; k < ids[i].size(); k++)
			if (t[ids[i][k]] < t[ids[i][j]]) swap(ids[i][j], ids[i][k]);

/*		for (int j = 0; j < ids[i].size(); j++) cout << t[ids[i][j]] << " ";
		cout << endl;*/
			

		mi[i] = t[ids[i][0]];
		ma[i] = t[ids[i].back()];

		int sz = ids[i].size();

		dp1[i].resize(sz + 1);
		for (int j = 0; j <= sz; j++) dp1[i][j].resize(4001);

		for (int j = 0; j <= sz; j++) for (int k = 0; k <= 4000; k++) dp1[i][j][k] = 0;

		for (int j = 0; j < sz; j++) for (int k = 0; k <= 4000; k++) {
			dp1[i][j + 1][k] = max(dp1[i][j + 1][k], dp1[i][j][k]);
			

			if (k + c[ids[i][j]] <= 4000) dp1[i][j + 1][k + c[ids[i][j]]] = max(dp1[i][j + 1][k + c[ids[i][j]]], dp1[i][j][k] + h[ids[i][j]]);
		}


		dp2[i].resize(sz + 1);
		for (int j = 0; j <= sz; j++) dp2[i][j].resize(4001);

		for (int j = 0; j <= sz; j++) for (int k = 0; k <= 4000; k++) dp2[i][j][k] = 0;

		for (int j = 0; j < sz; j++) for (int k = 0; k <= 4000; k++) {
			dp2[i][j + 1][k] = max(dp2[i][j + 1][k], dp2[i][j][k]);
			

			if (k + c[ids[i][sz - 1 - j]] <= 4000) dp2[i][j + 1][k + c[ids[i][sz - 1 - j]]] = max(dp2[i][j + 1][k + c[ids[i][sz - 1 - j]]], dp2[i][j][k] + h[ids[i][sz - 1 - j]]);
		}

		for (int j = 0; j <= sz; j++) for (int k = 1; k <= 4000; k++) {
			dp1[i][j][k] = max(dp1[i][j][k], dp1[i][j][k - 1]);
			dp2[i][j][k] = max(dp2[i][j][k], dp2[i][j][k - 1]);
		}
	}
	int m;
	cin >> m;
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int q1 = -1;
		int sz1 = 0;

		for (int i = gr - 1; i >= 0; i--) if (a <= mi[i] && mi[i] <= a + p - 1) {
			q1 = i;
			for (int j = 0; j < ids[i].size(); j++) if (t[ids[i][j]] <= a + p - 1) sz1++; else break;
			break;
		}

		int q2 = -1;
		int sz2 = 0;

		for (int i = 0; i < gr; i++) if (ma[i] >= a && ma[i] <= a + p - 1) {
			q2 = i;
			for (int j = 0; j < ids[i].size(); j++) if (t[ids[i][ids[i].size() - 1 - j]] >= a) sz2++; else break;
			break;
		}
		if (q1 == q2) q2 = -1;

		int ans = 0;
		if (q1 == -1 && q2 == -1) ans = 0; else
		if (q2 == -1) {
			ans = dp1[q1][sz1][b];
		} else if (q1 == -1) {
			ans = dp2[q2][sz2][b];
		} else {
			for (int i = 0; i <= b; i++) ans = max(ans, dp1[q1][sz1][i] + dp2[q2][sz2][b - i]);
		}
		printf("%d\n", ans);
	}

	return 0;
}