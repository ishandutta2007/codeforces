#include <set>
#include <vector>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=250000;
const int Maxv=1000000;
int n,k;
int deg[Maxn+5],id[Maxn+5];
bool cmp_deg(int x,int y){
	return deg[x]<deg[y];
}
std::set<std::pair<int,int> > edge[Maxn+5];
struct Semgent_Node{
	int lson,rson;
	int num;
	ll sum;
}seg[Maxn*30+5];
int Root[Maxn+5];
int id_tot;
void push_up(int root){
	seg[root].num=seg[seg[root].lson].num+seg[seg[root].rson].num;
	seg[root].sum=seg[seg[root].lson].sum+seg[seg[root].rson].sum;
}
void update(int &root,int x,int a,int left=1,int right=Maxv){
	if(root==0){
		root=++id_tot;
	}
	if(left==right){
		seg[root].num+=a;
		seg[root].sum+=a*left;
		return;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		update(seg[root].lson,x,a,left,mid);
	}
	else{
		update(seg[root].rson,x,a,mid+1,right);
	}
	push_up(root);
}
ll query(int root,int &k,int left=1,int right=Maxv){
	if(root==0||k==0){
		return 0;
	}
	if(seg[root].num<=k){
		k-=seg[root].num;
		return seg[root].sum;
	}
	if(left==right){
		ll ans=1ll*k*left;
		k=0;
		return ans;
	}
	int mid=(left+right)>>1;
	ll ans=query(seg[root].lson,k,left,mid);
	ans+=query(seg[root].rson,k,mid+1,right);
	return ans;
}
void print(int root,int left=1,int right=Maxv){
	if(root==0||seg[root].num==0){
		return;
	}
	if(left==right){
		printf("%d %d; ",left,seg[root].num);
		return;
	}
	int mid=(left+right)>>1;
	print(seg[root].lson,left,mid),print(seg[root].rson,mid+1,right);
}
bool vis[Maxn+5];
ll f[Maxn+5][2];
void del_node(int u){
	std::set<std::pair<int,int> >::iterator it;
	it=edge[u].begin();
	while(it!=edge[u].end()){
		edge[(it->first)].erase(std::make_pair(u,it->second));
		update(Root[it->first],(it->second),1);
		it++;
	}
}
void work_dfs(int u,int fa){
	vis[u]=1;
	ll sum=0;
	std::set<std::pair<int,int> >::iterator it;
	std::vector<int> val;
	it=edge[u].begin();
	int num=0;
	while(it!=edge[u].end()){
		if((it->first)==fa){
			it++;
			continue;
		}
		int v=(it->first);
		work_dfs(v,u);
		sum+=f[v][0];
		if(f[v][1]+(it->second)-f[v][0]<=0){
			num++;
			sum+=f[v][1]+(it->second)-f[v][0];
		}
		else{
			val.push_back(f[v][1]+(it->second)-f[v][0]);
		}
		it++;
	}
	if(num>=deg[u]-k){
		f[u][0]=f[u][1]=sum;
	}
	else{
		for(int i=0;i<(int)val.size();i++){
			update(Root[u],val[i],1);
		}
		int tmp_k=deg[u]-k-num-1;
		f[u][1]=sum+query(Root[u],tmp_k);
		tmp_k=deg[u]-k-num;
		f[u][0]=sum+query(Root[u],tmp_k);
		for(int i=0;i<(int)val.size();i++){
			update(Root[u],val[i],-1);
		}
	}
}
std::vector<ll> minimum_closure_costs(int N,std::vector<int> U,std::vector<int> V,std::vector<int> W){
	n=N;
	ll sum=0;
	for(int i=0;i<n-1;i++){
		U[i]++,V[i]++;
		deg[U[i]]++,deg[V[i]]++;
		sum+=W[i];
		edge[U[i]].insert(std::make_pair(V[i],W[i]));
		edge[V[i]].insert(std::make_pair(U[i],W[i]));
	}
	for(int i=1;i<=n;i++){
		id[i]=i;
	}
	std::sort(id+1,id+1+n,cmp_deg);
	std::vector<ll> ans;
	ans.push_back(sum);
	for(int i=1,pos=1;i<n;i++){
		k=i;
		while(pos<=n&&deg[id[pos]]<=i){
			del_node(id[pos]);
			pos++;
		}
		for(int j=pos;j<=n;j++){
			vis[id[j]]=0;
		}
		sum=0;
		for(int j=pos;j<=n;j++){
			if(vis[id[j]]){
				continue;
			}
			work_dfs(id[j],0);
			sum+=f[id[j]][0];
		}
		ans.push_back(sum);
	}
	return ans;
}
int main() {
  int N;
  scanf("%d", &N);

  std::vector<int> U(N - 1), V(N - 1), W(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    scanf("%d %d %d", &U[i], &V[i], &W[i]);
    U[i]--,V[i]--;
  }

  std::vector<long long> closure_costs = minimum_closure_costs(N, U, V, W);
  for (int i = 0; i < static_cast<int>(closure_costs.size()); ++i) {
    if (i > 0) {
      printf(" ");
    }
    printf("%lld",closure_costs[i]);
  }
  printf("\n");
  return 0;
}