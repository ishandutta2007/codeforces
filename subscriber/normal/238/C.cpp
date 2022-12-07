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

int n,a,b,ans=1e9+1,w[3333][3];
vector<int>v[3333],c[3333];

int rec(int x,int p,int t){
	if (w[x][t])return w[x][t]-1;
	int s=0,r=1e9+1;
	for (int i=0;i<v[x].size();i++)if (v[x][i]!=p)s+=rec(v[x][i],x,0)+c[x][i];
	if (t==0)r=s;else
	if (t==1){
		for (int i=0;i<v[x].size();i++)if (v[x][i]!=p){
			r=min(r,s-rec(v[x][i],x,0)+rec(v[x][i],x,1));
		}
		r=min(r,rec(x,p,2));
		
	}else{
		for (int i=0;i<v[x].size();i++)if (v[x][i]!=p){
			r=min(r,s-rec(v[x][i],x,0)-c[x][i]+rec(v[x][i],x,2)+(1-c[x][i]));
		}
		r=min(r,rec(x,p,0));
	}
	return (w[x][t]=r+1)-1;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n-1;i++){
		cin >> a >> b;
		a--;
		b--;
		v[a].pb(b);
		c[a].pb(0);
		v[b].pb(a);
		c[b].pb(1);
	}
	for (int i=0;i<n;i++){
		m0(w);
		ans=min(ans,rec(i,-1,0));
		ans=min(ans,rec(i,-1,1));
		ans=min(ans,rec(i,-1,2));
	}
	CC(ans);
	return 0;
}