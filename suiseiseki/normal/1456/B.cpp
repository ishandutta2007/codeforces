#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100000;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
int sum[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	bool flag=0;
	for(int i=3;i<=n;i++){
		if((a[i]^a[i-1])<a[i-2]||(a[i-1]^a[i-2])>a[i]){
			flag=1;
			break;
		}
	}
	if(flag){
		puts("1");
		return 0;
	}
	int ans=Inf;
	for(int i=1;i<=n;i++){
		for(int j=i;j>0;j--){
			for(int k=i+1;k<=n;k++){
				if((sum[i]^sum[j-1])>(sum[k]^sum[i])){
					ans=min(ans,i-j+k-i-1);
				}
			}
		}
	}
	if(ans==Inf){
		ans=-1;
	}
	printf("%d\n",ans);
	return 0;
}