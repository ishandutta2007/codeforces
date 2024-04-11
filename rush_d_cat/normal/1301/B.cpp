#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
int t,n,a[N],ans;
bool ok(int x){
	int L=-1e9,R=1e9;
	for(int i=1;i<n;i++){
		if(a[i]!=-1&&a[i+1]!=-1){
			if(abs(a[i+1]-a[i])>x)return 0;
		}
		if(a[i]==-1&&a[i+1]!=-1){
			L=max(L,a[i+1]-x);
			R=min(R,a[i+1]+x);
		}
		if(a[i]!=-1&&a[i+1]==-1){
			L=max(L,a[i]-x);
			R=min(R,a[i]+x);
		}
	}
	if(L>R)return 0;
	ans=L;
	return 1;
}
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int lef=-1,rig=1e9;
		while(rig-lef>1){
			int mid=(lef+rig)>>1;
			if(ok(mid))rig=mid;
			else lef=mid;
		}
		ok(rig);
		if(ans<0||ans>1e9) ans=0;
		printf("%d %d\n", rig,ans);
	}
}