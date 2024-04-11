#include <cstdio>
#define Maxn 200000
char s[Maxn+5];
int n,k;
int work(char c){
	int ans=0;
	int now;
	for(int i=1,j;i<=n;i=j){
		if(s[i]==c){
			j=i;
			now=0;
			while(j<=n&&s[i]==s[j]){
				now++;
				j++;
			}
			ans+=now/k;
		}
		else{
			j=i+1;
		}
	}
	return ans;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int ans=0;
	for(char c='a';c<='z';c++){
		ans=mx(ans,work(c));
	}
	printf("%d\n",ans);
	return 0;
}