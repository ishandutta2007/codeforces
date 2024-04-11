#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
int n,k,a[N];
int b[N],mn[N];
bool chk(int x){
	for(int i=1;i<=n;i++) if(a[i]>=x) b[i]=1; else b[i]=-1;
	for(int i=1;i<=n;i++) b[i]+=b[i-1];
	mn[0]=0; for(int i=1;i<=n;i++) mn[i]=min(mn[i-1],b[i]);	
	bool ok=true;
	for(int i=k;i<=n;i++) {
		if(b[i]>mn[i-k])return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=1,r=n+1;
	while(r-l>1){
		int mid=(l+r)>>1;
		if(chk(mid)) l=mid; else r=mid;
	}
	cout<<l<<endl;
}