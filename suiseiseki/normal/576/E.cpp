#include <vector>
#include <cstdio>
#include <cassert>
using namespace std;
const int Maxn=500000;
int u[Maxn+5],v[Maxn+5],c[Maxn+5];
int n,m,k,q;
struct DSU{
	int fa[Maxn+5],val[Maxn+5],sz[Maxn+5];
	int st[Maxn+5],top;
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
		int fa_x=find(x),fa_y=find(y),x_val=find_val(x),y_val=find_val(y);
		if(fa_x==fa_y){
			/*if((x_val^y_val)==0){
				printf("Failed: %d %d\n",x,y);
			}*/
			return (x_val^y_val)==1;
		}
		if(sz[fa_x]<sz[fa_y]){
			swap(x,y);
			swap(fa_x,fa_y);
			swap(x_val,y_val);
		}
		fa[fa_y]=fa_x;
		val[fa_y]=(x_val^y_val^1);
		sz[fa_x]+=sz[fa_y];
		st[++top]=fa_y;
//		printf("Link: %d %d\n",fa_x,fa_y);
		return 1;
	}
	void del(int k){
		while(top>k){
			int u=st[top];
			int v=fa[u];
			sz[v]-=sz[u];
			fa[u]=u;
			val[u]=0;
//			printf("Del: %d %d\n",v,u);
			top--;
		}
	}
	void init(){
		for(int i=1;i<=n;i++){
			sz[i]=1;
			fa[i]=i;
		}
	}
}dsu[51];
struct Question{
	int p,e;
	Question(int _p=0,int _e=0){
		p=_p;
		e=_e;
	}
}qu[Maxn+5];
int pos[Maxn+5];
vector<int> id[Maxn+5];
bool ans[Maxn+5];
struct Segment_Tree{
	vector<Question> lis[Maxn<<2|5];
	int begin[205][51];
	int dep[Maxn<<2|5];
	void update(int l,int r,Question a,int root=1,int left=1,int right=q){
		if(l>right||r<left||l>r){
			return;
		}
		if(l<=left&&r>=right){
			lis[root].push_back(a);
			return;
		}
		int mid=(left+right)>>1;
		update(l,r,a,root<<1,left,mid);
		update(l,r,a,root<<1|1,mid+1,right);
	}
	bool insert(int root){
		for(int i=1;i<=k;i++){
			begin[dep[root]][i]=dsu[i].top;
		}
		for(int i=0;i<(int)lis[root].size();i++){
//			printf("Insert: %d %d\n",u[lis[root][i].p],v[lis[root][i].p]);
			if(!dsu[lis[root][i].e].merge(u[lis[root][i].p],v[lis[root][i].p])){
				return 0;
			}
		}
		return 1;
	}
	void del(int root){
		for(int i=1;i<=k;i++){
			dsu[i].del(begin[dep[root]][i]);
		}
	}
	void query(int root=1,int left=1,int right=q){
		if(left==right){
			lis[root].push_back(qu[left]);
//			if(left==8){
				/*for(int i=1;i<=n;i++){
					printf("%d ",dsu[1].find(i));
				}
				puts("");*/
				/*for(int i=0;i<(int)lis[root].size();i++){
					printf("%d %d\n",u[lis[root][i].p],v[lis[root][i].p]);
				}*/
//			}
//			printf("Query: %d %d %d %d %d %d\n",left,(int)lis[root].size(),u[qu[left].p],v[qu[left].p],c[qu[left].p],qu[left].e);
			if(insert(root)){
				ans[left]=1;
				c[qu[left].p]=qu[left].e;
				update(id[qu[left].p][pos[qu[left].p]]+1,id[qu[left].p][pos[qu[left].p]+1]-1,qu[left]);
//				puts("Successful!");
			}
			else if(c[qu[left].p]){
				update(id[qu[left].p][pos[qu[left].p]]+1,id[qu[left].p][pos[qu[left].p]+1]-1,Question(qu[left].p,c[qu[left].p]));
//				puts("Failed...");
			}
			pos[qu[left].p]++;
			assert(pos[qu[left].p]<(int)id[qu[left].p].size());
			del(root);
			return;
		}
		insert(root);
		int mid=(left+right)>>1;
		dep[root<<1]=dep[root<<1|1]=dep[root]+1;
		query(root<<1,left,mid);
		query(root<<1|1,mid+1,right);
		del(root);
	}
}seg;
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&qu[i].p,&qu[i].e);
		id[qu[i].p].push_back(i);
	}
	for(int i=1;i<=m;i++){
		id[i].push_back(q+1);
	}
	for(int i=1;i<=k;i++){
		dsu[i].init();
	}
	seg.query();
	for(int i=1;i<=q;i++){
		if(ans[i]){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}