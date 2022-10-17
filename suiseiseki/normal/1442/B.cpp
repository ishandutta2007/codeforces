#include <cstdio>
const int Maxn=200000;
const int Mod=998244353;
int n,k;
int a[Maxn+5];
int pos[Maxn+5];
int b[Maxn+5];
bool vis[Maxn+5];
/*int f[Maxn<<2|5];
void build(int root=1,int left=1,int right=n){
	f[root]=0;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
}
int query_l(int l,int r,int root=1,int left=1,int right=n){
	if(l>right||r<left||f[root]==0){
		return 0;
	}
	if(left==right){
		return left;
	}
	int mid=(left+right)>>1;
	int ans=query_l(l,r,root<<1,left,mid);
	if(ans==0){
		ans=query_l(l,r,root<<1|1,mid+1,right);
	}
	return ans;
}
int query_r(int l,int r,int root=1,int left=1,int right=n){
	if(l>right||r<left||f[root]==0){
		return n+1;
	}
	if(left==right){
		return left;
	}
	int mid=(left+right)>>1;
	int ans=query_r(l,r,root<<1|1,mid+1,right);
	if(ans==n+1){
		ans=query_r(l,r,root<<1|1,left,mid);
	}
	return ans;
}
void update(int x,int a,int root=1,int left=1,int right=n){
	f[root]+=a;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		update(x,a,root<<1,left,mid);
	}
	else{
		update(x,a,root<<1|1,mid+1,right);
	}
}*/
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
//		build();
		vis[0]=vis[n+1]=1;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			pos[a[i]]=i;
			vis[i]=0;
		}
		for(int i=1;i<=k;i++){
			scanf("%d",&b[i]);
		}
		int ans=1;
		for(int i=k;i>0;i--){
			int num=0;
			if(!vis[pos[b[i]]-1]){
				num++;
			}
			if(!vis[pos[b[i]]+1]){
				num++;
			}
			ans=1ll*ans*num%Mod;
			vis[pos[b[i]]]=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}