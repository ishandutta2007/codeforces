#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MN 5005
#define Mod 1000000007
const int inv2=(Mod+1)/2;
int ksm(int a,int x){
	int ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
int n,k,S[MN][MN];
signed main(){
	scanf("%lld%lld",&n,&k);
	S[0][0]=1;
	for(int i=1;i<=k;++i)
		for(int j=1;j<=i;++j)
			S[i][j]=(S[i-1][j-1]+S[i-1][j]*j)%Mod;
	int ans=0,buf=ksm(2,n);;
	for(int i=0;i<=k;++i){
		ans=(ans+S[k][i]*buf)%Mod;
		buf=buf*(n-i)%Mod*inv2%Mod;
	}
	printf("%lld\n",ans);
	return 0;
}