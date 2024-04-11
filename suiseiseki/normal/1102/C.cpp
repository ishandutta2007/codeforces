#include <cstdio>
#define Maxn 100
int a[Maxn+5];
int main(){
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans;
	int now;
	if(x>y){
		printf("%d\n",n);
	}
	else{
		ans=0;
		now=0;
		for(int i=1;i<=n;i++){
			if(a[i]>x){
				continue;
			}
			if(a[i]+y>x){
				now++;
			}
			else{
				ans++;
			}
		}
		printf("%d\n",ans+((now+1)>>1));
	}
	return 0;
}