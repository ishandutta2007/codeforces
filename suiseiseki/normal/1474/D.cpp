#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=200000;
int n;
int a[Maxn+5];
ll s[Maxn+5];
bool check(){
	ll sum=0;
	for(int i=1;i<=n;i++){
		sum=a[i]-sum;
		if(sum<0){
			return 0;
		}
	}
	return sum==0;
}
void solve(){
	ll sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if((n-i+1)&1){
			sum+=a[i];
		}
		else{
			sum-=a[i];
		}
		s[i]=a[i]-s[i-1];
	}
	int left=n+1;
	for(int i=n;i>0;i--){
		if((n-i+1)&1){
			if(s[i]-sum<0){
				left=i;
				break;
			}
			left=i;
		}
		else{
			if(s[i]+sum<0){
				left=i;
				break;
			}
			left=i;
		}
	}
	int right=0;
	for(int i=1;i<=n;i++){
		if(s[i]<0){
			right=i;
			break;
		}
		right=i;
	}
	if(sum==0){
		if(check()){
			puts("YES");
			return;
		}
	}
	for(int i=1;i<n;i++){
		if((n-i+1)&1){
			if((a[i]-a[i+1])*2==sum){
				swap(a[i],a[i+1]);
				if(left<=i&&right>=i&&check()){
					puts("YES");
					return;
				}
				swap(a[i],a[i+1]);
			}
		}
		else{
			if((a[i+1]-a[i])*2==sum){
				swap(a[i],a[i+1]);
				if(left<=i&&right>=i&&check()){
					puts("YES");
					return;
				}
				swap(a[i],a[i+1]);
			}
		}
	}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}