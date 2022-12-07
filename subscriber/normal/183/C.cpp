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

int n,m,x,y,kk,t,j,f[111111],yy[222222],tt[222222],xx[222222],pp[222222],d[111111];

void rec(int x,int o){
	if (f[x]<n)return;
	f[x]=o;
	for (int w=xx[x];w;w=pp[w])rec(yy[w],o+tt[w]);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<m;i++){
		cin >> x >> y;
		x--;
		y--;
		yy[++kk]=y;
		tt[kk]=1;
		pp[kk]=xx[x];
		xx[x]=kk;
		yy[++kk]=x;
		tt[kk]=-1;
		pp[kk]=xx[y];
		xx[y]=kk;		           	
	}
	m1(f);
	for (int i=0;i<n;i++)rec(i,0);
	for (int i=0;i<n;i++)for (int w=xx[i];w;w=pp[w])d[abs(f[yy[w]]-tt[w]-f[i])]++;
	for (int i=n;i;i--){
		j=t=0;
		while (j<=n){
			t+=d[j];
			j+=i;
		}
		if (t==kk){
			CC(i);
			break;
		}
	}
	return 0;
}