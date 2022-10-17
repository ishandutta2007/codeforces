#include <cstdio>
#define Mod 1000000007
int sum[100005];
int a[100005];
int ksm(int x,int y){
	int ans=1;
	while(y){
		if(y&1){
			ans=(int)((long long)ans*x%Mod);
		}
		y>>=1;
		x=(int)((long long)x*x%Mod);
	}
	return ans;
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
		sum[i]+=sum[i-1]+a[i];
	}
	int l,r;
	int ans;
	while(q--){
		scanf("%d%d",&l,&r);
		ans=ksm(2,sum[r]-sum[l-1])-1;
		if(ans==-1){
			ans+=Mod;
		}
		ans=(int)(((long long)ans+((long long)ans*((ksm(2,r-l+1+sum[l-1]-sum[r])-1+Mod)%Mod))%Mod)%Mod);
		printf("%d\n",ans);
	}
	return 0;
}
/*
ans=pow(2ll,sum[r]-sum[l-1],inf)-1;
ans=(ans+(ans*(pow(2ll,r-l+1+sum[l-1]-sum[r],inf)-1))%inf)%inf;
*/