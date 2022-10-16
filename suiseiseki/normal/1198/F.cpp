#include <ctime>
#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 100000
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int a[Maxn+5];
int n;
int p[Maxn+5];
int ans[Maxn+5];
int main(){
	srand(19260817);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[i]=i;
	}
	int t=200;
	int x,y;
	int tmp;
	while(t--){
		random_shuffle(p+1,p+1+n);
		x=0,y=0;
		for(int i=1;i<=n;i++){
			tmp=gcd(a[p[i]],x);
			if(tmp!=x){
				ans[p[i]]=1;
				x=tmp;
			}
			else{
				ans[p[i]]=2;
				y=gcd(a[p[i]],y);
			}
		}
		if(x!=1||y!=1){
			continue;
		}
		puts("YES");
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
		puts("");
		return 0;
	}
	puts("NO");
	return 0;
}