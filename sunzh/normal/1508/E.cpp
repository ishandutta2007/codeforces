#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n;
int T;
int idx;
int a[300010],pos[300010];
vector<int>vec[300010];
int fa[300010],dep[300010];
int Dfn[300010],Pos[300010];
void dfs(int x,int f){
	fa[x]=f;dep[x]=dep[f]+1;
	for(int v:vec[x]){
		if(v==f) continue ;
		dfs(v,x);
	}
}
long long solve(){
	long long ans=0;
	for(int i=1;i<T;++i){
//		printf("i:%d,pos:%d,Pos:%d\n",i,pos[i],Pos[i]);
		ans+=dep[pos[i]]-1;
	}
	return ans;
}
int in_t[300010],iidx;
int in[300010],out[300010],ot[300010];
int oidx;
void check(int x,int f){
	in[x]=++idx;
	if(a[x]>=T){
		in_t[x]=++iidx;
	}
	auto cmp=[&](int x,int y){
		return Dfn[x]<Dfn[y];
	};
	sort(vec[x].begin(),vec[x].end(),cmp);
	for(int v:vec[x]){
		if(v==f) continue ;
		if(Dfn[v]!=idx+1) {
			printf("NO\n");exit(0);
		}
		check(v,x);
	}
	ot[x]=++oidx;
	out[x]=idx;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),pos[a[i]]=i;
	for(int i=1;i<n;++i){
		int u=read(),v=read();vec[u].pb(v),vec[v].pb(u);
	}
	dfs(1,0);
	Dfn[1]=1;
	int idx=1;
	for(int i=1;i<=n;++i){
		vector<int>st;
		int p=pos[i];
		while(!Dfn[p]){
			st.pb(p);p=fa[p];
		}
		reverse(st.begin(),st.end());
		for(int a:st){
			Dfn[a]=++idx;
		}
	}
	T=max(1,a[1]-1);
	int ps=pos[T],cur=ps;
	int ans=0;
	while(ps!=1){
		swap(a[ps],a[fa[ps]]);
		swap(pos[a[ps]],pos[a[fa[ps]]]);
		ps=fa[ps];
		++ans;
	}
	idx=0;
	check(1,0);
	for(int i=1;i<=n;++i){
		if(a[i]>=T){
			if(a[i]!=in_t[i]+T-1){
				printf("NO\n");exit(0);
			}
		}
		else{
			if(a[i]!=ot[i]){
				printf("NO\n");exit(0);
			}
		}
		if(ot[i]==T){
			if(in[i]<in[cur]||out[i]>out[cur]){
				printf("NO\n");exit(0);
			}
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;++i) Pos[Dfn[i]]=i;
	printf("%lld\n",ans+solve());
	for(int i=1;i<=n;++i) printf("%d ",Dfn[i]);
}