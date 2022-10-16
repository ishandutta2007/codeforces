#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define ll long long
int a[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	if(a[n]==0){
		puts("cslnb");
		return 0;
	}
	int num=0;
	for(int i=1;i<=n-1;i++){
		if(a[i]==a[i+1]){
			num++;
		}
	}
	if(num>1){
		puts("cslnb");
		return 0;
	}
	for(int i=1;i<=n-1;i++){
		if(a[i]==a[i+1]&&(a[i]==0||(i>1&&a[i]-1==a[i-1]))){
			puts("cslnb");
			return 0;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i]-(i-1);
	}
	if(ans&1){
		puts("sjfnb");
	}
	else{
		puts("cslnb");
	}
	return 0;
}