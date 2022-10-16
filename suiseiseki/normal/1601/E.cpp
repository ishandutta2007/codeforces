#include <vector>
#include <cstdio>
#include <cassert>
#include <algorithm>
typedef long long ll;
const int Maxn=500000;
int n,q,k;
int len;
int a[Maxn+5];
struct Segment{
	int l,r;
	ll ans;
}qu[Maxn+5];
std::vector<int> q_lis[Maxn+5];
struct Segment_Node{
	int lson,rson;
	ll sum,lazy;
}seg[Maxn<<2|5];
int Root[Maxn+5];
int id_tot;
void update_tag(int &root,int left,int right,ll a){
	if(root==0){
		root=++id_tot;
	}
	seg[root].sum+=1ll*(right-left+1)*a,seg[root].lazy+=a;
}
void push_down(int root,int left,int right){
	if(seg[root].lazy){
		int mid=(left+right)>>1;
		update_tag(seg[root].lson,left,mid,seg[root].lazy);
		update_tag(seg[root].rson,mid+1,right,seg[root].lazy);
		seg[root].lazy=0;
	}
}
void push_up(int root){
	seg[root].sum=seg[seg[root].lson].sum+seg[seg[root].rson].sum;
}
void update(int &root,int l,int r,int a,int left=0,int right=len){
	if(l>right||r<left){
		return;
	}
	if(root==0){
		root=++id_tot;
	}
	if(l<=left&&r>=right){
		update_tag(root,left,right,a);
		return;
	}
	push_down(root,left,right);
	int mid=(left+right)>>1;
	update(seg[root].lson,l,r,a,left,mid);
	update(seg[root].rson,l,r,a,mid+1,right);
	push_up(root);
}
ll query(int root,int l,int r,int left=0,int right=len){
	if(l>right||r<left){
		return 0;
	}
	if(l<=left&&r>=right){
		return seg[root].sum;
	}
	int mid=(left+right)>>1;
	push_down(root,left,right);
	return query(seg[root].lson,l,r,left,mid)+query(seg[root].rson,l,r,mid+1,right);
}
std::vector<std::pair<int,int> > st[Maxn+5];
int qu_min[Maxn+5],qu_min_f,qu_min_t;
int b[Maxn+5];
int main(){
	scanf("%d%d%d",&n,&q,&k);
	len=(n-1)/k;
	for(int i=0;i<k;i++){
		st[i].push_back(std::make_pair(0,len+1));
	}
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&qu[i].l,&qu[i].r);
		qu[i].l--,qu[i].r--;
		q_lis[qu[i].l].push_back(i);
	}
	qu_min_f=1,qu_min_t=0;
	for(int i=n-1;i>=0;i--){
		while(qu_min_f<=qu_min_t&&qu_min[qu_min_f]-i>=k){
			qu_min_f++;
		}
		while(qu_min_f<=qu_min_t&&a[qu_min[qu_min_t]]>=a[i]){
			qu_min_t--;
		}
		qu_min[++qu_min_t]=i;
		b[i]=a[qu_min[qu_min_f]];
		if(i+k<n){
			int add_val=std::min(b[i+1],a[i]);
			update(Root[i%k],i/k+1,i/k+1,add_val);
			while(add_val<st[i%k].back().first){
				update(Root[i%k],st[i%k].back().second,st[i%k][(int)st[i%k].size()-2].second-1,add_val-st[i%k].back().first);
				st[i%k].pop_back();
			}
			st[i%k].push_back(std::make_pair(add_val,i/k+1));
		}
		for(int j:q_lis[i]){
			qu[j].ans=query(Root[i%k],i/k+1,(qu[j].r-(i%k))/k)+a[i];
		}
	}
	for(int i=1;i<=q;i++){
		printf("%lld\n",qu[i].ans);
	}
	return 0;
}