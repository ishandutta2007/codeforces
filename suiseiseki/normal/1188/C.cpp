#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 1000
#define Mod 998244353
#define ll long long
void add(int &a,int b){
	a+=b;
	if(a>=Mod){
		a-=Mod;
	}
}
void sub(int &a,int b){
	a-=b;
	if(a<0){
		a+=Mod;
	}
}
int n,k,a[Maxn<<1|5];
int dp[Maxn<<1|5][Maxn<<1|5];
int sum[Maxn<<1|5];
int way[100005];
int calc(int d){
	int ans=0;
	for(int i=0;i<=k;i++){
		for(int j=0;j<=n;j++){
			dp[i][j]=0;
		}
	}
	dp[0][0]=1;
	int p;
	for(int i=0;i<k;i++){
		sum[0]=dp[i][0];
		for(int j=1;j<=n;j++){
			sum[j]=(sum[j-1]+dp[i][j])%Mod;
		}
		p=1;
		for(int j=1;j<=n;j++){
			while(a[j]-a[p]>=d){
				p++;
			}
			dp[i+1][j]=sum[p-1];
		}
	}
	for(int j=k;j<=n;j++){
		add(ans,dp[k][j]);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int dif=a[n]-a[1];
	int ans=0;
	for(int i=1;i*(k-1)<=dif;i++){
		way[i]=calc(i);
	}
	for(int i=1;i*(k-1)<=dif;i++){
		sub(way[i],way[i+1]);
		add(ans,(ll)i*way[i]%Mod);
	}
	printf("%d\n",ans);
	return 0;
}