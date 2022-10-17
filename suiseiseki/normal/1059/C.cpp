/*#include <cstdio>
#include <vector>
using namespace std;
vector<int> a;
int ans[1000005];
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	int n;
	scanf("%d",&n);
	int s=1;
	while(s<=n){
		if((s<<2)>n){
			for(int i=1;i*s<=n&&(int)a.size()<n;i++){
				a.push_back(i*s);
			}
		}
		else{
			for(int i=1;i*s<=n;i+=2){
				a.push_back(i*s);
			}
		}
		s<<=1;
	}
	for(int i=n-1;i>=0;i--){
		ans[i]=gcd(ans[i+1],a[i]);
	}
	for(int i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}*/
#include <cstdio>
int ans[1000005];
int a[1000005];
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	int n;
	scanf("%d",&n);
	int len=0;
	for(int i=1;i<=n;i<<=1){
		if((i<<2)>n){
			for(int j=1;j*i<=n&&len<n;j++){
				a[++len]=i*j;
			}
		}
		else{
			for(int j=1;j*i<=n;j+=2){
				a[++len]=i*j;
			}
		}
	}
	for(int i=n;i>0;i--){
		ans[i]=gcd(ans[i+1],a[i]);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}