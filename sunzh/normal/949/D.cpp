#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
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
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,d,b;
int a[100010];
long long suml[100010],sumr[100010];
int c1,c2;
int mid;
int main(){
	n=read(),d=read(),b=read();
	mid=(n+1)>>1;
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) suml[i]=suml[i-1]+a[i];
	for(int i=n;i>=0;--i) sumr[i]=sumr[i+1]+a[i];
	for(int i=1;i<=mid;++i){
		c1+=(suml[min(1ll*n,1ll*d*i+i)]-c1*b>=b);
	}
	for(int j=n;j>mid;--j){
		c2+=(sumr[max(0ll,j-1ll*(n-j+1)*d)]-c2*b>=b);
	}
	printf("%d\n",max(mid-c1,n-mid-c2));
}