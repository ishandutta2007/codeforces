#include<bits/stdc++.h>
using namespace std;
#define N 200010
const int MINF=0xc0c0c0c0;
int n;
long long v;
int a[N],t[N],id[N],dp[N],p[N],Lid[N],Rid[N];
bool cmp(int x,int y){
	return a[x]<a[y];
}
struct BIT{
	int bit[N];
	void add(int i,int x){
		while (i>0){
			bit[i]=max(bit[i],x);
			i-=i&-i;
		}
	}
	int query(int i){
		int res=MINF;
		while (i<N){
			res=max(res,bit[i]);
			i+=i&-i;
		}
		return res;
	}
	void clear(int i){
		while (i>0){
			bit[i]=MINF;
			i-=i&-i;
		}
	}
	void init(){
		memset(bit,192,sizeof(bit));
	}
}LT,RT;
void CDQ(int l,int r){
	if (l==r){
		return;
	}
	int mid=(l+r)>>1,i,j;
	CDQ(l,mid);
	
	for (i=l;i<=r;i++){
		p[i]=i;
	}
	sort(p+l,p+mid+1,cmp);
	sort(p+mid+1,p+r+1,cmp);
	
	i=l,j=mid+1;
	while (i<=mid && j<=r){
		if (a[p[i]]<=a[p[j]]){
			LT.add(Lid[p[i]],dp[p[i]]+1);
			i++;
		}else{
			dp[p[j]]=max(dp[p[j]],LT.query(Lid[p[j]]));
			j++;
		}
	}
	while (j<=r){
		dp[p[j]]=max(dp[p[j]],LT.query(Lid[p[j]]));
		j++;
	}
	
	reverse(p+l,p+mid+1);
	reverse(p+mid+1,p+r+1);
	
	i=l,j=mid+1;
	while (i<=mid && j<=r){
		if (a[p[i]]>=a[p[j]]){
			RT.add(N-1-Rid[p[i]],dp[p[i]]+1);
			i++;
		}else{
			dp[p[j]]=max(dp[p[j]],RT.query(N-1-Rid[p[j]]));
			j++;
		}
	}
	while (j<=r){
		dp[p[j]]=max(dp[p[j]],RT.query(N-1-Rid[p[j]]));
		j++;
	}
	
	for (i=l;i<=mid;i++){
		LT.clear(Lid[i]);
		RT.clear(N-1-Rid[i]);
	}
	
	CDQ(mid+1,r);
}
long long Le[N],Ri[N];
int main(){
	int i;
	scanf("%d%lld",&n,&v);
	for (i=1;i<=n;i++){
		scanf("%d",&t[i]);
	}
	for (i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (t[i]*v>=abs(a[i])){
			dp[i]=1;
		}else{
			dp[i]=MINF;
		}
		Le[i]=a[i]-t[i]*v;
		Ri[i]=a[i]+t[i]*v;
	}
	sort(Le+1,Le+n+1);
	sort(Ri+1,Ri+n+1);
	for (i=1;i<=n;i++){
		Lid[i]=lower_bound(Le+1,Le+n+1,a[i]-t[i]*v)-Le;
		Rid[i]=lower_bound(Ri+1,Ri+n+1,a[i]+t[i]*v)-Ri;
	}
	
	LT.init();
	RT.init();
	CDQ(1,n);
	
	int Ans=0;
	for (i=1;i<=n;i++){
		Ans=max(Ans,dp[i]);
	}
	printf("%d\n",Ans);
	return 0;
}