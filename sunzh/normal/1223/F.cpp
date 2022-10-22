#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<map>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define int long long
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
int Q;
int n;
int a[300010];
map<int,int>trans[300010];
int nxt[300010],f[300010];
signed main(){
	Q=read();
	while(Q--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=n;++i) nxt[i]=0;
		trans[n+1].clear();
		for(int i=n;i>=1;--i){
			trans[i].clear();
			if(trans[i+1].count(a[i])){
				nxt[i]=trans[i+1][a[i]];
				swap(trans[i],trans[nxt[i]+1]);
				if(nxt[i]+1<=n) trans[i][a[nxt[i]+1]]=nxt[i]+1;
			}
			trans[i][a[i]]=i;
		}
		int ans=0;
		for(int i=1;i<=n+2;++i) f[i]=0;
		for(int i=n;i>=1;--i){
			if(!nxt[i]) continue ;
			f[i]=f[nxt[i]+1]+1;
			ans+=f[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}