#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=100000;
int n,q;
int a[Maxn+5];
ll sum[Maxn+5];
set<ll> st;
void work(int left,int right){
	st.insert(sum[right]-sum[left-1]);
	if(left==right||a[left]==a[right]){
		return;
	}
	int val_mid=(a[left]+a[right])>>1;
	int mid=left;
	while(mid+1<=right&&a[mid+1]<=val_mid){
		mid++;
	}
	work(left,mid);
	work(mid+1,right);
}
void solve(){
	st.clear();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	work(1,n);
	for(int i=1;i<=q;i++){
		int x;
		scanf("%d",&x);
		if(st.count(x)>0){
			puts("Yes");
		}
		else{
			puts("No");
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}