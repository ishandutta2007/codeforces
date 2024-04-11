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
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n,m;
int a[300010];
set<int>vec[300010];
int c[300010],cnt[300010];
const int B=70;
vector<int>s[B+11];
vector<int>big;
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i) a[i]=c[i]=read(),set<int>().swap(vec[i]);
		for(int i=0;i<=B;++i) vector<int>().swap(s[i]);
		vector<int>().swap(big);
		sort(c+1,c+n+1);
		int N=unique(c+1,c+n+1)-c-1;
		for(int i=1;i<=n;++i){
			int t=lower_bound(c+1,c+N+1,a[i])-c;
			++cnt[t];
		}
		for(int i=1;i<=m;++i){
			int x=read(),y=read();
			x=lower_bound(c+1,c+N+1,x)-c;
			y=lower_bound(c+1,c+N+1,y)-c;
			vec[x].insert(y);vec[y].insert(x);
		}
		for(int i=1;i<=N;++i){
			if(cnt[i]<=B) s[cnt[i]].pb(i);
			else big.pb(i);
		}
		long long ans=0;
		for(int i:big){
			for(int j:big) if(i!=j&&!vec[i].count(j)){
				ans=max(ans,1ll*(cnt[i]+cnt[j])*(c[i]+c[j]));
			}
		}
		for(int i=1;i<=N;++i){
			for(int j=1;j<=B;++j){
				for(int t=s[j].size()-1;t>=0;--t){
					int v=s[j][t];
					if(i!=v&&!vec[i].count(v)){
						// printf("i:%d,v:%d,%d %d,%d %d\n",i,v,c[i],c[v],j,cnt[i]);
						ans=max(ans,1ll*(j+cnt[i])*(c[i]+c[v]));
						break ;
					}
				}
			}
		}
		for(int i=1;i<=N;++i) cnt[i]=0;
		printf("%lld\n",ans);
	}
}