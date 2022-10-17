#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<n;i++){
		ans+=a[i+1]-a[i]-1;
	}
	printf("%d\n",ans);
	return 0;
}