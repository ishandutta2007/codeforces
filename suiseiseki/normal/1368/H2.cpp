#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
const int Inf=0x3f3f3f3f;
int n,m,q;
char s_1[Maxn+5],s_2[Maxn+5],s_3[Maxn+5],s_4[Maxn+5];
namespace Segment_Tree_1{
	struct Segment_Node{
		int l,r;
		int a_0[4],a_1[4],a_2[4],a_3[4];
		int tag;
	}seg[2][Maxn<<2|5];
	void push_up(int root,int t){
		Segment_Node l_val=seg[t][root<<1],r_val=seg[t][root<<1|1];
		int t_n=(t==0?m:n);
		for(int i=0;i<4;i++){
			seg[t][root].a_0[i]=std::min(std::min(l_val.a_0[i]+r_val.a_0[i],l_val.a_1[i]+r_val.a_2[i]),std::min(l_val.a_0[i]+r_val.a_2[i],l_val.a_1[i]+r_val.a_0[i])+t_n);
			seg[t][root].a_1[i]=std::min(std::min(l_val.a_0[i]+r_val.a_1[i],l_val.a_1[i]+r_val.a_3[i]),std::min(l_val.a_0[i]+r_val.a_3[i],l_val.a_1[i]+r_val.a_1[i])+t_n);
			seg[t][root].a_2[i]=std::min(std::min(l_val.a_2[i]+r_val.a_0[i],l_val.a_3[i]+r_val.a_2[i]),std::min(l_val.a_2[i]+r_val.a_2[i],l_val.a_3[i]+r_val.a_0[i])+t_n);
			seg[t][root].a_3[i]=std::min(std::min(l_val.a_2[i]+r_val.a_1[i],l_val.a_3[i]+r_val.a_3[i]),std::min(l_val.a_2[i]+r_val.a_3[i],l_val.a_3[i]+r_val.a_1[i])+t_n);
			seg[t][root].a_0[i]=std::min(seg[t][root].a_0[i],Inf);
			seg[t][root].a_1[i]=std::min(seg[t][root].a_1[i],Inf);
			seg[t][root].a_2[i]=std::min(seg[t][root].a_2[i],Inf);
			seg[t][root].a_3[i]=std::min(seg[t][root].a_3[i],Inf);
			// printf("%d %d %d %d; ",seg[t][root].a_0[i],seg[t][root].a_1[i],seg[t][root].a_2[i],seg[t][root].a_3[i]);
		}
		// puts("");
	}
	void update_tag(Segment_Node &val,int t){
		if(t==0){
			return;
		}
		if(t==1){
			std::swap(val.a_0[0],val.a_0[1]),std::swap(val.a_0[2],val.a_0[3]),std::swap(val.a_1[0],val.a_1[1]),std::swap(val.a_1[2],val.a_1[3]);
			std::swap(val.a_2[0],val.a_2[1]),std::swap(val.a_2[2],val.a_2[3]),std::swap(val.a_3[0],val.a_3[1]),std::swap(val.a_3[2],val.a_3[3]);
		}
		else if(t==2){
			std::swap(val.a_0[0],val.a_0[2]),std::swap(val.a_0[1],val.a_0[3]),std::swap(val.a_1[0],val.a_1[2]),std::swap(val.a_1[1],val.a_1[3]);
			std::swap(val.a_2[0],val.a_2[2]),std::swap(val.a_2[1],val.a_2[3]),std::swap(val.a_3[0],val.a_3[2]),std::swap(val.a_3[1],val.a_3[3]);
		}
		else{
			std::swap(val.a_0[0],val.a_0[3]),std::swap(val.a_0[2],val.a_0[1]),std::swap(val.a_1[0],val.a_1[3]),std::swap(val.a_1[2],val.a_1[1]);
			std::swap(val.a_2[0],val.a_2[3]),std::swap(val.a_2[2],val.a_2[1]),std::swap(val.a_3[0],val.a_3[3]),std::swap(val.a_3[2],val.a_3[1]);
		}
		val.tag^=t;
	}
	void push_down(int root,int t){
		if(seg[t][root].tag!=0){
			update_tag(seg[t][root<<1],seg[t][root].tag);
			update_tag(seg[t][root<<1|1],seg[t][root].tag);
			seg[t][root].tag=0;
		}
	}
	void build(int t,int root,int left,int right){
		if(left==right){
			bool val_1=(t==0?s_1[left]=='R':s_3[left]=='R'),val_2=(t==0?s_2[left]=='R':s_4[left]=='R');
			seg[t][root]=(Segment_Node){left,right,{(!val_1)+(!val_2),val_1+(!val_2),(!val_1)+val_2,val_1+val_2},{Inf,Inf,Inf,Inf},{Inf,Inf,Inf,Inf},{val_1+val_2,(!val_1)+val_2,val_1+(!val_2),(!val_1)+(!val_2)},0};
			return;
		}
		int mid=(left+right)>>1;
		seg[t][root].l=left,seg[t][root].r=right;
		build(t,root<<1,left,mid);
		build(t,root<<1|1,mid+1,right);
		push_up(root,t);
	}
	void update(int l,int r,int v,int t,int root){
		if(r<seg[t][root].l||l>seg[t][root].r){
			return;
		}
		if(l<=seg[t][root].l&&r>=seg[t][root].r){
			update_tag(seg[t][root],v);
			return;
		}
		push_down(root,t);
		update(l,r,v,t,root<<1);
		update(l,r,v,t,root<<1|1);
		push_up(root,t);
	}
}
namespace Segment_Tree_2{
	struct Segment_Node{
		int l,r,sum,tag;
	}seg[4][Maxn<<2|5];
	void build(int t,int root,int left,int right){
		if(left==right){
			seg[t][root]=(Segment_Node){left,right,(t==0?s_1[left]=='R':(t==1?s_2[left]=='R':(t==2?s_3[left]=='R':s_4[left]=='R'))),0};
			return;
		}
		int mid=(left+right)>>1;
		build(t,root<<1,left,mid);
		build(t,root<<1|1,mid+1,right);
		seg[t][root]=(Segment_Node){left,right,seg[t][root<<1].sum+seg[t][root<<1|1].sum,0};
	}
	void update_tag(Segment_Node &val){
		val.tag^=1;
		val.sum=val.r-val.l+1-val.sum;
	}
	void push_down(int t,int root){
		if(seg[t][root].tag==0){
			return;
		}
		update_tag(seg[t][root<<1]),update_tag(seg[t][root<<1|1]);
		seg[t][root].tag=0;
	}
	void update_rev(int l,int r,int t,int root){
		if(r<seg[t][root].l||l>seg[t][root].r){
			return;
		}
		if(l<=seg[t][root].l&&r>=seg[t][root].r){
			update_tag(seg[t][root]);
			return;
		}
		push_down(t,root);
		update_rev(l,r,t,root<<1);
		update_rev(l,r,t,root<<1|1);
		seg[t][root].sum=seg[t][root<<1].sum+seg[t][root<<1|1].sum;
	}
}
int get_ans(){
	// printf("%d %d %d %d ; %d %d %d %d\n",Segment_Tree_1::seg[0][1].a_0[0],Segment_Tree_1::seg[0][1].a_1[0],Segment_Tree_1::seg[0][1].a_2[0],Segment_Tree_1::seg[0][1].a_3[0],
		// Segment_Tree_1::seg[1][1].a_0[0],Segment_Tree_1::seg[1][1].a_1[0],Segment_Tree_1::seg[1][1].a_2[0],Segment_Tree_1::seg[1][1].a_3[0]);
	// printf("%d %d %d %d\n",Segment_Tree_2::seg[0][1].sum,Segment_Tree_2::seg[1][1].sum,Segment_Tree_2::seg[2][1].sum,Segment_Tree_2::seg[3][1].sum);
	return std::min(std::min(std::min(std::min(std::min(std::min(std::min(
		Segment_Tree_1::seg[0][1].a_0[0]+(m<<1)-Segment_Tree_2::seg[2][1].sum-Segment_Tree_2::seg[3][1].sum,
		Segment_Tree_1::seg[0][1].a_1[0]+m-Segment_Tree_2::seg[2][1].sum+Segment_Tree_2::seg[3][1].sum),
		Segment_Tree_1::seg[0][1].a_2[0]+m+Segment_Tree_2::seg[2][1].sum-Segment_Tree_2::seg[3][1].sum),
		Segment_Tree_1::seg[0][1].a_3[0]+Segment_Tree_2::seg[2][1].sum+Segment_Tree_2::seg[3][1].sum),
		Segment_Tree_1::seg[1][1].a_0[0]+(n<<1)-Segment_Tree_2::seg[0][1].sum-Segment_Tree_2::seg[1][1].sum),
		Segment_Tree_1::seg[1][1].a_1[0]+n-Segment_Tree_2::seg[0][1].sum+Segment_Tree_2::seg[1][1].sum),
		Segment_Tree_1::seg[1][1].a_2[0]+n+Segment_Tree_2::seg[0][1].sum-Segment_Tree_2::seg[1][1].sum),
		Segment_Tree_1::seg[1][1].a_3[0]+Segment_Tree_2::seg[0][1].sum+Segment_Tree_2::seg[1][1].sum);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s%s%s%s",s_1+1,s_2+1,s_3+1,s_4+1);
	Segment_Tree_1::build(0,1,1,n);
	Segment_Tree_1::build(1,1,1,m);
	Segment_Tree_2::build(0,1,1,n);
	Segment_Tree_2::build(1,1,1,n);
	Segment_Tree_2::build(2,1,1,m);
	Segment_Tree_2::build(3,1,1,m);
	printf("%d\n",get_ans());
	for(int i=1;i<=q;i++){
		char op[4];
		scanf("%s",op);
		int l,r;
		scanf("%d%d",&l,&r);
		if((*op)=='L'){
			Segment_Tree_1::update(l,r,1,0,1);
			Segment_Tree_2::update_rev(l,r,0,1);
		}
		else if((*op)=='R'){
			Segment_Tree_1::update(l,r,2,0,1);
			Segment_Tree_2::update_rev(l,r,1,1);
		}
		else if((*op)=='U'){
			Segment_Tree_1::update(l,r,1,1,1);
			Segment_Tree_2::update_rev(l,r,2,1);
		}
		else{
			Segment_Tree_1::update(l,r,2,1,1);
			Segment_Tree_2::update_rev(l,r,3,1);
		}
		printf("%d\n",get_ans());
	}
	return 0;
}