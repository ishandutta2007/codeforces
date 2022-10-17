#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 200
int a[Maxn+5];
bool see[10005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	see[a[n]]=1;
	for(int i=n-1;i>0;i--){
		if(a[n]%a[i]!=0||see[a[i]]){
			printf("%d %d\n",a[n],a[i]);
			break;
		}
		see[a[i]]=1;
	}
	return 0;
}