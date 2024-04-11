#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int a[105];
int main(){
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1,j;i<=n;i++){
		for(j=i-1;j&&a[i]%a[j];j--);
		ans+=!j;
	}
	printf("%d\n",ans);
	return 0;
}