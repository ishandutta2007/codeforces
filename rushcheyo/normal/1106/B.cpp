#include<bits/stdc++.h>

using namespace std;

set<pair<int,int>>q;

int n,m,a[100005],c[100005];

int main(){
	scanf("%d%d",&n,&m);
	long long tot=0;
	for(int i=1;i<=n;i++)scanf("%d",a+i),tot+=a[i];
	for(int i=1;i<=n;i++)scanf("%d",c+i),q.emplace(c[i],i);
	bool gg=false;
	while(m--){
		int t,d;
		scanf("%d%d",&t,&d);
		if(gg||d>tot){puts("0");gg=true;continue;}
		if(d<=a[t]){
			a[t]-=d;
			printf("%lld\n",1ll*d*c[t]);
			tot-=d;
			if(!a[t])q.erase(make_pair(c[t],t));
			continue;
		}
		long long ans=1ll*a[t]*c[t];
		tot-=a[t];d-=a[t];a[t]=0;q.erase(make_pair(c[t],t));
		while(d){
			int x=q.begin()->second;
			if(d<a[x]){
				a[x]-=d;
				tot-=d;
				ans+=1ll*d*c[x];
				break;
			}else{
				ans+=1ll*a[x]*c[x];tot-=a[x];d-=a[x];a[x]=0;q.erase(make_pair(c[x],x));
			}
		}
		printf("%lld\n",ans);
	}
}