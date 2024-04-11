#include <cstdio>
char s[105];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	int len=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='x'){
			len++;
		}
		else{
			if(len>=3){
				ans+=len-2;
			}
			len=0;
		}
	}
	if(len>=3){
		ans+=len-2;
	}
	printf("%d\n",ans);
	return 0;
}