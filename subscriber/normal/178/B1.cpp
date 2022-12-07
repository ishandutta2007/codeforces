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

int n,m,a,b,ms[2222][2222],f[2222],A[2222],B[2222],ans[2222],k,u;
vector<int>v[2222];

void rec(int x,int o){
	if (f[x])return;
	f[x]=o;
	for (int i=0;i<v[x].size();i++)if (ms[x][v[x][i]])rec(v[x][i],o);
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
		ms[a][b]=ms[b][a]=1;
	}
	cin >> k;
	for (int i=0;i<k;i++)cin >> A[i] >> B[i];
	for (int x=0;x<n;x++)for (int y=0;y<x;y++)if (ms[x][y]){
		ms[x][y]=ms[y][x]=0;
		m0(f);
		u=0;
		for (int i=0;i<n;i++)if (!f[i])u++,rec(i,u);
		for (int i=0;i<k;i++)if (f[A[i]-1]!=f[B[i]-1])ans[i]++;
		ms[x][y]=ms[y][x]=1;
	}
	for (int i=0;i<k;i++)CC(ans[i]);
	return 0;
}