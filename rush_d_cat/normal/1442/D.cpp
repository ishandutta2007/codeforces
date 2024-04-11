#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 3000 + 10;
int n,k;
vector<int> v[N]; LL s[N];
LL f[N];
LL ans=0;
void solve(int l,int r){
	if(l==r) {
		//printf("query %d\n", l);
		LL tmpsum=0;
		for(int i=0;i<v[l].size();i++){
			tmpsum+=v[l][i];
			if(k-i-1>=0) {
				//printf("sum=%lld,f[%d]=%lld\n", tmpsum,k-i-1,f[k-i-1]);
				ans=max(ans,tmpsum+f[k-i-1]);
			}
		}
		return;
	}
	int mid=(l+r)>>1;
	LL tmp[N] = {0};
	for(int i=0;i<=k;i++) tmp[i]=f[i];
	//printf("ins [%d,%d]\n", l,mid);
	for(int i=l;i<=mid;i++){
		for(int j=k;j>=v[i].size();j--){
			f[j]=max(f[j],f[j-v[i].size()]+s[i]);
		}
	}
	solve(mid+1,r);
	//printf("undo [%d,%d]\n", l,mid);
	for(int i=0;i<=k;i++) f[i]=tmp[i];
	//printf("ins [%d,%d]\n", mid+1,r);
	for(int i=mid+1;i<=r;i++){
		for(int j=k;j>=v[i].size();j--){
			f[j]=max(f[j],f[j-v[i].size()]+s[i]);
		}
	}
	solve(l,mid);
}
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int c; scanf("%d",&c);
		for(int j=1;j<=c;j++){
			int x; scanf("%d",&x); v[i].push_back(x);
			s[i]+=x;
		}
	}
	solve(1,n); 
	cout<<ans<<endl;
}