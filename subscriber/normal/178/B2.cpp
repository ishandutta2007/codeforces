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

int n,m,a,b,k,A[111111],B[111111],pr[21][111111],t[111111],f[111111],de[111111],g[111111],D;
vector<int>v[222222],d[222222];

void rec(int x,int p){
	D++;
	t[x]=f[x]=D;
	for (int i=0;i<v[x].size();i++)if (v[x][i]!=p){
		if (t[v[x][i]])f[x]=min(f[x],t[v[x][i]]);else{
			d[x][i]+=2;
			rec(v[x][i],x);
			int q=f[v[x][i]];
			f[x]=min(f[x],q);
			if (q>t[x])d[x][i]++;
		}
	}

}

void rc(int x,int dd){
	de[x]=dd;
	for (int i=0;i<v[x].size();i++)if (d[x][i]>1){
		pr[0][v[x][i]]=x;
		g[v[x][i]]=g[x]+d[x][i]%2;
		rc(v[x][i],dd+1);
	}	
}

int lca(int x,int y){
	for (int i=20;i>=0;i--)if (pr[i][x]!=-1&&de[pr[i][x]]>=de[y])x=pr[i][x];
	for (int i=20;i>=0;i--)if (pr[i][y]!=-1&&de[pr[i][y]]>=de[x])y=pr[i][y];
	if (x==y)return x;
	for (int i=20;i>=0;i--)if (pr[i][x]!=-1&&pr[i][x]!=pr[i][y])x=pr[i][x],y=pr[i][y];
	return pr[0][x];
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<m;i++){
		cin >> a >> b;
		a--;
		b--;
		v[a].pb(b);
		v[b].pb(a);
		d[a].pb(0);
		d[b].pb(0);
	}
	cin >> k;
	for (int i=0;i<k;i++)cin >> A[i] >> B[i],A[i]--,B[i]--;
	rec(0,-1);
	rc(0,0);
	pr[0][0]=-1;
	for (int i=1;i<20;i++)for (int j=0;j<n;j++)if (pr[i-1][j]==-1)pr[i][j]=-1;else pr[i][j]=pr[i-1][pr[i-1][j]];
	for (int i=0;i<k;i++)CC(g[A[i]]+g[B[i]]-2*g[lca(A[i],B[i])]);
	return 0;
}