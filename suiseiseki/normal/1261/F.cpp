#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Mod=998244353;
const int Maxn=100;
const ll Inf=(1ll<<60)-1;
int n_a,n_b;
struct Segment{
	ll left,right;
}a[Maxn+5],b[Maxn+5];
vector<pair<ll,ll> > tmp_a[65],tmp_b[65];
vector<pair<ll,ll> > ans;
struct Segment_Node{
	int lson,rson;
}seg[Maxn*1000+5];
int id_tot,Root;
int new_node(){
	id_tot++;
	seg[id_tot].lson=seg[id_tot].rson=0;
	return id_tot;
}
void insert_a(ll l,ll r,int &root=Root,ll left=0,ll right=Inf,int dep=0){
	if(l>right||r<left){
		return;
	}
	if(root==0){
		root=new_node();
		tmp_a[dep].push_back(make_pair(left,right));
	}
	if(l<=left&&r>=right){
		return;
	}
	ll mid=(left+right)>>1;
	insert_a(l,r,seg[root].lson,left,mid,dep+1);
	insert_a(l,r,seg[root].rson,mid+1,right,dep+1);
}
void insert_b(ll l,ll r,ll left=0,ll right=Inf,int dep=0){
	if(l>right||r<left){
		return;
	}
	if(l<=left&&r>=right){
		tmp_b[dep].push_back(make_pair(left,right));
		return;
	}
	ll mid=(left+right)>>1;
	insert_b(l,r,left,mid,dep+1);
	insert_b(l,r,mid+1,right,dep+1);
}
void work(){
	id_tot=0;
	Root=0;
	for(int i=0;i<=60;i++){
		tmp_a[i].clear();
		tmp_b[i].clear();
	}
	for(int i=1;i<=n_a;i++){
		insert_a(a[i].left,a[i].right);
	}
	for(int i=1;i<=n_b;i++){
		insert_b(b[i].left,b[i].right);
	}
	for(int i=1;i<=60;i++){
		for(int j=0;j<(int)tmp_a[i].size();j++){
			for(int k=0;k<(int)tmp_b[i].size();k++){
				ll low=tmp_b[i][k].first^tmp_b[i][k].second;
				ans.push_back(make_pair((tmp_a[i][j].first^tmp_b[i][k].first)&(~low),(tmp_a[i][j].first^tmp_b[i][k].first)|low));
			}
		}
	}
}
ll find_sum(ll l,ll r){
	if((l+r)&1){
		return ((r-l+1)/2)%Mod*((l+r)%Mod)%Mod;
	}
	return ((l+r)/2)%Mod*((r-l+1)%Mod)%Mod;
}
int main(){
	scanf("%d",&n_a);
	for(int i=1;i<=n_a;i++){
		scanf("%lld%lld",&a[i].left,&a[i].right);
	}
	scanf("%d",&n_b);
	for(int i=1;i<=n_b;i++){
		scanf("%lld%lld",&b[i].left,&b[i].right);
	}
	work();
	swap(n_a,n_b);
	swap(a,b);
	work();
	sort(ans.begin(),ans.end());
	ll answer=0,l=0,r=-1;
	for(int i=0;i<(int)ans.size();i++){
		if(ans[i].first>r){
			answer=(answer+find_sum(l,r))%Mod;
			l=ans[i].first;
			r=ans[i].second;
		}
		else{
			r=max(r,ans[i].second);
		}
	}
	answer=(answer+find_sum(l,r))%Mod;
	printf("%lld\n",answer);
	return 0;
}