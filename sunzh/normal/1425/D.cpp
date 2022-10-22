#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define int long long
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m,r;
int s[2010][2010];
const int N=2000;
const int mod=1e9+7;
int fac[2010],ifac[2010];
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res; 
}
inline int C(int x,int y){
//	printf("X:%d,y:%d\n",x,y);
	if(y==0) return 1;
	if(x<y) return 0;
	if(x<=0) return 0;
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int ans;
struct node{
	int x,y,b;
	bool operator <(const node &p)const{
		return x==p.x?y<p.y:x<p.x;
	}
}a[2010];
signed main(){
	n=read(),m=read(),r=read();
	for(int i=1;i<=n;++i){
		int x=read(),y=read(),b=read();
		a[i]=node{x,y,b};++s[x][y];
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			s[i][j]=s[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	sort(a+1,a+n+1);
	fac[1]=1;
	fac[0]=1;
	for(int i=2;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	for(int i=1;i<=n;++i){
		int x=a[i].x,y=a[i].y,B=a[i].b;
		int a=max(1ll,x-r),b=max(1ll,y-r);
		int c=min(N,x+r),d=min(N,y+r);
		int cnt=s[c][d]-s[a-1][d]-s[c][b-1]+s[a-1][b-1];
		(ans+=1ll*B*B%mod*(C(n,m)-C(n-cnt,m)+mod)%mod)%=mod;
	}
	for(int i=1;i<=n;++i){
		int a1=max(1ll,a[i].x-r),b1=max(1ll,a[i].y-r);
		int c1=min(N,a[i].x+r),d1=min(N,a[i].y+r);
		for(int j=i+1;j<=n;++j){
			int a2=max(1ll,a[j].x-r),b2=max(1ll,a[j].y-r);
			int c2=min(N,a[j].x+r),d2=min(N,a[j].y+r);
			int cnt1=s[c1][d1]-s[a1-1][d1]-s[c1][b1-1]+s[a1-1][b1-1];
			int cnt2=s[c2][d2]-s[a2-1][d2]-s[c2][b2-1]+s[a2-1][b2-1];
			int cnt=0;
			
			if(a2<=c1&&b2>=b1&&b2<=d1){
				cnt=s[c1][d1]-s[a2-1][d1]-s[c1][b2-1]+s[a2-1][b2-1];
			}
			if(a2<=c1&&d2>=b1&&d2<=d1){
				cnt=s[c1][d2]-s[a2-1][d2]-s[c1][b1-1]+s[a2-1][b1-1];
			}
			if(a2<=c1&&d2>=b1&&d2<=d1&&b2>=b1&&b2<=d1){
				int miy=max(b1,b2),may=min(d1,d2);;
				cnt=s[c1][may]-s[a2-1][may]-s[c1][miy-1]+s[a2-1][miy-1];
			}
			
			(ans+=2ll*a[i].b*a[j].b%mod*((C(n,m)-C(n-cnt1,m)-C(n-cnt2,m)+C(n-cnt1-cnt2+cnt,m))%mod+mod)%mod)%=mod;
		}
	} 
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}