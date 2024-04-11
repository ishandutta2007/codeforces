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

int n, m;
vector<int> v[N];
pt q[N];
int f[N];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> q[i].F, q[i].S = i;
	sort(q, q + n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	for (int i = 0; i < n; i++) f[i] = -1;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int x = q[i].S;
		for (int j = 0; j < v[x].size(); j++) if (f[v[x][j]] != -1) ans += f[v[x][j]];
		f[x] = q[i].F;
	}
	cout << ans << endl;
	return 0;
}