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

int n,x,y,st,ans[111111],s[111111];
vector<int>vv[111111];
vector<pair<pt,int> >v;
pair<double,int>o[2222][2222];
pair<pt,int>q[111111];

void rec(int x,int p){
	s[x]=1;
	for (int i=0;i<vv[x].size();i++)if (vv[x][i]!=p){
		rec(vv[x][i],x);
		s[x]+=s[vv[x][i]];
	}
}

void gg(int x,int p,vector<pair<pt,int> >v){	
	sort(v.begin(),v.end());
	ans[v[0].S]=x;
	st++;
	for (int i=1;i<v.size();i++)o[st][i]=mp(atan2(v[i].F.S-v[0].F.S,v[i].F.F-v[0].F.F),i);
	sort(o[st]+1,o[st]+v.size());
	int u=1;
	for (int i=0;i<vv[x].size();i++)if (vv[x][i]!=p){
		vector<pair<pt,int> >e;
		for (int j=0;j<s[vv[x][i]];j++)e.pb(v[o[st][u].S]),u++;
		gg(vv[x][i],x,e);
	}
	st--;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=1;i<n;i++){
		cin >> x >> y;
		x--;
		y--;
		vv[x].pb(y);
		vv[y].pb(x);
	}
	rec(0,-1);
	for (int i=0;i<n;i++)scanf("%d%d",&q[i].F.S,&q[i].F.F);
	for (int i=0;i<n;i++)q[i].S=i;
	for (int i=0;i<n;i++)v.pb(q[i]);
	gg(0,-1,v);
	for (int i=0;i<n;i++)cout << ans[i]+1 << " ";
	return 0;
}