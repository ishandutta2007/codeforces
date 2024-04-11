#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int P=1000000007;
const int N=110000;
inline int Pow(int a,int b){
	int c=1;for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;return c;
}
int fac[N],inv[N];
inline int C(int a,int b){
	if(b>a)return 0;
	int ans=fac[a]*1ll*inv[b]%P;
	ans=ans*1ll*inv[a-b]%P;
	return ans;
}
int n,k;char a[N];int sum[N];
inline void init(){
	fac[0]=1;rep(i,1,n)fac[i]=fac[i-1]*1ll*i%P;
	inv[n]=Pow(fac[n],P-2);
	per(i,n-1,0)inv[i]=inv[i+1]*1ll*(i+1)%P;
	
	int base=1;
	
	sum[0]=C(n-2,k-1)*1ll*1%P;
	
	rep(i,1,n){
		base=base*10ll%P;
		sum[i]=(sum[i-1]+base*1ll*C(n-2-i,k-1))%P;
		//printf("%d %d\n",i,sum[i]);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",a+1);
	init();
	int rp=0;
	rep(i,1,n){
		rp=(rp+(a[i]-'0')*1ll*sum[n-i-1])%P;
		int tmp=(a[i]-'0')*1ll*C(i-1,k)%P;
		tmp=tmp*1ll*Pow(10,n-i)%P;
		rp=(rp+tmp)%P;
		//printf("__%d\n",rp);
	}
	if(rp<0)rp+=P;
	printf("%d\n",rp);
	return 0;
}