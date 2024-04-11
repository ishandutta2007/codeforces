#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n,m,k;
void exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1,y=0;return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int pos[1000010];
int a[500010],b[500010];
int x,y;
int w1[500010];
int gcd;
int calc(int det){
	return (x%m+m)%m*(det/gcd)%m;
}
bool check(int mid){
	int res=0;
	for(int i=1;i<=n;++i) if(i<=mid) res+=((mid-i)/n+1)-(w1[i]<=mid);
	return res>=k;
}
signed main(){
	n=read(),m=read(),k=read();
	exgcd(n,m,x,y);
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=m;++i) b[i]=read();
	gcd=__gcd(n,m);
	int lcm=n*m/gcd;
	for(int i=1;i<=m;++i) pos[b[i]]=i;
	int trn=lcm;
	for(int i=1;i<=n;++i){
		int p=pos[a[i]];
		if(p&&p%gcd==i%gcd){
			--trn;w1[i]=(n*calc(((p-i)%m+m)%m)+i-1)%lcm+1;
		}
		else w1[i]=1e18;
	}
	int ans=k/trn*lcm;
//	printf("%d\n",trn);
	k%=trn;
	if(k==0){
		k=trn,ans-=lcm;
	}
	int l=0,r=lcm,res=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans+res);
}