#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
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
int n,m;
int L,R;
int head[500010],nxt[10000010],to[10000010];
int tot;
set<int>st;
int cnt[500010];
void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
signed main(){
	n=read(),m=read(),L=read(),R=read();
	for(int i=1;i<=200000;++i)
		for(int j=i;j<=200000;j+=i) add(j,i);
//	printf("tot:%d\n",tot);
	int lstL=m+1,lstR=m;
	for(int i=1;i<=n;++i){
		int l=ceil((double)L/i),r=floor((double)R/i);
		while(lstL>l){
			--lstL;
			for(int j=head[lstL];j;j=nxt[j]){
				int v=to[j];
				if(cnt[v]==0) st.insert(v);
				++cnt[v];
			}
		}
		while(lstR>r){
			for(int j=head[lstR];j;j=nxt[j]){
				int v=to[j];
				--cnt[v];if(cnt[v]==0) st.erase(v);
			}
			--lstR;
		}
		bool flag=0;
		for(int j=head[i];j;j=nxt[j]){
			int d=to[j];int t=i/d;
			auto it=st.upper_bound(t);
			if(it!=st.end()&&(d*(*it)<=n)){
				flag=1;
				int k=lstR/(*it);
				printf("%lld %lld %lld %lld\n",i,k*(*it),d*(*it),k*t);
				break ;
			}
		}
		if(!flag) printf("-1\n");
	}
}