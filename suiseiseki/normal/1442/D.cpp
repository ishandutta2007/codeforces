#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int Maxn=3000;
vector<int> a[Maxn+5];
int n,k;
ll sum[Maxn+5];
void update(ll *f,int w,ll v){
	for(int i=k;i>=w;i--){
		f[i]=max(f[i],f[i-w]+v);
	}
}
ll f[15][Maxn+5];
ll ans;
void solve(int dep,int left,int right){
	if(left==right){
		ll sum=0;
		for(int i=0;i<(int)a[left].size();i++){
			ans=max(ans,f[dep][k-i]+sum);
			sum+=a[left][i];
		}
		ans=max(ans,f[dep][k-a[left].size()]+sum);
		return;
	}
	int mid=(left+right)>>1;
	memcpy(f[dep+1],f[dep],sizeof f[dep]);
	for(int i=mid+1;i<=right;i++){
		update(f[dep+1],a[i].size(),sum[i]);
	}
	solve(dep+1,left,mid);
	memcpy(f[dep+1],f[dep],sizeof f[dep]);
	for(int i=left;i<=mid;i++){
		update(f[dep+1],a[i].size(),sum[i]);
	}
	solve(dep+1,mid+1,right);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int len;
		scanf("%d",&len);
		a[i].reserve(len);
		for(int j=0;j<len;j++){
			int x;
			scanf("%d",&x);
			a[i].push_back(x);
		}
		while((int)a[i].size()>k){
			a[i].pop_back();
		}
		for(int j=0;j<(int)a[i].size();j++){
			sum[i]+=a[i][j];
		}
	}
	solve(0,1,n);
	printf("%lld\n",ans);
	return 0;
}