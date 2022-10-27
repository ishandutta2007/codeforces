#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
int par[N];
int n,a[N];
int pre[33][N],nex[33][N];
int L[N],R[N];
int top,stk[N];
void init(){
	top=0;
	for(int i=1;i<=n;i++){
		while(top && a[stk[top]]<=a[i]) --top;
		L[i]=stk[top]; stk[++top]=i;
	}
	top=0; stk[top]=n+1;
	for(int i=n;i>=1;i--){
		while(top && a[stk[top]]<a[i]) --top;
		R[i]=stk[top]; stk[++top]=i;
		//printf("R=%d\n", R[i]);
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(int i=0;i<31;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>>i&1) pre[i][j]=j;
			else pre[i][j]=pre[i][j-1];
		}
	}
	for(int i=0;i<31;i++){
		nex[i][n+1]=n+1;
		for(int j=n;j>=1;j--){
			if(a[j]>>i&1) nex[i][j]=j;
			else nex[i][j]=nex[i][j+1];
		}
	}
	init();
	long long ans=0;
	for(int i=1;i<=n;i++){
		int l=L[i]+1,r=R[i]-1;
		int l2=0,r2=n+1;
		//printf("i=%d, [%d, %d]\n", i,l,r);
		for(int j=0;j<31;j++){
			if((a[i]>>j&1) == 0) {
				l2=max(l2,pre[j][i]);
				r2=min(r2,nex[j][i]);
			}
		}
		l2++, r2--;
		r2=min(r2,r); l2=max(l2,l);
		ans += 1LL*(r2-i+1)*(i-l2+1);
	}
	ans=1LL*n*(n+1)/2 - ans;
	cout<<ans<<endl;
}