#include <cstdio>
const int Maxn=100000;
const int Maxb=1024;
struct Value{
	int val,id;
	Value(int _val=0,int _id=0){
		val=_val,id=_id;
	}
};
namespace BIN{
	Value bin_array[Maxn*40+5];
	Value *bin_pos=bin_array;
	Value* new_array(int len){
		Value *ans=bin_pos;
		bin_pos+=len;
		return ans;
	}
}
struct Semgent_Node{
	Value *lis;
}seg[Maxn<<2|5];
int n,q;
int b[Maxn+5];
void push_up(Value *ans,Value *lis_1,int len_1,Value *lis_2,int len_2){
	int pos_1=0,pos_2=0;
	int len=0;
	while(pos_1<len_1&&pos_2<len_2){
		if(lis_1[pos_1].val+pos_2<lis_2[pos_2].val){
			ans[len++]=Value(lis_1[pos_1].val+pos_2,lis_1[pos_1].id);
			pos_1++;
		}
		else{
			ans[len++]=lis_2[pos_2++];
		}
	}
	while(pos_1<len_1){
		ans[len++]=Value(lis_1[pos_1].val+pos_2,lis_1[pos_1].id);
		pos_1++;
	}
	while(pos_2<len_2){
		ans[len++]=lis_2[pos_2++];
	}
}
void build(int root=1,int left=1,int right=n){
	seg[root].lis=NULL;
	if(right-left+1<=Maxb){
		seg[root].lis=BIN::new_array(right-left+1);
	}
	if(left==right){
		seg[root].lis[0]=Value(b[left],left);
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	if(seg[root].lis!=NULL){
		push_up(seg[root].lis,seg[root<<1].lis,mid-left+1,seg[root<<1|1].lis,right-mid);
	}
}
void update(int x,int a,int root=1,int left=1,int right=n){
	if(left==right){
		seg[root].lis[0]=Value(a,left);
		return;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		update(x,a,root<<1,left,mid);
	}
	else{
		update(x,a,root<<1|1,mid+1,right);
	}
	if(seg[root].lis!=NULL){
		push_up(seg[root].lis,seg[root<<1].lis,mid-left+1,seg[root<<1|1].lis,right-mid);
	}
}
int query(int x,int root=1,int left=1,int right=n,int ans=0){
	if(seg[root].lis!=NULL){
		if(ans==0){
			for(int i=0;i<right-left+1;i++){
				if(seg[root].lis[i].id==x){
					ans=seg[root].lis[i].val;
					break;
				}
			}
		}
		else{
			int l=0,r=right-left+1;
			while(l<r){
				int mid=(l+r)>>1;
				if(ans+mid<seg[root].lis[mid].val){
					r=mid;
				}
				else{
					l=mid+1;
				}
			}
			ans+=l;
		}
		return ans;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		ans=query(x,root<<1,left,mid,ans);
		return query(x,root<<1|1,mid+1,right,ans);
	}
	return query(x,root<<1|1,mid+1,right,ans);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		b[i]=i-b[i];
	}
	build();
	scanf("%d",&q);
	for(int t=1;t<=q;t++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int x,a;
			scanf("%d%d",&x,&a);
			a=x-a;
			b[x]=a;
			update(x,a);
		}
		else{
			int x;
			scanf("%d",&x);
			printf("%d\n",query(x));
		}
	}
	return 0;
}