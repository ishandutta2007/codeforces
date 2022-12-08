#include<bits/stdc++.h>
using namespace std;

const int N=400005,M=N*21;
int n,q,k,a[N],b[N<<2],u[N],v[N],root1[N],root2[N],dp1[N],dp2[N],un[N];
int c1[M][2],c2[M][2],p1[M],p2[M],cnt1,cnt2;

inline int get1(int k,int l,int r,int x,int y){
	if(!k) return 0;
	if(l>=x&&r<=y)return p1[k];
	int mid=l+r>>1,res=0;
	if(x<=mid) res=max(res,get1(c1[k][0],l,mid,x,y));
	if(y>mid) res=max(res,get1(c1[k][1],mid+1,r,x,y));
	return res;
}
inline int get2(int k,int l,int r,int x,int y){
	if(!k) return 0;
	if(l>=x&&r<=y)return p2[k];
	int mid=l+r>>1,res=0;
	if(x<=mid) res=max(res,get2(c2[k][0],l,mid,x,y));
	if(y>mid) res=max(res,get2(c2[k][1],mid+1,r,x,y));
	return res;
}
inline void change1(int &k,int t,int l,int r,int x,int y){
	k=++cnt1;
	p1[k]=max(p1[t],y);c1[k][0]=c1[t][0];c1[k][1]=c1[t][1];
	if(l==r) return;
	int mid=l+r>>1;
	if(x<=mid) change1(c1[k][0],c1[t][0],l,mid,x,y);
	else change1(c1[k][1],c1[t][1],mid+1,r,x,y);
}
inline void change2(int &k,int t,int l,int r,int x,int y){
	k=++cnt2;
	p2[k]=max(p2[t],y);c2[k][0]=c2[t][0];c2[k][1]=c2[t][1];
	if(l==r) return;
	int mid=l+r>>1;
	if(x<=mid) change2(c2[k][0],c2[t][0],l,mid,x,y); else change2(c2[k][1],c2[t][1],mid+1,r,x,y);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	for(int i=1;i<=q;i++) scanf("%d%d",&u[i],&v[i]),b[i+n]=v[i];
	sort(b+1,b+n+q+1);
	for(int i=1;i<=n+q;i++) if(b[i]!=b[i-1]||i==1) b[++k]=b[i];
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+k+1,a[i])-b;
	for(int i=1;i<=q;i++) v[i]=lower_bound(b+1,b+k+1,v[i])-b;
	for(int i=1;i<=n;i++){
		if(a[i]>1) dp1[i]=get1(root1[i-1],1,k,1,a[i]-1);
		dp1[i]++;
		change1(root1[i],root1[i-1],1,k,a[i],dp1[i]);
	//	printf("%d ",dp1[i]);
	}//puts("");
	for(int i=n;i;i--){
		if(a[i]<k) dp2[i]=get2(root2[i+1],1,k,a[i]+1,k);
		dp2[i]++;
		change2(root2[i],root2[i+1],1,k,a[i],dp2[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dp1[i]+dp2[i]-1);
	for(int i=1;i<=n;i++){
		if(dp1[i]+dp2[i]!=ans+1) continue;
		if(!un[dp1[i]]) un[dp1[i]]=1; else un[dp1[i]]=2;
	}
//	printf("%d\n",ans);
	for(int _=1;_<=q;_++){
		int i=u[_],x=v[_],res=ans,t=0;
		if(dp1[i]+dp2[i]==ans+1&&un[dp1[i]]==1) res--;
//		printf("%d\n",res);
		if(x>1) t+=get1(root1[i-1],1,k,1,x-1);
//		printf("%d ",t);
		if(x<k) t+=get2(root2[i+1],1,k,x+1,k);
//		printf("%d ",t);
		res=max(res,t+1);
		printf("%d\n",res);
	}
	return 0;
}
/*
4 4
1 2 3 4
1 1
1 4
4 3
4 5
*/