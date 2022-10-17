#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 100000
int c[Maxn+5];
int t[Maxn+5];
int a[Maxn+5];
int b[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		a[i]=c[i]-c[i-1];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i]);
		b[i]=t[i]-t[i-1];
	}
	sort(a+2,a+1+n);
	sort(b+2,b+1+n);
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			flag=0;
		}
	}
	if(flag){
		puts("Yes");
	}
	else{
		puts("No");
	}
	return 0;
}