#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int P=998244353;
int a[505][505],b[505],n,k;
int main(){
	scanf("%d%d",&n,&k);
	rep(i,n)a[0][i]=a[1][i]=2;
	for(int i=2;i<=n;++i){
		rep(j,i){
			a[i][j]=2*a[i-1][j]-((i-j-1>=0)?a[i-j-1][j]:0);
			if(a[i][j]<0)a[i][j]+=P;
			if(a[i][j]>=P)a[i][j]-=P;
		}
		for(int j=i+1;j<=n;++j)a[i][j]=a[i][j-1];
	}
	//rep(i,4)rep(j,4)printf("%d %d %d\n",i,j,a[i][j]);
	rep(i,n)b[i]=(a[n][i]-a[n][i-1]+P)%P;
	int ans=0;
	rep(i,n)ans=(ans+1ll*b[i]*a[n][min((k-1)/i,n)])%P;
	printf("%lld\n",1ll*ans*((P+1)/2)%P);
}