#include <cstdio>
int x[25];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	int ans=0;
	int left=1,right=n;
	while(left<right){
		if(x[left]==x[right]){
			if(x[left]==2){
				ans+=mn(a,b)*2;
			}
			goto to;
			continue;
		}
		if(x[left]!=2&&x[right]!=2){
			return puts("-1"),0;
		}
		if(x[left]==2){
			if(x[right]==0){
				ans+=a;
			}
			else{
				ans+=b;
			}
		}
		else{
			if(x[left]==0){
				ans+=a;
			}
			else{
				ans+=b;
			}
		}
		to:;
		left++,right--;
	}
	if(left==right&&x[left]==2){
		ans+=mn(a,b);
	}
	printf("%d\n",ans);
	return 0;
}