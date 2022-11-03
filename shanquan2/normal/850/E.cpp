#include<bits/stdc++.h>
using namespace std;

const int M=1000000007,inv2=(M+1)/2;
int n,a[1<<20],c[1<<20];
char s[2000005];
int main(){
	scanf("%d",&n);
	c[0]=1;for(int i=0;i<n;i++)c[0]*=2;
	for(int i=1;i<1<<n;i++)c[i]=c[i^(i&-i)]>>1;
	scanf("%s",s);
	for(int i=0;i<1<<n;i++)a[i]=s[i]-'0';
	for(int i=0;i<n;i++)for(int j=0;j<1<<n;j++)if(j>>i&1){
		int x=a[j^1<<i],y=a[j];
		a[j]=(x-y+M)%M,a[j^1<<i]=(x+y)%M;
	}
	for(int i=0;i<1<<n;i++)a[i]=1ll*a[i]*a[i]%M;
	for(int i=0;i<n;i++)for(int j=0;j<1<<n;j++)if(j>>i&1){
		int x=a[j^1<<i],y=a[j];
		a[j]=1ll*(x-y+M)*inv2%M,a[j^1<<i]=1ll*(x+y)*inv2%M;
	}
	int ans=0;
	for(int i=0;i<1<<n;i++)ans=(ans+1ll*c[i]*a[i])%M;
	ans=3ll*ans%M;
	printf("%d\n",ans);
	return 0;
}