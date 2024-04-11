#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[100005];
signed main(){
	scanf("%I64d%I64d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%I64d",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(a[l]==a[l+1])l++;
	while(a[r]==a[r-1])r--;
	while(k&&l<r){
		if(l<(n-r+1)){
			int d=a[l+1]-a[l];
			if(k>=d*l) {
				k-=d*l;
				l++;
			}
			else {
				a[l]+=k/l;
				break;
			}
		}
		else{
			int d=a[r]-a[r-1];
			if(k>=d*(n-r+1)){
				k-=d*(n-r+1);
				r--;
			}
			else{
				a[r]-=k/(n-r+1);
				break;
			}
		}
		while(a[l]==a[l+1])l++;
		while(a[r]==a[r-1])r--;
	}
	printf("%I64d",a[r]-a[l]);
	return 0;
}