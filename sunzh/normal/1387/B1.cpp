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
int n;
int siz[100010];
int rt,idx;
long long res;
int ans[100010];
vector<int>vec[100010];
int dfs(int x,int fa){
	siz[x]=1;
	vector<int>ve;
	for(int i:vec[x]){
		if(i==fa) continue ;
		int a=dfs(i,x);
		if(a!=-1) ve.pb(a);
		siz[x]+=siz[i];
	} 
	int sz=ve.size();
	if(sz==0){
		if(x!=1) return x;
		int v=vec[x][0];
		ans[x]=ans[v],ans[v]=x;res+=2;return -1;
	}
	else if(sz&1){
		for(int i=0;i+2<=sz;i+=2){
			res+=4;
			ans[ve[i]]=ve[i+1],ans[ve[i+1]]=ve[i];
		}
		ans[ve[sz-1]]=x,ans[x]=ve[sz-1];
		res+=2;
		return -1;
	}
	else{
		for(int i=0;i+4<=sz;i+=2){
			res+=4;
			ans[ve[i]]=ve[i+1],ans[ve[i+1]]=ve[i];
		}
		res+=4;
		ans[ve[sz-2]]=x,ans[x]=ve[sz-1],ans[ve[sz-1]]=ve[sz-2];
		return -1;
	}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v);vec[v].pb(u);
	}
	dfs(1,0);
	printf("%lld\n",res);
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
} //MI