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
int n;
int lst[400010];
PII a[200010];
int m,cnt;
int pre[400010],suf[400010];
int main(){
	T=read();
	while(T--){
		n=read();cnt=0;
		for(int i=1;i<=n;++i) a[i].fi=read(),a[i].se=read();
		for(int i=1;i<=n;++i){
			lst[++cnt]=a[i].fi,lst[++cnt]=a[i].se;
		}
		sort(lst+1,lst+cnt+1);
		m=unique(lst+1,lst+cnt+1)-lst-1;
		for(int i=1;i<=cnt+1;++i) pre[i]=suf[i]=0;
		int ans=n;
		for(int i=1;i<=n;++i){
			int x=lower_bound(lst+1,lst+m+1,a[i].fi)-lst; 
			int y=lower_bound(lst+1,lst+m+1,a[i].se)-lst;
			++pre[y],++suf[x];
		}
		for(int i=1;i<=m;++i) pre[i]+=pre[i-1];
		for(int i=m-1;i>=1;--i) suf[i]+=suf[i+1];
		for(int i=1;i<=n;++i){
			int x=lower_bound(lst+1,lst+m+1,a[i].fi)-lst; 
			int y=lower_bound(lst+1,lst+m+1,a[i].se)-lst;
			ans=min(ans,pre[x-1]+suf[y+1]);
		}
		printf("%d\n",ans);
	}
}