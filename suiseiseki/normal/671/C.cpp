#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
const int Maxn=200000;
int n;
int a[Maxn+5];
ll h[Maxn+5];
vector<int> v[Maxn+5];
int maxv[Maxn<<2|5],minv[Maxn<<2|5],setv[Maxn<<2|5];
ll sumv[Maxn<<2|5];
void push_up(int root){
	maxv[root]=max(maxv[root<<1],maxv[root<<1|1]);
	minv[root]=min(minv[root<<1],minv[root<<1|1]);
	sumv[root]=sumv[root<<1]+sumv[root<<1|1];
}
void push_down(int root,int left,int right){
	if(setv[root]){
		int mid=(left+right)>>1;
		setv[root<<1]=maxv[root<<1]=minv[root<<1]=setv[root];
		sumv[root<<1]=1ll*setv[root]*(mid-left+1);
		setv[root<<1|1]=maxv[root<<1|1]=minv[root<<1|1]=setv[root];
		sumv[root<<1|1]=1ll*setv[root]*(right-mid);
		setv[root]=0;
	}
}
void build(int root=1,int left=1,int right=n){
	if(left==right){
		maxv[root]=minv[root]=sumv[root]=left;
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	push_up(root);
}
void update(int l,int r,int w,int root=1,int left=1,int right=n){
	if(l>right||r<left){
		return;
	}
	if(minv[root]>=w){
		return;
	}
	if(l<=left&&r>=right&&maxv[root]<w){
		setv[root]=maxv[root]=minv[root]=w;
		sumv[root]=1ll*w*(right-left+1);
		return;
	}
	int mid=(left+right)>>1;
	push_down(root,left,right);
	update(l,r,w,root<<1,left,mid);
	update(l,r,w,root<<1|1,mid+1,right);
	push_up(root);
}
int main(){
	scanf("%d",&n);
	int lim=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		lim=max(lim,a[i]);
		for(int j=1;j*j<=a[i];j++){
			if(a[i]%j!=0){
				continue;
			}
			v[j].push_back(i);
			if(j*j!=a[i]){
				v[a[i]/j].push_back(i);
			}
		}
	}
	build(1);
	for(int i=lim;i>0;i--){
		h[i]=1ll*n*n-sumv[1]+n;
		if((int)v[i].size()<=1){
			continue;
		}
		int m=v[i].size();
		update(v[i][1]+1,n,n+1);
		update(v[i][0]+1,v[i][1],v[i][m-1]);
		update(1,v[i][0],v[i][m-2]);
	}
	h[0]=1ll*n*n-sumv[1]+n;
	ll ans=0;
	for(int i=1;i<=lim;i++){
		ans+=i*(h[i]-h[i-1]);
	}
	printf("%lld\n",ans);
    return 0;
}