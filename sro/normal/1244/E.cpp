#include <bits/stdc++.h>
using namespace std;

int n;
long long k;
int a[100005];

int main(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	int cntl=1,cntr=1;
	while(l<r-1&&a[l+1]==a[l]){
		cntl++;
		l++;
	}
	while(r>l+1&&a[r-1]==a[r]){
		cntr++;
		r--;
	}
	if(a[l]==a[r]){
		puts("0");
		return 0;
	}
	while(1){
		if(cntl<cntr){
			long long can=k/cntl,mdd=k%cntl;
			if(can+a[l]>=a[l+1]){
				k-=1ll*cntl*(a[l+1]-a[l]);
				a[l]=a[l+1];
				while(l<r-1&&a[l+1]==a[l]){
					cntl++;
					l++;
				}
			}else{
				printf("%d\n",a[r]-(a[l]+can));
				return 0;
			}
		}else{
			long long can=k/cntr,mdd=k%cntr;
			if(a[r]-can<=a[r-1]){
				k-=1ll*cntr*(a[r]-a[r-1]);
				a[r]=a[r-1];
				while(r>l+1&&a[r-1]==a[r]){
					cntr++;
					r--;
				}
			}else{
				printf("%d\n",(a[r]-can)-a[l]);
				return 0;
			}
		}
		if(a[l]==a[r]){
			break;
		}
	}
	puts("0");
	return 0;
}