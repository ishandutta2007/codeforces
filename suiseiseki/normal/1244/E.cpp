#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define ll long long
int a[Maxn+5];
int n;
ll k;
int main(){
	scanf("%d",&n);
	cin>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<=n&&a[l+1]==a[l]){
		l++;
	}
	while(r>0&&a[r-1]==a[r]){
		r--;
	}
	if(l>=r){
		puts("0");
		return 0;
	}
	int ans_1=a[1],ans_2=a[n];
	while(l<r&&k>0){
		if(l<=(n-r+1)){
			if(k>=1ll*l*(a[l+1]-a[l])){
				k-=1ll*l*(a[l+1]-a[l]);
				l++;
				ans_1=a[l];
				while(l<=n&&a[l+1]==a[l]){
					l++;
				}
			}
			else{
				ans_1+=k/l;
				break;
			}
		}
		else{
			if(k>=1ll*(n-r+1)*(a[r]-a[r-1])){
				k-=1ll*(n-r+1)*(a[r]-a[r-1]);
				r--;
				ans_2=a[r];
				while(r>0&&a[r-1]==a[r]){
					r--;
				}
			}
			else{
				ans_2-=k/(n-r+1);
				break;
			}
		}
	}
	printf("%d\n",ans_2-ans_1);
	return 0;
}