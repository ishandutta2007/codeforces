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
int T;
int n,k;
struct node{
	int x,y;
}a[110];
int f[110][110];
int main(){
	T=read();
	while(T--){
		memset(f,0x3f,sizeof(f));
		n=read(),k=read();
		for(int i=1;i<=n;++i) a[i].x=read(),a[i].y=read();
		auto getdis=[&](int x,int y){
			return abs(a[x].x-a[y].x)+abs(a[x].y-a[y].y);
		};
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(getdis(i,j)<=k) f[i][j]=1;
			}
			f[i][i]=0;
		}
		int ans=0x3f3f3f3f;
		for(int i=1;i<=n;++i){
			int res=0;
			for(int j=1;j<=n;++j){
				res=max(res,f[i][j]);
			}
			ans=min(ans,res);
		}
		if(ans<=n) printf("1\n");
		else printf("-1\n");
	}
}