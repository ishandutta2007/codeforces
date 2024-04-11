#include <cstdio>
#include <algorithm>
const int Maxn=100000;
const int Maxb=200;
const int eps=Maxn*Maxb;
const int Maxv=Maxn/Maxb;
int n;
int a[Maxn+5];
int val[Maxn*(Maxb*2+1)+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(int i=-Maxb;i<=Maxb;i++){
		int mx_val=0;
		for(int j=1;j<=n;j++){
			int v=a[j]-i*j;
			val[v+eps]++;
			mx_val=std::max(mx_val,val[v+eps]);
		}
		ans=std::max(ans,mx_val);
		for(int j=1;j<=n;j++){
			int v=a[j]-i*j;
			val[v+eps]--;
		}
	}
	for(int i=1;i<=n;i++){
		int mx_val=0;
		for(int j=1;j<=std::min(n-i,Maxv);j++){
			int v=a[i+j]-a[i];
			if(v%j!=0){
				continue;
			}
			v/=j;
			val[v+eps]++;
			mx_val=std::max(mx_val,val[v+eps]);
		}
		ans=std::max(ans,mx_val+1);
		for(int j=1;j<=std::min(n-i,Maxv);j++){
			int v=a[i+j]-a[i];
			if(v%j!=0){
				continue;
			}
			v/=j;
			val[v+eps]--;
		}
	}
	printf("%d\n",n-ans);
	return 0;
}