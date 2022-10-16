#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
const int Inf=0x3f3f3f3f;
int n;
namespace Segment_Minn{
	int minn[Maxn<<1|5];
	void init(){
		memset(minn,0x3f,sizeof minn);
	}
	void update(int x,int a){
		minn[x+n+1]=a;
		for(int i=(x+n+1)>>1;i>0;i>>=1){
			minn[i]=std::min(minn[i<<1],minn[i<<1|1]);
		}
	}
	int query(int l,int r){
		int ans=Inf;
		for(l+=n+1,r+=n+1;l<r;l>>=1,r>>=1){
			if(l&1){
				ans=std::min(ans,minn[l++]);
			}
			if(r&1){
				ans=std::min(ans,minn[--r]);
			}
		}
		return ans;
	}
}
int las_pos[Maxn+5];
int pos_l[Maxn+5],pos_r[Maxn+5];
struct Segment_Node{
	int lson,rson;
	ll sum_k,tag_k;
	ll sum_b,tag_b;
}seg[Maxn*60+5];
int id_tot;
std::vector<int> Root[Maxn+5];
std::vector<int> t_lis[Maxn+5];
void update_tag(int root,ll k,ll b,int left,int right){
	seg[root].sum_k+=k*(right-left+1);
	seg[root].sum_b+=b*(right-left+1);
	seg[root].tag_k+=k;
	seg[root].tag_b+=b;
}
void push_up(int root,int left,int right){
	seg[root].sum_k=seg[seg[root].lson].sum_k+seg[seg[root].rson].sum_k+seg[root].tag_k*(right-left+1);
	seg[root].sum_b=seg[seg[root].lson].sum_b+seg[seg[root].rson].sum_b+seg[root].tag_b*(right-left+1);
}
void update(int &root,int l,int r,int k,int b,int left=1,int right=n){
	if(l>right||r<left){
		return;
	}
	int last=root;
	root=++id_tot;
	seg[root]=seg[last];
	if(l<=left&&r>=right){
		update_tag(root,k,b,left,right);
		return;
	}
	int mid=(left+right)>>1;
	update(seg[root].lson,l,r,k,b,left,mid);
	update(seg[root].rson,l,r,k,b,mid+1,right);
	push_up(root,left,right);
}
std::pair<ll,ll> query(int root,int l,int r,int left=1,int right=n){
	if(l>right||r<left){
		return std::make_pair(0,0);
	}
	if(l<=left&&r>=right){
		return std::make_pair(seg[root].sum_k,seg[root].sum_b);
	}
	int mid=(left+right)>>1;
	int len=std::min(r,right)-std::max(l,left)+1;
	std::pair<ll,ll> l_ans=query(seg[root].lson,l,r,left,mid),r_ans=query(seg[root].rson,l,r,mid+1,right);
	return std::make_pair(l_ans.first+r_ans.first+seg[root].tag_k*len,l_ans.second+r_ans.second+seg[root].tag_b*len);
}
int main(){
	Segment_Minn::init();
	scanf("%d",&n);
	ll ans=0;
	int all_mex=0;
	for(int i=0;i<=n;i++){
		pos_l[i]=1,pos_r[i]=0;
	}
	for(int i=1;i<=n;i++){
		int a,l,r,k;
		scanf("%d%d%d%d",&a,&l,&r,&k);
		a=(a+ans)%(n+1),l=(l+ans)%i+1,r=(r+ans)%i+1,k=(k+ans)%(n+1);
		if(l>r){
			std::swap(l,r);
		}
		if(las_pos[a]){
			Segment_Minn::update(las_pos[a],Inf);
		}
		las_pos[a]=i;
		while(las_pos[all_mex]){
			all_mex++;
		}
		Segment_Minn::update(0,all_mex);
		Segment_Minn::update(i,a);
		Root[0].push_back(Root[0].empty()?0:Root[0].back());
		t_lis[0].push_back(i);
		update(Root[0].back(),i,i,1,-(i-1));
		if(pos_l[0]<=pos_r[0]){
			pos_r[0]=i;
		}
		else{
			pos_l[0]=pos_r[0]=i;
		}
		if(pos_l[a]<=pos_r[a]){
			Root[a].push_back(Root[a].empty()?0:Root[a].back());
			update(Root[a].back(),pos_l[a],pos_r[a],-1,i-1);
			t_lis[a].push_back(i);
			while(pos_l[a]<=pos_r[a]){
				int nxt_val=Segment_Minn::query(0,pos_r[a]);
				if(nxt_val==Inf){
					nxt_val=all_mex;
				}
				int nxt_pos=std::max(las_pos[nxt_val]+1,pos_l[a]);
				Root[nxt_val].push_back(Root[nxt_val].empty()?0:Root[nxt_val].back());
				t_lis[nxt_val].push_back(i);
				update(Root[nxt_val].back(),nxt_pos,pos_r[a],1,-(i-1));
				if(pos_l[nxt_val]>pos_r[nxt_val]){
					pos_l[nxt_val]=nxt_pos;
					pos_r[nxt_val]=pos_r[a];
				}
				else{
					pos_r[nxt_val]=pos_r[a];
				}
				pos_r[a]=nxt_pos-1;
			}
		}
		int pos=std::upper_bound(t_lis[k].begin(),t_lis[k].end(),r)-t_lis[k].begin()-1;
		if(pos<0){
			ans=0;
		}
		else{
			std::pair<ll,ll> t_ans=query(Root[k][pos],l,r);
			ans=t_ans.first*r+t_ans.second;
		}
		printf("%lld\n",ans);
	}
	return 0;
}