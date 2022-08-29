#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int P=1000000007;
const int N=1100000;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
int n;
int fac[N*2],inv[N*2];
int main(){
	scanf("%d",&n);n++;
	int ap=1;
	fac[0]=1;rep(i,1,2*n)fac[i]=fac[i-1]*1ll*i%P;
	inv[2*n]=Pow(fac[2*n],P-2);
	per(i,2*n-1,0)inv[i]=inv[i+1]*1ll*(i+1)%P;
	ap=2*fac[2*n-1]%P;
	int jj=inv[n]*1ll*inv[n-1]%P;
	ap=ap*1ll*jj%P;
	ap=(ap+P-1)%P;
	printf("%d\n",ap);
	return 0;
}