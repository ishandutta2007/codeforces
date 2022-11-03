#include<cstdio>
#include<algorithm>
using namespace std;

int a[300000];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	long long ans=0;
	for(int i=0;i<n-1;i++)ans+=(long long)(i+2)*a[i];
	ans+=(long long)n*a[n-1];
	printf("%I64d\n",ans);
	return 0;
}