#include <vector>
#include <cstdio>
#include <algorithm>
const int Maxn=500000;
int n;
int a[Maxn+5];
int lis[Maxn+5],lis_len;
int pos_l,pos_r;
int l_x[Maxn+5],r_x[Maxn+5];
struct Segment_Node{
	int minn,lazy;
}seg[Maxn<<2|5];
void update_tag(int root,int a){
	seg[root].lazy+=a;
	seg[root].minn+=a;
}
void push_down(int root){
	if(seg[root].lazy){
		update_tag(root<<1,seg[root].lazy);
		update_tag(root<<1|1,seg[root].lazy);
		seg[root].lazy=0;
	}
}
void push_up(int root){
	seg[root].minn=std::min(seg[root<<1].minn,seg[root<<1|1].minn);
}
void build(int root=1,int left=pos_r,int right=lis_len+1){
	seg[root].lazy=0;
	if(left==right){
		seg[root].minn=lis_len-left+1;
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	push_up(root);
}
void update(int l,int r,int a,int root=1,int left=pos_r,int right=lis_len+1){
	if(l>right||r<left||l>r){
		return;
	}
	if(l<=left&&r>=right){
		update_tag(root,a);
		return;
	}
	push_down(root);
	int mid=(left+right)>>1;
	update(l,r,a,root<<1,left,mid);
	update(l,r,a,root<<1|1,mid+1,right);
	push_up(root);
}
std::vector<int> t[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=0;i<=n+1;i++){
		t[i].clear();
	}
	lis_len=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){
			lis[++lis_len]=i;
		}
	}
	pos_l=(lis_len>>1),pos_r=lis_len-(lis_len>>1)+1;
	for(int i=1;i<=n;i++){
		l_x[i]=0,r_x[i]=lis_len+1;
	}
	for(int i=1,j=1;i<=n;i++){
		if(a[i]>0){
			while(j<=lis_len&&lis[j]<i){
				j++;
			}
			if(j>lis_len||j==1){
				continue;
			}
			if(j>=pos_r){
				r_x[a[i]]=std::min(r_x[a[i]],std::max(j,pos_r));
			}
			else{
				l_x[a[i]]=std::max(l_x[a[i]],std::min(j-1,pos_l));
			}
		}
	}
	for(int i=1;i<=n;i++){
		t[l_x[i]].push_back(i);
	}
	build();
	int sum=n;
	for(int i=1;i<=n;i++){
		if(l_x[i]==0){
			sum--;
			update(r_x[i]+1,lis_len+1,1);
		}
	}
	int ans=sum+seg[1].minn;
	for(int i=1;i<=pos_l;i++){
		sum++;
		for(int j=0;j<(int)t[i].size();j++){
			sum--;
			update(r_x[t[i][j]]+1,lis_len+1,1);
		}
		ans=std::min(ans,sum+seg[1].minn);
	}
	ans=std::min(ans,lis_len>>1);
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}