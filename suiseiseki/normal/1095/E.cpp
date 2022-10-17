#include <cstdio>
#define Maxn 1000000
char s[Maxn+5];
int pre[Maxn+5],pos[Maxn+5],cnt[Maxn+5];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='('){
			cnt[i]=cnt[i-1]+1;
		}
		else{
			cnt[i]=cnt[i-1]-1;
		}
	}
	if((cnt[n]!=2)&&(cnt[n]!=-2)){
		puts("0");
		return 0;
	}
	pre[0]=Maxn;
	pos[n+1]=Maxn;
	for(int i=1;i<=n;i++){
		pre[i]=mn(pre[i-1],cnt[i]);
	}
	for(int i=n;i>0;i--){
		pos[i]=mn(pos[i+1],cnt[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='('){
			if(cnt[n]==2&&pos[i]>=2&&pre[i-1]>=0){
				ans++;
			}
		}
		else{
			if(cnt[n]==-2&&pos[i]>=-2&&pre[i-1]>=0){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}