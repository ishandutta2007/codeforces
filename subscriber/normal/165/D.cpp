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
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n,a[555555],b[555555],f[555555],k,ans,e,x,y,h=-1,oo,o;
pt m[555555];
vector<int>g[555555],s[555555],v[555555];

void rec(int x){
	f[x]=1;
	m[x]=mp(e,g[e].size());
	g[e].pb(x);
	for (int i=0;i<v[x].size();i++)if (!f[v[x][i]])rec(v[x][i]);
}

void add(int x,int y,int v){
	y++;
	while (y<=g[x].size()){
		s[x][y]+=v;
		y=y+y-(y&(y-1));
	}
}

int find(int x,int y){
	y++;
	int r=0;
	while (y){
		r+=s[x][y];
		y&=y-1;
	}
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=1;i<n;i++){
		cin >> a[i] >>b[i];
		a[i]--;
		b[i]--;
		v[a[i]].pb(b[i]);
		v[b[i]].pb(a[i]);
	}
	for (int i=0;i<n;i++)if (v[i].size()>2)h=i;
	if (h==-1)h=0;
	m[h]=mp(-1,-1);
	f[h]=1;
	for (int i=0;i<v[h].size();i++){
		rec(v[h][i]);
		e++;
	}
	for (int i=0;i<e;i++)for (int j=0;j<=g[i].size();j++)s[i].pb(0);
	for (int i=0;i<e;i++)for (int j=0;j<g[i].size();j++)add(i,j,1);
	cin >> k;
	for (int i=0;i<k;i++){
		cin >> o;
		if (o<3){
			cin >> oo;
			x=max(m[a[oo]].F,m[b[oo]].F);
			y=max(m[a[oo]].S,m[b[oo]].S);
			if (o==1)add(x,y,-1);else add(x,y,1);
		}else{
			cin >> x >> y;
			x--;
			y--;
			ans=0;
			if (m[x].F==m[y].F){
				int z=abs(find(m[y].F,m[y].S)-find(m[x].F,m[x].S));
				if (z!=abs(m[x].S-m[y].S))ans=-1e9;else ans+=z;
			}else{
				if (x!=h&&find(m[x].F,m[x].S)!=m[x].S+1)ans=-1e9;else ans+=m[x].S+1;
				if (y!=h&&find(m[y].F,m[y].S)!=m[y].S+1)ans=-1e9;else ans+=m[y].S+1;
			}
			if (ans<0)puts("-1");else CC(ans);
		}
	}
	return 0;
}