#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
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
int n;
int a,b;
const int mod=998244353;
struct poly{
	int len;
	std::vector<int>vec;
	poly(){
		vec.assign(5010,0);
	}
}ans[1010];
int qpow(int x,int k=mod-2){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1 ;
	}
	return res;
}
int x,len;
int R[40010];
void NTT(std::vector<int>&s,int f){
	for(int i=0;i<x;++i) if(i<R[i]) std::swap(s[i],s[R[i]]);
	for(int l=1;l<x;l<<=1){
		int w;
		if(f==1) w=qpow(3,(mod-1)/(l<<1));
		else w=qpow(qpow(3,mod-2),(mod-1)/(l<<1));
		for(int j=0;j<x;j+=(l<<1)){
			int sum=1;
			for(int k=0;k<l;++k){
				int a1=s[j+k],a2=1ll*sum*s[j+l+k]%mod;
				s[j+k]=(a1+a2)%mod,s[j+l+k]=(a1-a2+mod)%mod;
				sum=1ll*sum*w%mod;
			}
		}
	}
	if(f==-1){
		int t=qpow(x);
		for(int i=0;i<x;++i) s[i]=1ll*s[i]*t%mod;
	}
}
poly polymul(poly a,poly b){
	x=1,len=0;
	while(x<=a.len+b.len) ++len,x<<=1;
	for(int i=0;i<x;++i) R[i]=(R[i>>1]>>1)|((i&1)<<len-1);
	std::vector<int>va,vb;
	va.assign(x+1,0);vb.assign(x+1,0);
	for(int i=0;i<=a.len;++i) va[i]=a.vec[i];
	for(int i=0;i<=b.len;++i) vb[i]=b.vec[i];
//	printf("X:%d\n",x);
	NTT(va,1);NTT(vb,1);
	for(int i=0;i<x;++i) va[i]=1ll*va[i]*vb[i]%mod;
	NTT(va,-1);
//	printf("NTTfinish:\n");
	poly c;c.len=a.len+b.len;
	c.vec.assign(c.len+1,0);
	for(int i=0;i<=c.len;++i) c.vec[i]=va[i];
	return c;
}
int fac[200010],ifac[200010];
int C(int x,int y){
	if(x<y||y<0) return 0; 
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int main(){
	n=read();
	fac[0]=1;
	for(int i=1;i<=200000;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[200000]=qpow(fac[200000]);
	for(int i=199999;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	ans[0].vec[0]=1;
	for(int i=1;i<=n;++i){
		a=read(),b=read();
		poly trans;
		trans.vec.resize(a+ans[i-1].len-b+ans[i-1].len+10);
		int cnt=0;
		for(int j=b-ans[i-1].len;j<=a+ans[i-1].len;++j) trans.vec[cnt++]=C(a+b,j);
		trans.len=cnt-1;
		trans=polymul(ans[i-1],trans);
		for(int j=0;j<=ans[i-1].len+a-b;++j) ans[i].vec[j]=trans.vec[ans[i-1].len+j];
		ans[i].len=ans[i-1].len+a-b;
//		printf("%d:",ans[i].len);
//		for(int j=0;j<=ans[i].len;++j) printf("%d ",ans[i].vec[j]);
//		printf("\n");
	}
	int sum=0;
	for(int i=0;i<=ans[n].len;++i) (sum+=ans[n].vec[i])%=mod;
	printf("%d\n",sum);
}