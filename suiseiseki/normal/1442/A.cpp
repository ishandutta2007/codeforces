#include <cstdio>
const int Maxn=30000;
int n;
int a[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int num=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]<0){
				num+=a[i]-a[i-1];
			}
		}
		if(num>=0){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}