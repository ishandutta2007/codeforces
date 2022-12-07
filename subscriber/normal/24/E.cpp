#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

struct T{int x,v;} q[1000000];

int n;

long double f[1000000],c,w,l,r,g[1000000];

int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&n);
	for (int i=0;i<n;i++)scanf("%d%d",&q[i].x,&q[i].v);
	l=0;
	r=1000000011;
	while (r-l>0.000000001){
		c=(l+r)/2;
		int t=0;
		f[n]=21222222222;
		f[n]*=f[n];
		for (int i=n-1;i>=0;i--)if (q[i].v<0){
			w=q[i].x+q[i].v*c;			
			f[i]=f[i+1];
			if (w<f[i])f[i]=w;
		}else f[i]=f[i+1];
		g[0]=2122222222;
		g[0]*=-g[0];
		if (q[0].v>0)g[0]=q[0].x+q[0].v*c;
		for (int i=1;i<n;i++)if (q[i].v>0){
			w=q[i].x+q[i].v*c;			
			g[i]=g[i-1];
			if (w>g[i])g[i]=w;
		}else g[i]=g[i-1];
		for (int i=0;i<n;i++)if (f[i]<g[i])t=1;
		if (t)r=c;else l=c;
	}
	if (l>1000000001){
		puts("-1");
		return 0;
	}
	cout.precision(10);
	cout << fixed << l << endl;
	return 0;
}