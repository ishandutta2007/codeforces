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

int n ,m ,k;
int s[N];
vector<int> v[N];

double h[N];
int f[N];
int q[N], q1, q2;

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) scanf("%d", &s[i]), s[i]--;

	for (int i = 0; i < m; i++) {
		int x , y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}

	double l = 0;
	double r = 1;
	vector<int> ans;
	for (int it = 0; it < 90; it++) {
		double mid = (l + r ) / 2;
		for (int i = 0; i < n; i++) h[i] = 1, f[i] = 0;

		q1 = q2 = 0;
		for (int i = 0; i < k; i++) {
			q[q1++] = s[i];
			f[s[i]] = 1;
		}

		if (ans.size() == 0) {
			for (int i = 0; i < n; i++) if (!f[i]) ans.pb(i);
		}	

		while (q1 != q2) {
			int x = q[q2++];
			f[x] = 1;
			for (int i = 0; i < v[x].size(); i++) {
				int to = v[x][i];
				h[to] -= 1. / v[to].size();
				if (h[to] < mid && f[to] == 0) {
					f[to] = 1;
					q[q1++] = to;
				}
			}
		}
		if (q1 == n) r = mid; else {
			l = mid;
			ans.clear();
			for (int i = 0; i< n; i++) if (!f[i]) ans.pb(i);
		}			
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i] + 1);
		if (i + 1 == ans.size()) puts(""); else putchar(' ');
	}
	return 0;
}