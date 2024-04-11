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
using namespace std;
typedef pair<int,int> pt;

int n, m, k, e[111][111];
int d[111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &e[i][j]);
	int ans = 1e9;
	if (m > k) {
		for (int s = 0; s < m; s++) {
			int t = 0;
			for (int ss = 0; ss < m; ss++) if (ss != s) {
				int q1 = 0, q2 = 0;
				for (int i = 0; i < n; i++) if (e[i][s] == e[i][ss]) q1++; else q2++;
				t += min(q1, q2);
			}
			ans = min(ans, t);
		}
	} else {
		for (int o = 0; o < pw(m); o++) {
			for (int i = 0; i < m; i++) if (o & pw(i)) d[i] = 1; else d[i] = 0;
			int t = 0;
			for (int i = 0; i < n; i++) {
				int q1 = 0, q2 = 0;
				for (int j = 0; j < m; j++) if (d[j] == e[i][j]) q1++; else q2++;
				t += min(q1, q2);
			}
			ans = min(ans, t);
		}
	}
	if (ans > k) ans = -1;
	cout << ans << endl;

	return 0;
}