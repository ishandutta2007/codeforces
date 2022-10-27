#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
int n,s1,s2;
int a[N];
int mn[20][N], mx[20][N], lg[N];
void rmq_init() {
	lg[1] = 0;
	for(int i=2;i<N;i++){
		lg[i]=lg[i/2]+1;
	}
	for(int i=1;i<=n;i++){
		mx[0][i]=mn[0][i]=a[i];
	}
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
			mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
		}
	}
}
int queMin(int l, int r) {
	int k=lg[r-l+1];
	return min(mn[k][l], mn[k][r-(1<<k)+1]);
}
int queMax(int l, int r) {
	int k=lg[r-l+1];
	return max(mx[k][l], mx[k][r-(1<<k)+1]);
}
int rig[N], dp[N];
bool chk(int x) {
	for(int i=1;i<=n;i++) {
		int l=i,r=n+1;
		while(r-l>1){
			int mid=(l+r)>>1;
			//printf("mid=%d, %d, %d\n",mid,queMax(i,mid)-a[i],a[i]-queMin(i,mid) );
			if(queMax(i,mid)-a[i]<=x && a[i]-queMin(i,mid)<=x) l=mid;
			else r=mid;
		}
		rig[i]=l;
		//printf("rig[%d]=%d\n", i,rig[i]);
	}
	//for(int i=1;i<=n;i++) printf("%d ", rig[i]); printf("\n");

	{
		int mxrig=0;
		for(int i=1;i<=n;i++) dp[i]=0;
		dp[1]=1; mxrig=rig[1];
		for(int i=2;i<=n;i++){
			if(mxrig>=i){
				dp[i]=1; mxrig=max(mxrig, rig[i]);
			}
		}
		if(dp[n]) return true;
	}

	{
		int mxrig=0;
		for(int i=1;i<=n;i++) dp[i]=0;
		dp[2]=1; mxrig=rig[2];
		for(int i=3;i<=n;i++){
			if(mxrig>=i){
				dp[i]=1; mxrig=max(mxrig, rig[i]);
			}
		}
		if(dp[n]) return true;
	}
	return false;
}
int main() {
	scanf("%d%d%d",&n,&s1,&s2);
	a[1]=s1, a[2]=s2; 
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i+2]);
	n+=2;
	rmq_init();
	int l=abs(a[2]-a[1])-1, r=1e9;
//chk(2); return 0;
	while(r-l>1){
		int mid=(l+r)>>1;
		if(chk(mid)) r=mid; else l=mid;
	}
	cout << r << endl;
}