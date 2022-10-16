#include <cstdio>
const int Maxn=200000;
int n,q;
char s[Maxn+5];
char t[Maxn+5];
int nxt[Maxn+5];
int len;
namespace Segment_Tree{
	struct Segment_Node{
		int lson,rson;
	}seg[Maxn*20+5];
	int id_tot;
	void insert(int x,int &root,int left=1,int right=n){
		root=++id_tot;
		if(left==right){
			return;
		}
		int mid=(left+right)>>1;
		if(x<=mid){
			insert(x,seg[root].lson,left,mid);
		}
		else{
			insert(x,seg[root].rson,mid+1,right);
		}
	}
	int merge(int root_1,int root_2,int left=1,int right=n){
		if(root_1==0||root_2==0){
			return root_1+root_2;
		}
		if(left==right){
			return root_1;
		}
		int mid=(left+right)>>1;
		int new_node=++id_tot;
		seg[new_node].lson=merge(seg[root_1].lson,seg[root_2].lson,left,mid);
		seg[new_node].rson=merge(seg[root_1].rson,seg[root_2].rson,mid+1,right);
		return new_node;
	}
	bool query(int root,int l,int r,int left=1,int right=n){
		if(l>right||r<left||root==0){
			return 0;
		}
		if(l<=left&&r>=right){
			return 1;
		}
		int mid=(left+right)>>1;
		return query(seg[root].lson,l,r,left,mid)||query(seg[root].rson,l,r,mid+1,right);
	}
	void print(int root,int left=1,int right=n){
		if(root==0){
			return;
		}
		if(left==right){
			printf("%d ",left);
			return;
		}
		int mid=(left+right)>>1;
		print(seg[root].lson,left,mid);
		print(seg[root].rson,mid+1,right);
	}
}
namespace SAM{
	struct Node{
		int ch[26];
		int fa,len;
	}node[Maxn+5];
	int root[Maxn+5];
	int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
	void add_edge(int from,int to){
		arrive[++tot]=to;
		nxt[tot]=head[from];
		head[from]=tot;
	}
	int id_tot=1,last=1;
	void add_ch(int val){
		int p=last;
		int np=last=++id_tot;
		node[np].len=node[p].len+1;
		Segment_Tree::insert(node[np].len,root[np]);
		for(;p&&node[p].ch[val]==0;p=node[p].fa){
			node[p].ch[val]=np;
		}
		if(p==0){
			node[np].fa=1;
		}
		else{
			int q=node[p].ch[val];
			if(node[q].len==node[p].len+1){
				node[np].fa=q;
			}
			else{
				int nq=++id_tot;
				node[nq]=node[q];
				node[nq].len=node[p].len+1;
				node[q].fa=node[np].fa=nq;
				for(;p&&node[p].ch[val]==q;p=node[p].fa){
					node[p].ch[val]=nq;
				}
			}
		}
	}
	void init_dfs(int u){
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			init_dfs(v);
			SAM::root[u]=Segment_Tree::merge(root[u],root[v]);
		}
	}
	void init(){
		for(int i=2;i<=id_tot;i++){
			add_edge(node[i].fa,i);
//			printf("%d-->%d\n",node[i].fa,i);
		}
		/*for(int i=1;i<=id_tot;i++){
			printf("%d %d\n",i,root[i]);
			Segment_Tree::print(root[i]);
			puts("END");
		}*/
		init_dfs(1);
		/*for(int i=1;i<=id_tot;i++){
			printf("%d %d\n",i,root[i]);
			Segment_Tree::print(root[i]);
			puts("END");
		}*/
	}
}
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	for(int i=1;i<=n;i++){
		SAM::add_ch(s[i]-'a');
	}
	SAM::init();
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		scanf("%s",t+1);
		len=0;
		while(t[++len]!='\0');
		len--;
		int root=1;
		for(int j=0;j<=len;j++){
			nxt[j]=-1;
		}
		for(int j=0;j<len;j++){
			for(int k=t[j+1]-'a'+1;k<26;k++){
				int tmp_root=SAM::node[root].ch[k];
				if(tmp_root==0){
					continue;
				}
				if(Segment_Tree::query(SAM::root[tmp_root],l+j,r)){
					nxt[j]=k;
					break;
				}
			}
			root=SAM::node[root].ch[t[j+1]-'a'];
			if(root==0){
				break;
			}
			if(j==len-1){
				for(int k=0;k<26;k++){
					int tmp_root=SAM::node[root].ch[k];
					if(tmp_root==0){
						continue;
					}
					if(Segment_Tree::query(SAM::root[tmp_root],l+len,r)){
						nxt[len]=k;
						break;
					}
				}
			}
		}
		bool flag=0;
		for(int j=len;j>=0;j--){
			if(nxt[j]!=-1){
				for(int k=1;k<=j;k++){
					putchar(t[k]);
				}
				putchar((char)(nxt[j]+'a'));
				puts("");
				flag=1;
				break;
			}
		}
		if(!flag){
			puts("-1");
		}
	}
	return 0;
}