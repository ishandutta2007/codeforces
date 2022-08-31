#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int P=1000000007;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
const int N=10005;
LL n;int k;
int t;
pair<LL,int>w[105];
int f[2][60];
int inv[N];
LL work(LL b,int n){
	memset(f,0,sizeof f);
	int now=0;
	f[now][n]=1;
	rep(ii,1,k){
		rep(j,0,n)f[now^1][j]=0;
		rep(j,0,n)if(f[now][j]){
			int w=f[now][j]*1ll*inv[j+1]%P;
			rep(d,0,j)f[now^1][d]=(f[now^1][d]+w)%P;
		}
		now^=1;
	}
	int ans=0;
	rep(i,0,n)ans=(ans+Pow(b%P,i)*1ll*f[now][i])%P;
	return ans;
}
int main(){
	scanf("%lld%d",&n,&k);
	for(int x=2;x*1ll*x<=n;x++)if(n%x==0){
		int c=0;
		while(n%x==0){
			n/=x;
			c++;
		}
		w[++t]=pair<LL,int>(x,c);
	}
	if(n>1)w[++t]=pair<LL,int>(n,1);
	int ans=1;
	rep(i,1,100)inv[i]=Pow(i,P-2);
	rep(i,1,t)ans=ans*1ll*work(w[i].fi,w[i].se)%P;
	printf("%d\n",ans);
	return 0;
}