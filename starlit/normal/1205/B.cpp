#include<bits/stdc++.h>
const int L=130;
using namespace std;
typedef long long ll;
int n,m,cnt[L],to[L*2],hd[L*2],lk[L],
cct=1,de,q[L],h,t,dis[L],ans=L;
inline void add(int u,int v){
	to[++cct]=v,hd[cct]=lk[u],lk[u]=cct;
}
ll x,a[L];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		if(!x)continue;
		a[m++]=x;
		for(int j=0;j<62;j++)
		if(x>>j&1){
			if((++cnt[j])>2)
			return puts("3"),0;
		}
	}
	for(int i=0;i<m;i++)
	for(int j=0;j<i;j++)
	if(a[i]&a[j])add(i,j),add(j,i);
	for(de=2;de<cct;de+=2){
		h=t=0;q[t++]=to[de];
		for(int k=0;k<m;k++)
		dis[k]=0;dis[to[de]]=1;
		for(;h<t;){
			x=q[h++];
			if(x==to[de^1]){
				ans=min(ans,dis[x]);
				break;
			}
			for(int k=lk[x];k;k=hd[k])
			if((k^de)>1&&!dis[to[k]])
			dis[q[t++]=to[k]]=dis[x]+1;
		}
	}
	printf("%d",ans<L?ans:-1);
}