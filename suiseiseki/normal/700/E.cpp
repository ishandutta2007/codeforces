#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=200000;
struct Node{
	int ch[26];
	int fa,len;
	int pos;
}node[Maxn<<1|5];
char s[Maxn+5];
int pos[Maxn+5];
int n;
int id_tot,las;
int add_ch(int v){
	int p=las;
	int np=las=++id_tot;
	node[np].len=node[p].len+1;
	node[np].pos=node[np].len;
	for(;p&&node[p].ch[v]==0;p=node[p].fa){
		node[p].ch[v]=np;
	}
	if(p==0){
		node[np].fa=1;
	}
	else{
		int q=node[p].ch[v];
		if(node[q].len==node[p].len+1){
			node[np].fa=q;
		}
		else{
			int nq=++id_tot;
			node[nq]=node[q];
			node[nq].pos=node[np].pos;
			node[nq].len=node[p].len+1;
			node[np].fa=node[q].fa=nq;
			for(;p&&node[p].ch[v]==q;p=node[p].fa){
				node[p].ch[v]=nq;
			}
		}
	}
	return np;
}
namespace Segment_Tree{
	struct Segment_Node{
		int lson,rson;
	}seg[Maxn*40+5];
	int id_tot;
	int merge(int root_1,int root_2,int left=1,int right=n){
		if(root_1==0||root_2==0){
			return root_1^root_2;
		}
		int root=++id_tot;
		int mid=(left+right)>>1;
		seg[root].lson=merge(seg[root_1].lson,seg[root_2].lson,left,mid);
		seg[root].rson=merge(seg[root_1].rson,seg[root_2].rson,mid+1,right);
		return root;
	}
	void update(int &root,int x,int left=1,int right=n){
		if(root==0){
			root=++id_tot;
		}
		if(left==right){
			return;
		}
		int mid=(left+right)>>1;
		if(x<=mid){
			update(seg[root].lson,x,left,mid);
		}
		else{
			update(seg[root].rson,x,mid+1,right);
		}
	}
	bool query(int root,int l,int r,int left=1,int right=n){
		if(l>right||r<left||root==0||l>r){
			return 0;
		}
		if(l<=left&&r>=right){
			return 1;
		}
		int mid=(left+right)>>1;
		return query(seg[root].lson,l,r,left,mid)||query(seg[root].rson,l,r,mid+1,right);
	}
}
int Root[Maxn<<1|5];
int seq[Maxn<<1|5];
int cnt[Maxn<<1|5];
int top[Maxn<<1|5];
int f[Maxn<<1|5];
int main(){
	las=++id_tot;
    scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		add_ch(s[i]-'a');
	}
	for(int i=1;i<=id_tot;i++){
		cnt[node[i].len]++;
	}
	for(int i=1;i<=n;i++){
		cnt[i]+=cnt[i-1];
	}
	for(int i=id_tot;i>0;i--){
		seq[cnt[node[i].len]--]=i;
	}
	for(int i=id_tot;i>0;i--){
		int u=seq[i];
		if(node[u].pos){
			Segment_Tree::update(Root[u],node[u].pos);
		}
		if(node[u].fa){
			Root[node[u].fa]=Segment_Tree::merge(Root[node[u].fa],Root[u]);
		}
	}
	for(int i=1;i<=id_tot;i++){
		int u=seq[i];
		if(node[u].fa<=1){
			f[u]=1;
			top[u]=u;
		}
		else if(Segment_Tree::query(Root[top[node[u].fa]],node[u].pos-(node[u].len-node[top[node[u].fa]].len),node[u].pos-1)){
			f[u]=f[node[u].fa]+1;
			top[u]=u;
		}
		else{
			f[u]=f[node[u].fa];
			top[u]=top[node[u].fa];
		}
	}
	int ans=0;
	for(int i=1;i<=id_tot;i++){
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}