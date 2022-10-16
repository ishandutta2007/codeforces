#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
bool np[Maxn+5];
int phi[Maxn+5];
int p[Maxn+5],p_len;
void init(){
	np[0]=np[1]=1;
	phi[1]=1;
	for(int i=2;i<=Maxn;i++){
		if(!np[i]){
			p[++p_len]=i;
			phi[i]=i-1;
		}
		for(int j=1;1ll*i*p[j]<=Maxn;j++){
			int x=i*p[j];
			np[x]=1;
			if(i%p[j]==0){
				phi[x]=phi[i]*p[j];
				break;
			}
			phi[x]=phi[i]*(p[j]-1);
		}
	}
}
std::vector<int> lis[Maxn+5];
namespace Segment_Tree{
	struct Segment_Node{
		ll minn[18],lazy;
	}seg[Maxn<<2|5];
	void update_tag(int root,ll a){
		for(int i=2;i<18;i++){
			seg[root].minn[i]+=a;
		}
		seg[root].lazy+=a;
	}
	void push_up(int root){
		for(int i=2;i<18;i++){
			seg[root].minn[i]=std::min(seg[root<<1].minn[i],seg[root<<1|1].minn[i])+seg[root].lazy;
		}
	}
	void modify(int x,ll *a,int root=1,int left=1,int right=Maxn,ll sum_lazy=0){
		if(left==right){
			for(int i=2;i<18;i++){
				seg[root].minn[i]=a[i-1]-sum_lazy;
			}
			return;
		}
		int mid=(left+right)>>1;
		if(x<=mid){
			modify(x,a,root<<1,left,mid,sum_lazy+seg[root].lazy);
		}
		else{
			modify(x,a,root<<1|1,mid+1,right,sum_lazy+seg[root].lazy);
		}
		push_up(root);
	}
	void update(int l,int r,int a,int root=1,int left=1,int right=Maxn){
		if(l>right||r<left){
			return;
		}
		if(l<=left&&r>=right){
			update_tag(root,a);
			return;
		}
		int mid=(left+right)>>1;
		update(l,r,a,root<<1,left,mid);
		update(l,r,a,root<<1|1,mid+1,right);
		push_up(root);
	}
	void query(int l,int r,ll *a,int root=1,int left=1,int right=Maxn,ll sum_lazy=0){
		if(l>right||r<left){
			return;
		}
		if(l<=left&&r>=right){
			for(int i=2;i<18;i++){
				a[i]=std::min(a[i],seg[root].minn[i]+sum_lazy);
			}
			return;
		}
		int mid=(left+right)>>1;
		query(l,r,a,root<<1,left,mid,sum_lazy+seg[root].lazy);
		query(l,r,a,root<<1|1,mid+1,right,sum_lazy+seg[root].lazy);
	}
}
ll f[Maxn+5][18];
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(k>=18){
		printf("%d\n",n);
		return;
	}
	printf("%lld\n",f[n][k]);
}
int main(){
	init();
	memset(f,0x3f,sizeof f);
	f[1][1]=1;
	for(int i=1;i<=Maxn;i++){
		for(int j=i;j<=Maxn;j+=i){
			lis[j].push_back(i);
		}
	}
	for(int i=2;i<=Maxn;i++){
		Segment_Tree::modify(i,f[i-1]);
		for(int j:lis[i]){
			Segment_Tree::update(1,j,phi[i/j]);
		}
		f[i][1]=f[i-1][1]+i;
		Segment_Tree::query(1,i,f[i]);
	}
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}