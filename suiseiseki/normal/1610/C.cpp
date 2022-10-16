#include <cstdio>
const int Maxn=200000;
int n;
int a[Maxn+5],b[Maxn+5];
bool check(int m){
	int ans=0;
	for(int i=1;i<=n&&ans<m;i++){
		if(a[i]>=ans&&b[i]>=m-ans-1){
			ans++;
		}
	}
	return ans>=m;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&b[i],&a[i]);
	}
	int left=1,right=n;
	while(left<right){
		int mid=(left+right+1)>>1;
		if(check(mid)){
			left=mid;
		}
		else{
			right=mid-1;
		}
	}
	printf("%d\n",left);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}