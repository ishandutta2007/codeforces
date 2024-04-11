#include <cstdio>
#define Maxn 200000
int s[Maxn+5];
int main(){
	int n;
	int b,a;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
	}
	int ans=0;
	int now_a,now_b;
	now_a=a,now_b=b;
	for(int i=1;i<=n;i++){
		if(s[i]==1){
			if(now_a>0&&now_b<b){
				now_a--;
				now_b++;
				ans++;
			}
			else{
				now_b--;
				if(now_b<0){
					break;
				}
				ans++;
			}
		}
		else{
			if(now_b>0){
				now_b--;
				ans++;
			}
			else if(now_a>0){
				now_a--;
				ans++;
			}
			else{
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}