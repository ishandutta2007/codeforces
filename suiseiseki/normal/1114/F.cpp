#include <cstdio>
#define Maxn 400000
#define Mod 1000000007
#define ll long long
struct Segment_Node{
	int left,right;
	int val;
	int lazy_v;
	ll lazy_p;
	ll p;
}seg[Maxn<<2|5];
bool np[305];
int p[305];
int p_len;
int ins[305];
int ksm(int x,int y){
	int ans=1;
	while(y){
		if(y&1){
			ans=(int)((ll)ans*x%Mod);
		}
		y>>=1;
		x=(int)((ll)x*x%Mod);
	}
	return ans;
}
void init(){
	np[0]=np[1]=1;
	for(int i=2;i<=300;i++){
		if(!np[i]){
			p[++p_len]=i;
			ins[p_len]=(int)((ll)ksm(i,Mod-2)*(i-1)%Mod);
			for(int j=i*i;j<=300;j+=i){
				np[j]=1;
			}
		}
	}
}
int a[Maxn+5];
void build(int root,int left,int right){
	seg[root].left=left;
	seg[root].right=right;
	seg[root].lazy_v=1;
	seg[root].lazy_p=0;
	if(left==right){
		seg[root].val=a[left];
		seg[root].p=0;
		for(int i=1;i<=p_len;i++){
			if(a[left]%p[i]==0){
				seg[root].p|=(1ll<<(i-1));
			}
		}
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	seg[root].val=(int)((ll)seg[root<<1].val*seg[root<<1|1].val%Mod);
	seg[root].p=seg[root<<1].p|seg[root<<1|1].p;
}
void push(int root,int val,ll p){
	seg[root].val=(int)((ll)seg[root].val*ksm(val,seg[root].right-seg[root].left+1)%Mod);
	seg[root].p|=p;
	seg[root].lazy_v=(int)((ll)seg[root].lazy_v*val%Mod);
	seg[root].lazy_p|=p;
}
void push_down(int root){
	if(seg[root].lazy_v!=1||seg[root].lazy_p!=0){
		push(root<<1,seg[root].lazy_v,seg[root].lazy_p);
		push(root<<1|1,seg[root].lazy_v,seg[root].lazy_p);
		seg[root].lazy_v=1;
		seg[root].lazy_p=0;
	}
}
void update(int root,int left,int right,int val,ll p){
	if(seg[root].left==left&&seg[root].right==right){
		push(root,val,p);
		return;
	}
	push_down(root);
	root<<=1;
	if(left<=seg[root].right){
		if(right<=seg[root].right){
			update(root,left,right,val,p);
		}
		else{
			update(root,left,seg[root].right,val,p);
		}
	}
	root|=1;
	if(right>=seg[root].left){
		if(left>=seg[root].left){
			update(root,left,right,val,p);
		}
		else{
			update(root,seg[root].left,right,val,p);
		}
	}
	root>>=1;
	seg[root].val=(int)((ll)seg[root<<1].val*seg[root<<1|1].val%Mod);
	seg[root].p=seg[root<<1].p|seg[root<<1|1].p;
}
int query_v(int root,int left,int right){
	if(seg[root].left==left&&seg[root].right==right){
		return seg[root].val;
	}
	int val=1;
	push_down(root);
	root<<=1;
	if(left<=seg[root].right){
		if(right<=seg[root].right){
			val=(int)((ll)val*query_v(root,left,right)%Mod);
		}
		else{
			val=(int)((ll)val*query_v(root,left,seg[root].right)%Mod);
		}
	}
	root|=1;
	if(right>=seg[root].left){
		if(left>=seg[root].left){
			val=(int)((ll)val*query_v(root,left,right)%Mod);
		}
		else{
			val=(int)((ll)val*query_v(root,seg[root].left,right)%Mod);
		}
	}
	return val;
}
ll query_p(int root,int left,int right){
	if(seg[root].left==left&&seg[root].right==right){
		return seg[root].p;
	}
	ll p=0;
	push_down(root);
	root<<=1;
	if(left<=seg[root].right){
		if(right<=seg[root].right){
			p|=query_p(root,left,right);
		}
		else{
			p|=query_p(root,left,seg[root].right);
		}
	}
	root|=1;
	if(right>=seg[root].left){
		if(left>=seg[root].left){
			p|=query_p(root,left,right);
		}
		else{
			p|=query_p(root,seg[root].left,right);
		}
	}
	return p;
}
char qu[10];
int main(){
	init();
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	int l,r,x;
	ll P;
	int ans;
	while(q--){
		scanf("%s",qu);
		if((*qu)=='T'){
			scanf("%d%d",&l,&r);
			ans=query_v(1,l,r);
			P=query_p(1,l,r);
			for(int i=0;i<p_len;i++){
				if(P&(1ll<<i)){
					ans=(int)((ll)ans*ins[i+1]%Mod);
				}
			}
			printf("%d\n",ans);
		}
		else{
			scanf("%d%d%d",&l,&r,&x);
			P=0;
			for(int i=1;i<=p_len;i++){
				if(x%p[i]==0){
					P|=(1ll<<(i-1));
				}
			}
			update(1,l,r,x,P);
		}
	}
	return 0;
}