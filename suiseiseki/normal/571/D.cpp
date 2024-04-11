#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int Maxn=500000;
struct Tree{
	int n;
    vector<int> parent,lc,rc,id;
    vector<vector<int> > mod;
    void init(int n){
    	parent.assign(2*n-1,-1);
		lc.assign(2*n-1,-1);
		rc.assign(2*n-1,-1);
		id.resize(n);
		iota(id.begin(),id.end(),0);
		mod.resize(2*n-1);
	}
};
int n,m;
Tree t1,t2;
vector<vector<int> > query;
vector<int> lb,sz;
vector<ll> ans;
ll fen[Maxn+5];
void add(int x,int y){
	for(int i=x+1;i<=Maxn;i+=(i&(-i))){
		fen[i]+=y;
	}
}
ll sum(int x){
	ll res=0;
	for(int i=x;i>0;i-=(i&(-i))){
		res+=fen[i];
	}
	return res;
}
ll sum(int l,int r){
	return sum(r)-sum(l);
}
int getLeft(int x){
	int s=sum(x);
	x=0;
	for(int i=(1<<18);i>0;i>>=1){
		if(x+i<=Maxn&&fen[x+i]<s){
			x+=i;
			s-=fen[x];
		}
	}
	return x;
}
void dfs_1(int u){
	for(int i:t2.mod[u]){
		add(i,1);
	}
	if(u<n){
		for(int i:query[u]){
			lb[i]=getLeft(i);
		}
	}
	else{
		dfs_1(t2.lc[u]);
		dfs_1(t2.rc[u]);
	}
	for(int i:t2.mod[u]){
		add(i,-1);
	}
}
void dfs_2(int u){
	for(int i:t1.mod[u]){
		add(i,sz[u]);
	}
	if(u<n){
		for(int i:query[u]){
			ans[i]=sum(lb[i],i);
		}
	}
	else{
		dfs_2(t1.lc[u]);
		dfs_2(t1.rc[u]);
	}
	for(int i:t1.mod[u]){
		add(i,-sz[u]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	t1.init(n),t2.init(n);
	query.resize(n);
	lb.resize(m);
	sz.resize((n<<1)-1);
	for(int i=0;i<(n<<1)-1;i++){
		sz[i]=1;
	}
	ans.resize(m);
	for(int i=0;i<m;i++){
		ans[i]=-1;
	}
	int c1=0,c2=0;
	for(int i=0;i<m;i++){
		char op,qu[5];
		scanf("%s",qu);
		op=(*qu);
		if(op=='U'){
			int a,b;
			scanf("%d%d",&a,&b);
			a--;
			b--;
			int p=n+(c1++);
			t1.parent[t1.id[a]]=t1.parent[t1.id[b]]=p;
			t1.lc[p]=t1.id[a];
			t1.rc[p]=t1.id[b];
			t1.id[a]=p;
			sz[p]=sz[t1.lc[p]]+sz[t1.rc[p]];
		}
		else if(op=='M'){
			int a,b;
			scanf("%d%d",&a,&b);
			a--;
			b--;
			int p=n+(c2++);
			t2.parent[t2.id[a]]=t2.parent[t2.id[b]]=p;
			t2.lc[p]=t2.id[a];
			t2.rc[p]=t2.id[b];
			t2.id[a]=p;
		}
		else if(op=='A'){
			int x;
			scanf("%d",&x);
			x--;
			t1.mod[t1.id[x]].push_back(i);
		}
		else if(op=='Z'){
			int x;
			scanf("%d",&x);
			x--;
			t2.mod[t2.id[x]].push_back(i);
		}
		else{
			int x;
			scanf("%d",&x);
			x--;
			query[x].push_back(i);
		}
	}
	for(int i=0;i<n+c2;i++){
		if(t2.parent[i]==-1){
			dfs_1(i);
		}
	}
	for(int i=0;i<n+c1;i++){
		if(t1.parent[i]==-1){
			dfs_2(i);
		}
	}
	for(int i=0;i<m;i++){
		if(ans[i]!=-1){
			printf("%lld\n",ans[i]);
		}
	}
	return 0;
}