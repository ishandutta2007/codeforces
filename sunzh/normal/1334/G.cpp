#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<ctime>
#include<random>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int x,len;
int R[800010];
const int mod=998244353;
int qpow(int x,int k=mod-2){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;k>>=1;
	}
	return res;
}
void NTT(int s[],int f){
	for(int i=0;i<x;++i) if(i<R[i]) swap(s[i],s[R[i]]);
	for(int l=1;l<x;l<<=1){
		int w;
		if(f==1) w=qpow(3,(mod-1)/(l<<1));
		else w=qpow(qpow(3),(mod-1)/(l<<1));
		for(int j=0;j<x;j+=(l<<1)){
			int sum=1;
			for(int k=0;k<l;++k){
				int a1=s[j+k],a2=1ll*sum*s[j+k+l]%mod;
				s[j+k]=(a1+a2)%mod;s[j+k+l]=(a1-a2+mod)%mod;
				sum=1ll*sum*w%mod;
			}
		} 
	}
	if(f==-1){
		int t=qpow(x);
		for(int i=0;i<x;++i) s[i]=1ll*s[i]*t%mod;
	}
}
mt19937 rnd(time(NULL));
int hsh[27],p[27];
char s[200010],t[200010];
int n,m;
int a[800010],b[800010],c[800010];
int pre[200010];
int ans[200010];
int main(){
	for(int i=1;i<=26;++i) p[i]=read(),hsh[i]=rnd()%mod;
	scanf("%s",s);scanf("%s",t);
	n=strlen(s)-1,m=strlen(t)-1;
	int sum=0;
	reverse(s,s+n+1);
	for(int i=0;i<=n;++i){
		b[i]=(hsh[s[i]-'a'+1]+hsh[p[s[i]-'a'+1]])%mod;
//		printf("b[%d]:%d\n",i,b[i]);
		(sum+=1ll*hsh[s[i]-'a'+1]*hsh[p[s[i]-'a'+1]]%mod)%=mod;
	}
	for(int i=0;i<=m;++i){
		a[i]=hsh[t[i]-'a'+1];
//		printf("a[%d]=%d\n",i,a[i]);
		pre[i]=1ll*a[i]*a[i]%mod;
	}
	x=1,len=0;
	for(int i=1;i<=m;++i) pre[i]=(pre[i-1]+pre[i])%mod;
	while(x<=n+m) x<<=1,++len;
	for(int i=0;i<x;++i) R[i]=(R[i>>1]>>1)|((i&1)<<len-1);
	NTT(a,1);NTT(b,1);
	for(int i=0;i<x;++i) c[i]=1ll*a[i]*b[i]%mod;
	NTT(c,-1);
	for(int i=n;i<=m;++i){
		int s=(sum-c[i]+mod)%mod;
		s=(s+pre[i]-(i==n?0:pre[i-n-1]))%mod;
		printf("%d",(s+mod)%mod==0);
	}
	printf("\n");
}