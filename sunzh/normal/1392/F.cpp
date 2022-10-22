#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
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
int n;
int h[1000010];
int ans[1000010];
int sum;
signed main(){
	n=read();
	for(int i=1;i<=n;++i) h[i]=read(),sum+=h[i];
	sum-=n*(n-1)>>1; 
	for(int i=1;i<=n;++i){
		ans[i]=(i-1)+sum/n;
		if(i<=sum%n) ++ans[i];
	}
	for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}