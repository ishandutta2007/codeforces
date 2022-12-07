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
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, m;
int x[N], y[N], q[N];
int s[N], ss[N];
int ans[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x[i], &y[i], &q[i]);
		x[i]--;
		y[i]--;
	}

	for (int t = 0; t < 30; t++) {
	        for (int i = 0; i <= n; i++) s[i] = 0;

	        for (int i = 0; i < m; i++) if (q[i] & pw(t)) {
	        	s[x[i]]++;
	        	s[y[i] + 1]--;
	        }

	        for (int i = 1; i < n; i++) s[i] += s[i - 1];

	        for (int i = 0; i < n; i++) if (s[i] > 0) s[i] = 1;

	        for (int i = 0; i < n; i++) ans[i] += pw(t) * s[i];

	        ss[0] = 0;
	        for (int i = 0; i < n; i++) ss[i + 1] = ss[i] + s[i];

	        for (int i = 0; i < m; i++) if ((q[i] & pw(t)) == 0) {
	        	if (ss[y[i] + 1] - ss[x[i]] == (y[i] - x[i] + 1)) {
		        	puts("NO");
		        	return 0;
	        	}
	        }
	}
	puts("YES");
	for (int i = 0; i < n; i++) {
		printf("%d", ans[i]);
		if (i == n - 1) puts(""); else putchar(' ');
	}
	return 0;
}