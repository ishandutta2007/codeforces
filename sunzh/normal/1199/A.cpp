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
int n,x,y;
int a[100010];
int main(){
	n=read(),x=read(),y=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i){
		int minn=0x3f3f3f3f;
		for(int j=max(1,i-x);j<=min(n,i+y);++j){
			minn=min(minn,a[j]);
		}
		if(minn==a[i]){
			printf("%d\n",i);return 0;
		}
	}
}