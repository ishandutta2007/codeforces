#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 100
int a[Maxn+5];
int ans[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int i=2,j=n,k=n-1;
	ans[1]=a[n];
	while(k>0){
		ans[i]=a[k];
		k--;
		i++;
		if(k==0){
			break;
		}
		ans[j]=a[k];
		k--;
		j--;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}