#include<bits/stdc++.h>
const int N=250005;
using namespace std;
int n,M,fac[N],ans;
int main(){
	//freopen("dat.txt","r",stdin);
	//freopen("me.txt","w",stdout);
	scanf("%d%d",&n,&M);
	fac[0]=1;
	for(int i=1;i<=n;i++)
	fac[i]=1ll*fac[i-1]*i%M;
	for(int i=1;i<=n;i++)
	ans=(ans+(n-i+1ll)*(n-i+1)%M*fac[i]%M*fac[n-i])%M;
	printf("%d",ans);
}