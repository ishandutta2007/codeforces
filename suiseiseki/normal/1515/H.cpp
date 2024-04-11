#include <cstdio>
#include <algorithm>
const int Maxn=200000;
const int Maxv=(1<<20);
const int Maxk=20;
int n,q;
int a[Maxn+5];
int Root,id_tot;
struct Trie_Node{
	int ch[2];
	int val_0,val_1;
	int sum;
	int lazy;
}seg[Maxn*Maxk+5];
int st[Maxn*Maxk+5],st_top;
int new_node(){
	int u;
	if(st_top>0){
		u=st[st_top--];
	}
	else{
		u=++id_tot;
	}
	seg[u].ch[0]=seg[u].ch[1]=0;
	seg[u].val_0=seg[u].val_1=0;
	seg[u].sum=0;
	seg[u].lazy=0;
	return u;
}
void del_node(int u){
	st[++st_top]=u;
}
void push_up(int root,int dep){
	seg[root].sum=seg[seg[root].ch[0]].sum+seg[seg[root].ch[1]].sum;
	seg[root].val_0=seg[seg[root].ch[0]].val_0|seg[seg[root].ch[1]].val_0;
	seg[root].val_1=seg[seg[root].ch[0]].val_1|seg[seg[root].ch[1]].val_1;
	if(seg[root].ch[0]){
		seg[root].val_0|=(1<<dep);
	}
	if(seg[root].ch[1]){
		seg[root].val_1|=(1<<dep);
	}
}
void insert(int val,int &root=Root,int dep=Maxk-1){
	if(root==0){
		root=new_node();
	}
	if(dep==-1){
		seg[root].sum=1;
		return;
	}
	insert(val,seg[root].ch[(val>>dep)&1],dep-1);
	push_up(root,dep);
}
void update_tag(int root,int v,int dep){
	if(root==0||dep==-1){
		return;
	}
	if((v>>dep)&1){
		std::swap(seg[root].ch[0],seg[root].ch[1]);
	}
	int tmp=(seg[root].val_0^seg[root].val_1)&v;
	seg[root].val_0^=tmp,seg[root].val_1^=tmp;
	seg[root].lazy^=v;
}
void push_down(int root,int dep){
	if(seg[root].lazy){
		update_tag(seg[root].ch[0],seg[root].lazy,dep-1);
		update_tag(seg[root].ch[1],seg[root].lazy,dep-1);
		seg[root].lazy=0;
	}
}
int trie_merge(int root_1,int root_2,int dep=Maxk-1){
	if(root_1==0||root_2==0){
		return root_1^root_2;
	}
	if(dep==-1){
		del_node(root_2);
		return root_1;
	}
	push_down(root_1,dep);
	push_down(root_2,dep);
	seg[root_1].ch[0]=trie_merge(seg[root_1].ch[0],seg[root_2].ch[0],dep-1);
	seg[root_1].ch[1]=trie_merge(seg[root_1].ch[1],seg[root_2].ch[1],dep-1);
	del_node(root_2);
	push_up(root_1,dep);
	return root_1;
}
void trie_split(int root,int k,int &l_root,int &r_root,int dep=Maxk-1){
	if(root==0){
		l_root=r_root=0;
		return;
	}
	if(dep==-1){
		l_root=root;
		r_root=0;
		return;
	}
	push_down(root,dep);
	if((k>>dep)&1){
		l_root=root;
		r_root=new_node();
		trie_split(seg[root].ch[1],k,seg[l_root].ch[1],seg[r_root].ch[1],dep-1);
	}
	else{
		l_root=new_node();
		r_root=root;
		trie_split(seg[root].ch[0],k,seg[l_root].ch[0],seg[r_root].ch[0],dep-1);
	}
	push_up(l_root,dep);
	push_up(r_root,dep);
}
void push_or(int root,int k,int dep=Maxk-1){
	if(root==0||((seg[root].val_0>>k)&1)==0){
		return;
	}
	if(((seg[root].val_1>>k)&1)==0){
		update_tag(root,1<<k,dep);
		return;
	}
	push_down(root,dep);
	if(dep==k){
		seg[root].ch[1]=trie_merge(seg[root].ch[0],seg[root].ch[1],dep-1);
		seg[root].ch[0]=0;
		push_up(root,dep);
		return;
	}
	push_or(seg[root].ch[0],k,dep-1);
	push_or(seg[root].ch[1],k,dep-1);
	push_up(root,dep);
}
void push_and(int root,int k,int dep=Maxk-1){
	if(root==0||((seg[root].val_1>>k)&1)==0){
		return;
	}
	if(((seg[root].val_0>>k)&1)==0){
		update_tag(root,1<<k,dep);
		return;
	}
	push_down(root,dep);
	if(dep==k){
		seg[root].ch[0]=trie_merge(seg[root].ch[0],seg[root].ch[1],dep-1);
		seg[root].ch[1]=0;
		push_up(root,dep);
		return;
	}
	push_and(seg[root].ch[0],k,dep-1);
	push_and(seg[root].ch[1],k,dep-1);
	push_up(root,dep);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		insert(a[i]);
	}
	for(int t=1;t<=q;t++){
		int op;
		scanf("%d",&op);
		int l,r;
		scanf("%d%d",&l,&r);
		int l_root=0,r_root=0;
		if(l){
			trie_split(Root,l-1,l_root,Root);
		}
		trie_split(Root,r,Root,r_root);
		if(op==1){
			int x;
			scanf("%d",&x);
			for(int i=0;i<Maxk;i++){
				if(((x>>i)&1)==0){
					push_and(Root,i);
				}
			}
		}
		else if(op==2){
			int x;
			scanf("%d",&x);
			for(int i=0;i<Maxk;i++){
				if(((x>>i)&1)==1){
					push_or(Root,i);
				}
			}
		}
		else if(op==3){
			int x;
			scanf("%d",&x);
			update_tag(Root,x,Maxk-1);
		}
		else{
			printf("%d\n",seg[Root].sum);
		}
		Root=trie_merge(trie_merge(l_root,Root),r_root);
	}
	return 0;
}