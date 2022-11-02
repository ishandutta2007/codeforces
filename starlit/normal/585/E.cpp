#include<bits/stdc++.h>
const int N=10000007,M=1000000007;
using namespace std;
int n,m,x,bin[N>>4],cnt[N],ans,
p[N>>3],mu[N],t;
bool np[N];
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d",&n);
	bin[0]=mu[1]=np[1]=1;
	for(int i=1;i<=n;i++){
		bin[i]=bin[i-1]*2%M;
		scanf("%d",&x),cnt[x]++,m=max(m,x);
	}
	for(int i=1;i<=m;i++){
		if(!np[i])p[t++]=i,mu[i]=-1;
		for(int j=0;j<t&&p[j]*i<=m;j++){
			np[i*p[j]]=1;
			if(i%p[j]==0)break;
			mu[i*p[j]]=-mu[i];
		}
		if(mu[i]){
			x=0;
			for(int j=i;j<=m;j+=i)
			x+=cnt[j];
			//cerr<<i<<":"<<x<<"/"<<mu[i]<<endl;
			if(x)
			ans=(ans+mu[i]*(2ll*x*bin[x-1]-(bin[x]-1ll)*n))%M;
		}
	}
	printf("%d",(ans+M)%M);
}