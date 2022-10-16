#include <cstdio>
#include <algorithm>
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
const int Maxn=100000;
int n;
int a[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	std::reverse(a+1,a+1+n);
	int num=0;
	while(n>1){
		for(int i=1;i<n;i++){
			a[i]-=a[i+1];
		}
		std::sort(a+1,a+n,[](int p,int q){return p>q;});
		n--;
		while(n>1&&a[n]==0){
			n--;
			num++;
		}
		if(num>0){
			num--;
			n++;
		}
	}
	printf("%d\n",a[n]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}