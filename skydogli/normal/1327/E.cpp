#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define LL long long
#define mp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
inline void chkmax(int &a,int b){if(a<b)a=b;}
inline void chkmin(int &a,int b){if(a>b)a=b;}
inline int read(){
	   int a=0,fh=1;char c=getchar();
	   while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	   while('0'<=c&&c<='9'){
		   a=a*10+c-48;
		   c=getchar();
	   }
	   return a*fh;
}
#define int long long
vector<int>edg[MN];
int dis(int a,int b,int x,int y){
	return abs(a-x)+abs(b-y);
}
int n,m,k,x[MN],y[MN],u[MN],v[MN];
#define Mod 998244353
LL ans[MN],pw[MN];
signed main(){
	n=read();
	int tmp=0,del=0;
	pw[0]=1;for(int i=1;i<=n;++i)pw[i]=pw[i-1]*10%Mod;
	for(int i=n;i;--i){
		ans[i]+=(n-i+1)*pw[n-i+1]%Mod;
		ans[i]=(ans[i]-del+Mod)%Mod;
		(tmp+=ans[i])%=Mod;
		(del+=tmp+ans[i])%=Mod;
	}
	for(int i=1;i<=n;++i)printf("%lld ",ans[i]);
	return 0;
}