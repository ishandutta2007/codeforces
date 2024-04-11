#include<bits/stdc++.h>
const int N=5003;
using namespace std;
typedef long long ll;
const ll inf=1e17;
int n,S,T,x[N],a[N],b[N],c[N],d[N],ro;
ll f[N],g[N];
inline void rd(int*a){
	for(int i=1;i<=n;i++)
	scanf("%d",a+i);
}
int main(){
	scanf("%d%d%d",&n,&S,&T);
	rd(x),rd(a),rd(b),rd(c),rd(d);
	for(int i=1;i<=n;i++)
	c[i]+=x[i],b[i]-=x[i],
	a[i]+=x[i],d[i]-=x[i],f[i]=inf;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++)
		g[j]=f[j],f[j]=inf;
		for(int j=0;j<i;j++)
		if(g[j]<inf){
			ro=j-(T<i)+(S<i);
			if(j==0&&ro==0&&i>1)continue;
			if(i==S){
				if(j)f[j-1]=min(f[j-1],g[j]+c[i]);
				f[j]=min(f[j],g[j]+d[i]);
			}
			else if(i==T){
				f[j+1]=min(f[j+1],g[j]+b[i]);
				if(ro)f[j]=min(f[j],g[j]+a[i]);
			}
			else{
				if(j&&ro)f[j-1]=min(f[j-1],g[j]+a[i]+c[i]);
				if(j)f[j]=min(f[j],g[j]+b[i]+c[i]);
				if(ro)f[j]=min(f[j],g[j]+d[i]+a[i]);
				f[j+1]=min(f[j+1],g[j]+b[i]+d[i]);
			}
		}
	}
	printf("%lld",f[0]);
}