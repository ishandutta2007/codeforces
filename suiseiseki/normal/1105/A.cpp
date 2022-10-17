#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 1000
int a[Maxn+5];
int ab(int a){
	return a<0?-a:a;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int ans=(1<<30),now;
	int x=0;
	for(int i=1;i<=100;i++){
		now=0;
		for(int j=1;j<=n;j++){
			if(ab(a[j]-i)<=1){
				continue;
			}
			now+=ab(a[j]-i)-1;
		}
		if(now<ans){
			x=i;
			ans=now;
		}
	}
	printf("%d %d\n",x,ans);
	return 0;
}