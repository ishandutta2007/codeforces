#include<cstdio>
#include<algorithm>
using namespace std;

int a[100000];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)a[i]+=a[i-1];
	int m;scanf("%d",&m);
	for(int i=0;i<m;i++){
		int x;
		scanf("%d",&x);
		int u=lower_bound(a,a+n,x)-a;
		printf("%d\n",u+1);
	}
	return 0;
}