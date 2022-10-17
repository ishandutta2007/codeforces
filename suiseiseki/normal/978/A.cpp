#include <cstdio>
bool see[1005];
int ans[55];
int a[55];
int main(){
	int n;
	int len=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>0;i--){
		if(!see[a[i]]){
			see[a[i]]=1;
			ans[++len]=a[i];
		}
	}
	printf("%d\n",len);
	for(int i=len;i>0;i--){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}