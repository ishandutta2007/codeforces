#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

long long x[10000],y[10000],X[10000],Y[10000],r[10000];
int n,m,k,u[10000],yy[111111],pp[111111],xx[111111],f[111111],p[111111],ans[111111],a,b,kk=0,dd[111111];
vector<int> o[111111],oo[111111];

int find(int x){
	int y=x;
	while (p[x]!=x)x=p[x];
	while (x!=y){
		int t=p[y];
		p[y]=x;
		y=t;
	}
	return x;
}

void rec(int x,int d){
	f[x]=1;
	dd[x]=d;
	for (int i=0;i<o[x].size();i++)if (f[o[x][i]]){
		int t=find(o[x][i]);
		ans[oo[x][i]]=d+dd[o[x][i]]-2*dd[t];
	}
	for (int w=xx[x];w;w=pp[w])if (!f[yy[w]]){
		rec(yy[w],d+1);
		p[yy[w]]=x;
	}
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=0;i<n;i++)scanf("%I64d%I64d",&x[i],&y[i]);
	for (int i=0;i<m;i++)scanf("%I64d%I64d%I64d",&r[i],&X[i],&Y[i]);
	memset(xx,0,sizeof(xx));
	memset(f,0,sizeof(f));
	for (int i=0;i<n;i++){
		int s=2000000000;
		u[i]=m;
		for (int j=0;j<m;j++)if ((x[i]-X[j])*(x[i]-X[j])+(y[i]-Y[j])*(y[i]-Y[j])<r[j]*r[j]&&r[j]<s){
			s=r[j];
			u[i]=j;
		}
	}
	for (int i=0;i<m;i++){
		int s=2000000000,l=m;
		for (int j=0;j<m;j++)if (r[j]>r[i]&&(X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j])<r[j]*r[j]&&r[j]<s){
			s=r[j];
			l=j;
		}
		yy[++kk]=i;
		pp[kk]=xx[l];
		xx[l]=kk;
	}
	for (int i=0;i<=m;i++)p[i]=i;
	for (int i=0;i<k;i++){
		scanf("%d%d",&a,&b);
		a=u[a-1];
		b=u[b-1];
		o[a].push_back(b);
		oo[a].push_back(i);
		o[b].push_back(a);
		oo[b].push_back(i);
	}
	rec(m,0);
	for (int i=0;i<k;i++)printf("%d\n",ans[i]);
	return 0;
}