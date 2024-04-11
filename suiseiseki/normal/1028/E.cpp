#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=140582;
int n;
int b[Maxn+5];
ll a[Maxn+5];
int main(){
	scanf("%d",&n);
	std::pair<int,int> mx_val=std::make_pair(-1,0);
	b[0]=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if(b[i]!=b[i-1]){
			mx_val=std::max(mx_val,std::make_pair(b[i],i));
		}
	}
	a[mx_val.second]=std::max(1,b[mx_val.second]);
	b[0]=b[n];
	for(int i=mx_val.second-1;i>0;i--){
		if(b[i]>b[i-1]){
			a[i]=b[i];
		}
		else{
			a[i]=b[i]+((b[i-1]-b[i])/a[i+1]+1)*a[i+1];
		}
	}
	a[n+1]=a[1];
	for(int i=n;i>mx_val.second;i--){
		if(b[i]>b[i-1]){
			a[i]=b[i];
		}
		else{
			a[i]=b[i]+((b[i-1]-b[i])/a[i+1]+1)*a[i+1];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i+1]==0||a[i]%a[i+1]!=b[i]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		printf("%lld ",a[i]);
	}
	puts("");
	return 0;
}