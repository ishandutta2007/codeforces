#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

long long a[100000],org[100000],b[100000];
long long tree[262144],dp[100000]={0},pre[100000];
void buildtree(int i,int l,int r){
	if(l+1==r){
		tree[i]=-1;
		return;
	}
	int mid=(l+r)>>1;
	buildtree(i*2,l,mid);
	buildtree(i*2+1,mid,r);
	tree[i]=-1;
	return;
}
int better(int x,int y){
	if(x==-1)return y;
	if(y==-1)return x;
	return (dp[x]>dp[y])?x:y;
}
int query(int i,int l,int r,int l0,int r0){
	if(l>=l0 && r<=r0)
		return tree[i];
	int mid=(l+r)>>1;
	int ans=-1;
	if(mid>l0)ans=better(ans,query(i*2,l,mid,l0,r0));
	if(mid<r0)ans=better(ans,query(i*2+1,mid,r,l0,r0));
	return ans;
}
void change(int i,int l,int r,int x,int y){
	if(l+1==r){
		tree[i]=y;
		return;
	}
	int mid=(l+r)>>1;
	if(x<mid)change(i*2,l,mid,x,y);else change(i*2+1,mid,r,x,y);
	tree[i]=better(tree[i*2],tree[i*2+1]);
	return;
}
int main(){
	int n,d;scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++)scanf("%I64d",&a[i]);
	memcpy(b,a,sizeof(b));
	sort(b,b+n);
	buildtree(1,0,n);
	dp[0]=1;pre[0]=-1;
	int t=lower_bound(b,b+n,a[0])-b;
	change(1,0,n,t,0);
	for(int i=1;i<n;i++){
		int u=lower_bound(b,b+n,a[i]-d+1)-b;
		int tu;
		if(u==0)tu=-1;else tu=query(1,0,n,0,u);
		int v=lower_bound(b,b+n,a[i]+d)-b;
		int tv;
		if(v==n)tv=-1;else tv=query(1,0,n,v,n);
		if(tu==-1 && tv==-1){
			dp[i]=1;pre[i]=-1;
		}
		if(tu==better(tu,tv)){
			dp[i]=dp[tu]+1;pre[i]=tu;
		}else{
			dp[i]=dp[tv]+1;pre[i]=tv;
		}
		int t=lower_bound(b,b+n,a[i])-b;
		change(1,0,n,t,i);
	}
//	for(int i=0;i<n;i++)printf("%I64d %I64d\n",dp[i],pre[i]);
	int max=0;
	for(int i=1;i<n;i++)
		if(dp[i]>dp[max])max=i;
	printf("%d\n",dp[max]);
	int top=0;
	for(int now=max;now!=-1;now=pre[now]){
		org[top++]=now;
	}
	for(int i=top-1;i>0;i--)printf("%d ",org[i]+1);printf("%d\n",org[0]+1);
	return 0;
}