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

int n,m,k,e[111111],x,y,s,t,l,r,c,cc,yy[555555],pp[555555],xx[555555],f[111111],rr[111111],q1,q2,kk,p[111111],ll;
int qx[444444],qc[444444],ql[444444];


int find(int x){
	int y=x;
	while (x!=p[x])x=p[x];
	while (x!=y){
		int t=p[y];
		p[y]=x;
		y=x;
	}
	return x;
}


void add(int x,int cc,int l){
	if (f[x]){
		if (rr[x]+l<=c)p[find(cc)]=find(f[x]-1);
		return;
	}
	rr[x]=l;
	f[x]=cc+1;
	qx[q1]=x;
	qc[q1]=cc;
	ql[q1++]=l;
}


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m >> k;
	for (int i=0;i<k;i++)cin >> e[i],e[i]--;
	for (int i=0;i<m;i++){
		cin >> x >> y;
		x--;
		y--;
		yy[++kk]=y;
		pp[kk]=xx[x];
		xx[x]=kk;
		yy[++kk]=x;
		pp[kk]=xx[y];
		xx[y]=kk;
	}
	cin >> s >> t;
	e[k++]=t-1;
	l=1;
	r=n+5;
	while (l<r){
		c=(l+r)/2;
		for (int i=0;i<n;i++)p[i]=i;
		m0(f);
		q1=q2=0;
		for (int i=0;i<k;i++)add(e[i],e[i],0);
		while (q1!=q2){
			x=qx[q2];
			cc=qc[q2];
			ll=ql[q2++];
			for (int w=xx[x];w;w=pp[w])add(yy[w],cc,ll+1);
		}
		if (find(s-1)==find(t-1))r=c;else l=c+1;
	}
	if (l==n+5)puts("-1");else CC(l);
	return 0;
}