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
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n,m,vv,a[333],b[333],f[333],d[333],x,y;
vector<int> v[333];
vector<pair<int,pt> >ans;
pair<int,int>q[333];

void transfer(int x,int y,int z){
	ans.pb(mp(z,mp(x,y)));
	a[x] -= z;
	a[y] += z;
}

void dai(int x,int o){
	f[x]=1;
	o -= a[x];
	for (int i=0;i<v[x].size();i++)if (!f[v[x][i]] && o > 0){
		if (!d[v[x][i]]) {
			dai(v[x][i], o);
			int t = min(a[v[x][i]], o);
			o -=t;
			transfer(v[x][i], x, t);
		} else {
			transfer(v[x][i], x, o);
			dai(v[x][i], b[v[x][i]]);
			o = 0;
			if (a[v[x][i]] < b[v[x][i]]) {
				o = b[v[x][i]] - a[v[x][i]];
				transfer(x, v[x][i], b[v[x][i]] - a[v[x][i]]);
			}
		}
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> vv >> m;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<n;i++)cin >> b[i];
	for (int i=0;i<m;i++){
		cin >> x >> y;
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	for (int i=0;i<n;i++)q[i]=mp(-b[i],i);
	sort(q,q+n);
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++)f[j]=0;
		int e = q[i].S;
		dai(e,b[e]);
		d[e] = 1;
	}
	for (int i=0;i<n;i++)if (a[i] != b[i]) {
		puts("NO");
		return 0;
	}
	cout << ans.size() << endl;
	for (int i=0;i<ans.size();i++)cout << ans[i].S.F + 1 << " " << ans[i].S.S + 1 << " " << ans[i].F << endl;
	return 0;
}