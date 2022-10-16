#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=500000;
const int Maxm=50000;
const int Inf=0x3f3f3f3f;
int n;
namespace Segment_Tree{
	struct Segment_Node{
		int lson,rson;
		std::pair<int,int> val;
	}seg[(Maxm<<1)*20+5];
	int id_tot;
	int Root[Maxm<<1|5];
	void update(int &root,int x,int left=1,int right=n){
		if(root==0){
			root=++id_tot;
		}
		if(left==right){
			seg[root].val.first++;
			seg[root].val.second=-left;
			return;
		}
		int mid=(left+right)>>1;
		if(x<=mid){
			update(seg[root].lson,x,left,mid);
		}
		else{
			update(seg[root].rson,x,mid+1,right);
		}
		seg[root].val=std::max(seg[seg[root].lson].val,seg[seg[root].rson].val);
	}
	int merge(int root_1,int root_2,int left=1,int right=n){
		if(root_1==0||root_2==0){
			return root_1^root_2;
		}
		int t_root=++id_tot;
		seg[t_root]=seg[root_1];
		if(left==right){
			seg[t_root].val.first+=seg[root_2].val.first;
			return t_root;
		}
		int mid=(left+right)>>1;
		seg[t_root].lson=merge(seg[root_1].lson,seg[root_2].lson,left,mid);
		seg[t_root].rson=merge(seg[root_1].rson,seg[root_2].rson,mid+1,right);
		seg[t_root].val=std::max(seg[seg[t_root].lson].val,seg[seg[t_root].rson].val);
		return t_root;
	}
	std::pair<int,int> query(int root,int l,int r,int left=1,int right=n){
		if(l>right||r<left){
			return std::make_pair(0,-Inf);
		}
		if(l<=left&&r>=right){
			return seg[root].val;
		}
		int mid=(left+right)>>1;
		return std::max(query(seg[root].lson,l,r,left,mid),query(seg[root].rson,l,r,mid+1,right));
	}
}
namespace SAM{
	struct Node{
		int ch[26];
		int fa,len;
	}node[Maxm<<1|5];
	int id_tot;
	int add_ch(int val,int las,int id){
		if(node[las].ch[val]){
			int p=las,q=node[las].ch[val];
			if(node[p].len+1==node[q].len){
				Segment_Tree::update(Segment_Tree::Root[q],id);
				return q;
			}
			else{
				int nq=++id_tot;
				node[nq]=node[q];
				node[nq].len=node[p].len+1;
				node[q].fa=nq;
				for(;p&&node[p].ch[val]==q;p=node[p].fa){
					node[p].ch[val]=nq;
				}
				Segment_Tree::update(Segment_Tree::Root[nq],id);
				return nq;
			}
		}
		int p=las,np=++id_tot;
		node[np].len=node[las].len+1;
		for(;p&&node[p].ch[val]==0;p=node[p].fa){
			node[p].ch[val]=np;
		}
		if(p==0){
			node[np].fa=1;
		}
		else{
			int q=node[p].ch[val];
			if(node[p].len+1==node[q].len){
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
		Segment_Tree::update(Segment_Tree::Root[np],id);
		return np;
	}
	int fa[20][Maxm<<1|5];
	int head[Maxm<<1|5],arrive[Maxm<<1|5],nxt[Maxm<<1|5],tot;
	void add_edge(int from,int to){
		arrive[++tot]=to;
		nxt[tot]=head[from];
		head[from]=tot;
	}
	void build_tree(){
		for(int i=id_tot;i>1;i--){
			add_edge(node[i].fa,i);
			fa[0][i]=node[i].fa;
		}
		for(int i=1;i<20;i++){
			for(int j=1;j<=id_tot;j++){
				fa[i][j]=fa[i-1][fa[i-1][j]];
			}
		}
	}
	void init_dfs(int u){
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			init_dfs(v);
			Segment_Tree::Root[u]=Segment_Tree::merge(Segment_Tree::Root[u],Segment_Tree::Root[v]);
		}
	}
}
char s[Maxn+5];
int s_len;
int pos[Maxn+5],max_l[Maxn+5];
std::pair<int,int> query_ans(int l,int r,int p_l,int p_r){
	if(p_r-p_l+1>max_l[p_r]){
		return std::make_pair(0,-l);
	}
	int t_pos=pos[p_r];
	for(int i=19;i>=0;i--){
		if(SAM::node[SAM::fa[i][t_pos]].len>=p_r-p_l+1){
			t_pos=SAM::fa[i][t_pos];
		}
	}
	std::pair<int,int> ans=Segment_Tree::query(Segment_Tree::Root[t_pos],l,r);
	if(ans.first==0){
		ans.second=-l;
	}
	return ans;
}
int main(){
	scanf("%s",s+1);
	while(s[++s_len]!='\0');
	s_len--;
	SAM::id_tot=1;
	int las=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		static char t[Maxm+5];
		scanf("%s",t+1);
		int t_len=0;
		while(t[++t_len]!='\0');
		t_len--;
		las=1;
		for(int j=1;j<=t_len;j++){
			las=SAM::add_ch(t[j]-'a',las,i);
		}
	}
	SAM::build_tree();
	SAM::init_dfs(1);
	int t_pos=1,t_len=0;
	for(int i=1;i<=s_len;i++){
		while(t_pos&&SAM::node[t_pos].ch[s[i]-'a']==0){
			t_pos=SAM::node[t_pos].fa;
			t_len=SAM::node[t_pos].len;
		}
		t_pos=SAM::node[t_pos].ch[s[i]-'a'];
		if(t_pos==0){
			t_pos=1,t_len=0;
		}
		else{
			t_len++;
		}
		pos[i]=t_pos,max_l[i]=t_len;
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int l,r,p_l,p_r;
		scanf("%d%d%d%d",&l,&r,&p_l,&p_r);
		std::pair<int,int> ans=query_ans(l,r,p_l,p_r);
		printf("%d %d\n",-ans.second,ans.first);
	}
	return 0;
}