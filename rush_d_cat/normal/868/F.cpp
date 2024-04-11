#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
typedef long long LL;
int n, k, a[N];
LL pd[N], dp[N];
int cnt[N]; LL ans=0;

void solve(int l, int r, int ql, int qr) {
	if (l>r) {
		return;
   	}
	//printf("solve %d %d %d %d\n", l,r,ql,qr);
	int mid=(l+r)>>1;
	//printf("1 [%d,%d] %d %d\n", ql,l,cnt[1],cnt[2]);
	// l, ql
  	for(int i=l+1;i<=mid;i++){
		ans-=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;
  		cnt[a[i]]++; 
		ans+=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;
	}
	int bst=ql; LL mx=ans+pd[ql-1];
	for(int i=ql;i<qr;i++){
		ans-=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;
		cnt[a[i]]--;
		ans+=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;
		if(i+1<=mid){
			LL tmp=ans + pd[i];
			if(tmp<mx){
				mx=tmp; bst=i+1;
			}
		}
	}
	//printf("2 [%d,%d] %d %d\n", qr,mid,cnt[1],cnt[2]);
	// mid, qr -> l, ql
	for(int i=qr-1;i>=ql;i--) {
		ans-=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;
		cnt[a[i]]++;
		ans+=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;	
	}
	for(int i=mid;i>l;i--){
		ans-=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;
		cnt[a[i]]--;
		ans+=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;	
	}

	//printf("3 [%d,%d] %d %d\n", ql,l,cnt[1],cnt[2]);
	//printf("dp[%d]=%d, from %d\n", mid,mx,bst);
	dp[mid]=mx;
	solve(l,mid-1,ql,bst);
	// l, ql -> mid+1, bst
	for(int i=l+1;i<=mid+1;i++) {
		ans-=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;
		cnt[a[i]]++;
		ans+=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;	
	}
	for(int i=ql;i<bst;i++){
		ans-=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;
		cnt[a[i]]--;
		ans+=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;	
	}
	//printf("4 [%d,%d] %d %d\n", bst+1,mid+1,cnt[1],cnt[2]);
	solve(mid+1,r,bst,qr);
	// mid+1,bst -> l,ql
	for(int i=mid+1;i>l;i--){
		ans-=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;
		cnt[a[i]]--;
		ans+=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;	
	}
	for(int i=bst-1;i>=ql;i--){
		ans-=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;
		cnt[a[i]]++;
		ans+=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;	
	}
	//printf("5 [%d,%d] %d %d\n", ql,l,cnt[1],cnt[2]);
}
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		ans-=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;
		cnt[a[i]]++;
		ans+=1LL*cnt[a[i]]*(cnt[a[i]]-1)/2;
		pd[i]=ans;
	}
	for(int i=1;i<k;i++){
		memset(cnt,0,sizeof(cnt)); cnt[a[1]]++; memset(dp,0,sizeof(dp)); ans=0;
		solve(1,n,1,n);
		for(int j=1;j<=n;j++)pd[j]=dp[j];
	}
	cout<<dp[n]<<endl;
}