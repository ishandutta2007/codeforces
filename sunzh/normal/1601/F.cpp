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
#define int long long
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n;
vector<int>ve[11];
int sum[11];
const int N=1e6,mod1=998244353,mod2=1e9+7;
int cnt,tmp,ans;
int m1(int x){
	return (x%mod1+mod1)%mod1;
}
void dfs1(int x,int v){
	if(v>n) return ;
	// printf("%lld %lld\n",x,v);
	if(x>6) return ;
	++cnt;ve[x].pb(m1(cnt-v));sum[x]+=m1(cnt-v);
	for(int i=0;i<10;++i) dfs1(x+1,v*10+i);
}
void dfs2(int x,int v){
	if(v>n) return ;
	if(x>=1){
		if(v*N*10>n&&v*N+N-1<=n){
			for(int i=0,t=1;i<=6;++i,t*=10){
				int val=m1(cnt-v*t);
				int pos=lower_bound(ve[i].begin(),ve[i].end(),mod1-val)-ve[i].begin();
				(ans+=val*ve[i].size()+sum[i]-mod1*(ve[i].size()-pos))%=mod2;
			}
			cnt+=tmp;
			return ;
		}
		++cnt;
		(ans+=m1(cnt-v))%=mod2;
	}
	for(int i=(x==0?1:0);i<=9;++i) dfs2(x+1,v*10+i);
}
signed main(){
	n=read();
	dfs1(0,0);
	tmp=cnt;
	cnt=0;
	for(int i=0;i<=6;++i) sort(ve[i].begin(),ve[i].end());
	dfs2(0,0);
	printf("%d\n",ans);
}