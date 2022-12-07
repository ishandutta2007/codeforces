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

int n, m, s, e, a[N], b[N], last[N];
int f[N], prev[N];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m >> s >> e;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	for (int i = 0; i < n; i++) prev[i] = -1;
	int ans = 0;
	for (int k = 1; k <= 306; k++) {
		for (int i = 0; i <= 100000; i++) last[i] = m;
		int u = m;
		int x = m;
		if (k == 1) x = 0;
		for (int i = 0; i < n; i++) {
			while (u > x) {
				u--;
				last[b[u]] = u;
			}
			if (last[a[i]] != m) f[i] = last[a[i]]; else f[i] = -1;
			if (prev[i] != -1) x = min(x, prev[i] + 1);
		}
		for (int i = 0; i < n; i++) if (f[i] != -1) {
			int used = k * e + (i + 1) + (f[i] + 1);
			if (used <= s) ans = k;
		}
		for (int i = 0; i < n; i++) prev[i] = f[i];
	}
	cout << ans << endl;
	return 0;
}