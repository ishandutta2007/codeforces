#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100;
int a[Maxn+5];
int n;
bool cmp(int p,int q){
	return p>q;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		puts("");
	}
	return 0;
}