#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
#include<vector>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)((x).size()))
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double DB;
const DB pi=acos(-1.0);
const int N=1005;
int P;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
inline void add(int &a,int b){a+=b;if(a>=P)a-=P;}
inline void dec(int &a,int b){a-=b;if(a<0)a+=P;}
int n,d;
int fac[N],inv[N];
int f[N][11];
int ji(int a,int b){
	int res=1;
	rep(i,0,b-1)res=res*1ll*(a+i)%P;
	return res;
}
int main(){
	scanf("%d%d%d",&n,&d,&P);
	if(n<=2){
		printf("1");
		return 0;
	}
	fac[0]=1;
	rep(i,1,n)fac[i]=fac[i-1]*1ll*i%P;
	inv[n]=Pow(fac[n],P-2);
	per(i,n-1,0)inv[i]=inv[i+1]*1ll*(i+1)%P;
	rep(k,0,d)f[1+k][k]=1;
	rep(i,1,(n-1)/2){
		int way=f[i][d-1];
		per(j,n,1)rep(k,0,d-1)if(f[j][k]){
			int rest=n-j;
			int dd=way;
			rep(use,1,rest/i){
				if(k+use>d)break;
				add(f[j+use*i][k+use],(f[j][k]*1ll*dd%P)*1ll*inv[use]%P);
				dd=dd*1ll*(way+use)%P;
			}
		}
	}
	if(n%2==0){
		int ans=f[n/2][d-1];
		add(ans,(f[n/2][d-1]*1ll*(f[n/2][d-1]-1)/2)%P);
		add(ans,f[n][d]);
		printf("%d\n",ans);
	}
	else{
		printf("%d\n",f[n][d]);
	}
	return 0;
}