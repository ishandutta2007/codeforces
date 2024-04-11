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

int n,m,x,y,z,k,f[111111],d[111111],l,yy[222222],pp[222222],xx[222222],kk,zz[222222];
priority_queue<pair<int,int> >Q;
set<int>w[111111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		x--;
		y--;
		yy[++kk]=y;
		zz[kk]=z;
		pp[kk]=xx[x];
		xx[x]=kk;
		yy[++kk]=x;
		zz[kk]=z;
		pp[kk]=xx[y];
		xx[y]=kk;
	}
	for (int i=0;i<n;i++){
		scanf("%d",&k);
		for (int j=0;j<k;j++){
			scanf("%d",&x);
			w[i].insert(x);
		}
	}
	m1(d);
	d[0]=0;
	Q.push(mp(0,0));
	for (int i=0;i<n;i++){
		while (Q.size()&&f[Q.top().S])Q.pop();
		if (Q.empty())break;
		x=Q.top().S;
		l=-Q.top().F;
		while (w[x].find(l)!=w[x].end())l++;
		Q.pop();
		f[x]=1;
		for (int w=xx[x];w;w=pp[w])if (l+zz[w]<d[yy[w]]){
			d[yy[w]]=l+zz[w];
			Q.push(mp(-d[yy[w]],yy[w]));
		}
	}
	if (d[n-1]>1e9+1e7)puts("-1");else CC(d[n-1]);
	return 0;
}