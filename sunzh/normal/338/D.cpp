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
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m;
int k;
int a[10010],p[10010];
int exgcd(int a,int b,__int128 &x,__int128 &y){
	if(b==0){
		x=1,y=0;return a;
	}
	int t=exgcd(b,a%b,x,y);
	//b*x+(a-a/b*b)y=a*X+b*Y
	//X=y,Y=x-a/b*y
	__int128 tmp=x;
	x=y,y=tmp-(a/b)*y;
	return t;
}
int excrt(){
	__int128 ans=a[1],M=p[1];
	for(int i=2;i<=k;++i){
		__int128 x,y;
		int gcd=exgcd(M,p[i],x,y);
		int t=(a[i]-ans%p[i]+p[i])%p[i];
		if(t%gcd!=0) return -1;
		x=(x*t/gcd)%p[i];
		ans=ans+x*M;M=M*p[i]/gcd;
		ans=(ans%M+M)%M;
	}
	if(ans==0) ans=M;
	if(ans>m) return -1;return ans;
}
void fail(){
	printf("NO\n");exit(0);
}
signed main(){
	n=read(),m=read();
	k=read();for(int i=1;i<=k;++i) p[i]=read(),a[i]=(p[i]-i%p[i]+1)%p[i];
	// for(int i=1;i<=k;++i) printf("%d\n",a[i]);
	int j=excrt();
	if(j==-1){
		fail();
	}
	if(j+k-1>m) fail();
	__int128 lcm=1;
	for(int i=1;i<=k;++i){
		lcm=lcm*p[i]/__gcd((int)lcm,p[i]);
		if(lcm>n||lcm<1){
			fail();
		}
	}
	for(int i=1;i<=k;++i) if(__gcd((int)lcm,j+i-1)!=p[i]) fail();
	printf("YES\n");
}