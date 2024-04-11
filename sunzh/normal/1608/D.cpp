#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n;
char str[2];
int tr(char c){
	if(c=='W') return 1;else if(c=='B') return 0;else return 2;
}
const int mod=998244353;
int tag[100010][2];
int sum[2][3];
int fac[100010],ifac[100010];
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int C(int x,int y){
	// printf("x:%d,y:%d\n",x,y);
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
void chk(int &x,int k){
	if(x==2) x=k;else if(x!=k) x=-1;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		scanf("%s",str);
		tag[i][0]=tr(str[0]);
		tag[i][1]=tr(str[1]);
		sum[0][tag[i][0]]++;sum[1][tag[i][1]]++;
	}
	// printf("%d %d %d %d\n",sum[0][2],sum[1][2],sum[0][0],sum[1][1]);
	int ans=0;
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n]);
	for(int i=n-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	for(int i=0;i<=n;++i){
		if(i<sum[0][0]||i<sum[1][1]||i>sum[0][0]+sum[0][2]||i>sum[1][1]+sum[1][2]) continue ;
		(ans+=1ll*C(sum[0][2],i-sum[0][0])*C(sum[1][2],i-sum[1][1])%mod)%=mod;
	}
	int res=1;
	int pt=1,col=2;
	for(int i=1;i<=n;++i){
		if(tag[i][0]==2&&tag[i][1]==2) res=2ll*res%mod;
		else{
			if(tag[i][0]==tag[i][1]) res=0,pt=0;
			if(tag[i][0]<2) chk(col,tag[i][0]);
			if(tag[i][1]<2) chk(col,tag[i][1]^1);
		}
	}
	pt=(col<0?0:(col==2?2:1));
	printf("%d\n",(ans-res+pt+mod)%mod);
}