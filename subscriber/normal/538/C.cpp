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
int n, m, x[N], y[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) scanf("%d%d", &x[i], &y[i]);

	int ans = -1;
	for (int i = 0; i < m; i++) ans = max(ans, y[i]);

	for (int i = 1; i < m; i++) {
		int d = x[i] - x[i - 1];
		if (abs(y[i] - y[i - 1]) > d) {
			puts("IMPOSSIBLE");
			return 0;
		}

		int t = max(y[i], y[i - 1]);
		d -= abs(y[i] - y[i - 1]);
		ans = max(ans, d / 2 + t);
	}

	if (x[0] != 1) ans = max(ans, y[0] + x[0] - 1);
	if (x[m - 1] != n) ans = max(ans, y[m - 1] + (n - x[m - 1] ));
	cout << ans << endl;
	
	return 0;
}