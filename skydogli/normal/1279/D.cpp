#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,T,m,a[1000005],k,x,ok[1000005];
vector<int>gi[1000005];
#define Mod 998244353
LL ksm(LL a,LL x){
	LL ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		x>>=1;
		w=w*w%Mod;
	}
	return ans;
}
int main(){
		scanf("%d",&n);
		LL buf=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&k);
			for(int j=1;j<=k;++j){
				scanf("%d",&x);
				gi[i].push_back(x);
				ok[x]++;
			}
		}
		LL invn=ksm(n,Mod-2);
		LL ans=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<gi[i].size();++j){
				ans+=(LL)ksm((int)gi[i].size(),Mod-2)*invn%Mod*ok[gi[i][j]]%Mod*invn%Mod;
			}
		}
	
		printf("%I64d\n",ans%Mod);
	return 0;
}