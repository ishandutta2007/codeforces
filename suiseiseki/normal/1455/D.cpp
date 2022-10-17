#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=500;
int n,x;
int a[Maxn+5],b[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[j]=a[j];
			}
			sort(b+1,b+1+n);
			bool flag=1;
			for(int j=1;j<=n;j++){
				if(b[j]!=a[j]){
					flag=0;
					break;
				}
			}
			if(flag){
				break;
			}
			if(a[i]>x){
				swap(a[i],x);
				ans++;
			}
		}
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		sort(b+1,b+1+n);
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i]){
				ans=-1;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}