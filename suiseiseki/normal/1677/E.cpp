#include <vector>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
const int Maxq=1000000;
int n,m;
int a[Maxn+5],q[Maxn+5];
int pos_l[Maxn+5],pos_r[Maxn+5];
int st[Maxn+5],st_pos[Maxn+5],st_top;
struct Operation{
	int l,r,v;
	Operation(int _l=0,int _r=0,int _v=0){
		l=_l,r=_r,v=_v;
	}
};
std::vector<Operation> op_lis[Maxn+5];
int max_r[Maxn+5];
struct Segment_Node{
	ll s_val,add_s;
	ll c_val,add_c;
	int c_s;
}seg[Maxn<<2|5];
void update_tag_c_s(int root,int c_s){
	seg[root].s_val+=1ll*c_s*seg[root].c_val;
	seg[root].add_s+=1ll*c_s*seg[root].add_c;
	seg[root].c_s+=c_s;
}
void update_tag_add_s(int root,int left,int right,ll add_s){
	seg[root].s_val+=1ll*(right-left+1)*add_s;
	seg[root].add_s+=add_s;
}
void update_tag_add_c(int root,int left,int right,ll add_c){
	seg[root].c_val+=1ll*(right-left+1)*add_c;
	seg[root].add_c+=add_c;
}
void push_down(int root,int left,int right){
	int mid=(left+right)/2;
	if(seg[root].c_s){
		update_tag_c_s(root<<1,seg[root].c_s),update_tag_c_s(root<<1|1,seg[root].c_s);
		seg[root].c_s=0;
	}
	if(seg[root].add_s){
		update_tag_add_s(root<<1,left,mid,seg[root].add_s),update_tag_add_s(root<<1|1,mid+1,right,seg[root].add_s);
		seg[root].add_s=0;
	}
	if(seg[root].add_c){
		update_tag_add_c(root<<1,left,mid,seg[root].add_c),update_tag_add_c(root<<1|1,mid+1,right,seg[root].add_c);
		seg[root].add_c=0;
	}
}
void push_up(int root){
	seg[root].s_val=seg[root<<1].s_val+seg[root<<1|1].s_val,seg[root].c_val=seg[root<<1].c_val+seg[root<<1|1].c_val;
}
void update(int l,int r,int a,int root=1,int left=1,int right=n){
	if(l>right||r<left||l>r){
		return;
	}
	if(l<=left&&r>=right){
		update_tag_add_c(root,left,right,a);
		return;
	}
	push_down(root,left,right);
	int mid=(left+right)/2;
	update(l,r,a,root<<1,left,mid),update(l,r,a,root<<1|1,mid+1,right);
	push_up(root);
}
ll query(int l,int r,int root=1,int left=1,int right=n){
	if(l>right||r<left){
		return 0;
	}
	if(l<=left&&r>=right){
		return seg[root].s_val;
	}
	push_down(root,left,right);
	int mid=(left+right)/2;
	return query(l,r,root<<1,left,mid)+query(l,r,root<<1|1,mid+1,right);
}
std::vector<std::pair<int,int> > q_lis[Maxn+5];
ll ans[Maxq+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		q[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		q_lis[r].push_back(std::make_pair(l,i));
	}
	for(int i=1;i<=n;i++){
		while(st_top>0&&a[i]>a[st[st_top]]){
			st_pos[st[st_top]]=0;
			update(st[st_top-1]+1,max_r[a[st[st_top]]],-1);
			st_top--;
		}
		st[++st_top]=i,st_pos[i]=st_top;
		if(max_r[a[i]]>st[st_top-1]){
			update(st[st_top-1]+1,max_r[a[i]],1);
		}
		else{
			max_r[a[i]]=st[st_top-1];
		}
		for(int j=1;j*a[i]<=n;j++){
			if(q[j]>=i){
				continue;
			}
			if(st_pos[q[j*a[i]]]==0){
				max_r[j*a[i]]=std::max(max_r[j*a[i]],q[j]);
				continue;
			}
			int pos=std::min(q[j*a[i]],q[j]);
			if(max_r[j*a[i]]<pos){
				update(max_r[j*a[i]]+1,pos,1);
				max_r[j*a[i]]=pos;
			}
		}
		update_tag_c_s(1,1);
		for(std::pair<int,int> j:q_lis[i]){
			ans[j.second]=query(j.first,i);
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}