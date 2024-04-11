#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int P=1000000007;
const int N=5005;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
int n,k,a[N];
int f[N];
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	f[0]=1;
	rep(i,1,n){
		per(j,n,0){
			f[j]=f[j]*1ll*a[i]%P;
			if(j)f[j]=(f[j]+P-f[j-1])%P;
		}
	}
	int ans=0;
	int d=1;
	rep(i,0,min(n,k)){
		ans=(ans+d*1ll*(f[i]*1ll*Pow(n,k-i)%P))%P;
		d=d*1ll*(k-i)%P;
	}
	int gt=1;
	rep(i,1,n)gt=gt*1ll*a[i]%P;
	gt=gt*1ll*Pow(n,k)%P;
	printf("%d\n",((gt+P-ans)%P)*1ll*Pow(Pow(n,P-2),k)%P);
	return 0;
}