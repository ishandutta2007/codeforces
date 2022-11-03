#include<bits/stdc++.h>
using namespace std;

const int M=1000000007;
char s[1005];
int n,k,a[1005],c[1005][1005];
int C(int x,int y){
	if(x<0||y<0||x<y)return 0;
	return c[x][y];
}
long long calc(int m){
	int c1=n,c2=m;
	long long ans=0;
	for(int i=0;i<n;i++){
		c1--;
		if(s[i]=='1'){
			ans=(ans+C(c1,c2))%M;
			c2--;
		}
	}
	if(!c2)ans++;
	return ans;
}
int main(){
	scanf("%s",s);scanf("%d",&k);n=strlen(s);
	if(k==0){
		printf("1\n");
		return 0;
	}
	a[1]=0;
	for(int i=2;i<=1000;i++){
		int j=i,k=0;for(;j;j>>=1)k+=j&1;
		a[i]=a[k]+1;
	}
	for(int i=0;i<=1000;i++){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%M;
	}
	long long ans=0;
	for(int i=1;i<=n;i++)if(a[i]==k-1)ans=(ans+calc(i))%M;
	if(k==1)ans=(ans-1+M)%M;
	printf("%I64d\n",ans);
	return 0;
}