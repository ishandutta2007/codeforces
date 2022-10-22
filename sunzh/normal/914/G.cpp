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
int s[1000010];
int f[1000010];
int F1[1<<17],F2[1<<17],F17[1<<17];
int cnt[1<<17];
int c1[1<<17],c2[1<<17];
const int mod=1e9+7;
void FWTxor(int *s,int f){
	for(int l=1;l<(1<<17);l<<=1){
		for(int j=0;j<(1<<17);j+=(l<<1)){
			for(int k=0;k<l;++k){
				int s1=s[j+k],s2=s[j+k+l];
				s[j+k]=(s1+s2)%mod;
				s[j+k+l]=(s1-s2+mod)%mod;
				if(f==-1) s[j+k]=1ll*s[j+k]*(mod+1>>1)%mod,s[j+k+l]=1ll*s[j+k+l]*(mod+1>>1)%mod;
			}
		}
	}
}
void FWTand(int *s,int f){
	for(int l=1;l<(1<<17);l<<=1){
		for(int j=0;j<(1<<17);j+=(l<<1)){
			for(int k=0;k<l;++k){
				int s1=s[j+k],s2=s[j+k+l];
				s[j+k]=(s1+1ll*f*s2+mod)%mod;
			}
		}
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) s[i]=read(),++cnt[s[i]];
	f[0]=0,f[1]=1;
	for(int i=2;i<(1<<17);++i) f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=0;i<(1<<17);++i){
		if(i!=0) (c1[i]+=2ll*cnt[0]*cnt[i]%mod)%=mod;
		else (c1[i]+=1ll*cnt[0]*(cnt[0]-1)%mod)%=mod;
		for(int j=(i-1)&i;j;j=(j-1)&i){
			(c1[i]+=1ll*cnt[j]*cnt[i^j]%mod)%=mod;
		}
		// printf("i:%d,c1:%d\n",i,c1[i]);
	}
	for(int i=0;i<(1<<17);++i){
		c2[i]=cnt[i];
	}
	FWTxor(c2,1);
	for(int i=0;i<(1<<17);++i) c2[i]=1ll*c2[i]*c2[i]%mod;
	FWTxor(c2,-1);
	for(int i=0;i<(1<<17);++i){
		// printf("i:%d,%d %d %d\n",i,c1[i],cnt[i],c2[i]);
		F1[i]=1ll*c1[i]*f[i]%mod;
		F2[i]=1ll*cnt[i]*f[i]%mod;
		F17[i]=1ll*c2[i]*f[i]%mod;
	}
	FWTand(F1,1);FWTand(F2,1);FWTand(F17,1);
	for(int i=0;i<(1<<17);++i) F1[i]=1ll*F1[i]*F2[i]%mod*F17[i]%mod;
	FWTand(F1,-1);
	int ans=0;
	for(int i=0;i<17;++i) (ans+=F1[1<<i])%=mod;
	printf("%d\n",ans);
}