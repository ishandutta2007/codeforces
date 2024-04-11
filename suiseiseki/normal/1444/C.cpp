#include <stack>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=500000;
int n,m,k;
int c[Maxn+5],a[Maxn+5];
bool del[Maxn+5];
bool vis[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
struct Edge{
	int u,v;
	friend bool operator ==(Edge p,Edge q){
		return c[p.u]==c[q.u]&&c[p.v]==c[q.v];
	}
	friend bool operator <(Edge p,Edge q){
		if(c[p.u]==c[q.u]){
			return c[p.v]<c[q.v];
		}
		return c[p.u]<c[q.u];
	}
}edge[Maxn+5];
int dep[Maxn+5];
int fa[Maxn+5],sz[Maxn+5],val[Maxn+5];
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return find(fa[x]);
}
int find_val(int x){
	if(x==fa[x]){
		return 0;
	}
	return find_val(fa[x])^val[x];
}
bool merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	int tmp_val=find_val(x)^find_val(y);
	if(fa_x==fa_y){
		if(tmp_val!=1){
			return 0;
		}
		return 1;
	}
	if(sz[fa_x]<sz[fa_y]){
		swap(fa_x,fa_y);
		swap(x,y);
	}
	sz[fa_x]+=sz[fa_y];
	fa[fa_y]=fa_x;
	val[fa_y]=tmp_val^1;
	return 1;
}
stack<pair<int,pair<int,int> > > st;
void del_all(){
	while(!st.empty()){
		fa[st.top().first]=st.top().second.first;
		sz[st.top().first]=st.top().second.second;
		val[st.top().first]=0;
		st.pop();
	}
}
bool del_merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	int tmp_val=find_val(x)^find_val(y);
	if(fa_x==fa_y){
		if(tmp_val!=1){
			return 0;
		}
		return 1;
	}
	if(sz[fa_x]<sz[fa_y]){
		swap(fa_x,fa_y);
		swap(x,y);
	}
	st.push(make_pair(fa_x,make_pair(fa_x,sz[fa_x])));
	st.push(make_pair(fa_y,make_pair(fa_y,sz[fa_y])));
	sz[fa_x]+=sz[fa_y];
	fa[fa_y]=fa_x;
	val[fa_y]=tmp_val^1;
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&edge[i].u,&edge[i].v);
		if(c[edge[i].u]>c[edge[i].v]){
			swap(edge[i].u,edge[i].v);
		}
		if(c[edge[i].u]==c[edge[i].v]){
			if(!merge(edge[i].u,edge[i].v)){
				del[c[edge[i].u]]=1;
			}
		}
	}
	sort(edge+1,edge+1+m);
	ll ans=0;
	for(int i=1,j;i<=m;i=j+1){
		j=i;
		while(j<=m&&edge[j]==edge[i]){
			j++;
		}
		j--;
		if(c[edge[i].u]==c[edge[i].v]){
			continue;
		}
		if(del[c[edge[i].u]]||del[c[edge[i].v]]){
			continue;
		}
		bool flag=1;
		for(int k=i;k<=j;k++){
			if(!del_merge(edge[k].u,edge[k].v)){
				flag=0;
				break;
			}
		}
		del_all();
		if(!flag){
			ans++;
		}
	}
	int sum=0;
	for(int i=1;i<=k;i++){
		if(!del[i]){
			sum++;
		}
	}
	ans=(1ll*sum*(sum-1)>>1)-ans;
	if(ans<0){
		ans=0;
	}
	printf("%lld\n",ans);
	return 0;
}