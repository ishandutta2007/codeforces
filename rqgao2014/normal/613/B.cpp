#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
	int a,num;
}p[100005];
int n,A,a[100005],cf,cm,id,pi,res[100005];
ll m,sum[100005],ans;
inline bool cmp(node a,node b){
	return a.a>b.a;
}
inline bool cmp2(int a,int b){return a>b;}

int main(){
	scanf("%d%d%d%d%lld",&n,&A,&cf,&cm,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),p[i].a=a[i],p[i].num=i;
	sort(a+1,a+n+1,cmp2);
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int pt=n+1;ll minx;
	for(int i=n;~i;i--){
		ll t=m-((ll)i*A-sum[i]),minx=1ll<<60;
		if(t<0) continue;
		while(pt>i+1&&(ll)a[pt-1]*(n-pt+1)-(sum[n]-sum[pt-1])<=t) pt--;
		if(pt<=n) minx=a[pt]+(t-(ll)a[pt]*(n-pt+1)+(sum[n]-sum[pt-1]))/(n-pt+1);
		minx=min(minx,(ll)A);
		if(ans<(ll)i*cf+(ll)cm*minx) ans=(ll)i*cf+(ll)cm*minx,id=i,pi=pt;
	}
	cout<<ans<<endl;
	for(int i=1;i<=id;i++)
		res[p[i].num]=A;
	for(int i=id+1;i<pi;i++) res[p[i].num]=a[i];
	if(pi<=n){
		minx=min((ll)A,a[pi]+(m-((ll)id*A-sum[id])-(ll)a[pi]*(n-pi+1)+(sum[n]-sum[pi-1]))/(n-pi+1));
		for(int i=pi;i<=n;i++) res[p[i].num]=minx;
	}
	for(int i=1;i<=n;i++) printf("%d ",res[i]);
	puts("");
	return 0;
}
/*
3 5 10 1 5
1 3 1
*/