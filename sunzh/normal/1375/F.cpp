#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
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
int a[4],tmp[4];
signed main(){
	a[1]=read(),a[2]=read(),a[3]=read();
	printf("First\n");
	fflush(stdout);
	printf("10000000000\n");
	fflush(stdout);
	int x=read();
	if(x==0) return 0;
	a[x]+=10000000000;
	memcpy(tmp,a,sizeof(a));
	sort(a+1,a+4);
	printf("%lld\n",(a[3]<<1ll)-a[2]-a[1]);
	fflush(stdout);
	x=read();
	if(x==0) return 0;
	tmp[x]+=(a[3]<<1ll)-a[2]-a[1];
	memcpy(a,tmp,sizeof(tmp));
	sort(a+1,a+4);
	printf("%lld\n",a[3]-a[2]);
	fflush(stdout);
	return 0;
}