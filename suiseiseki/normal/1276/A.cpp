#include <cstdio>
#define Maxn 1500000
char s[Maxn+5];
int a[Maxn+5],len;
int main(){
	int t;
	int n;
	scanf("%d",&t);
	int ans;
	while(t--){
		n=0;
		len=0;
		scanf("%s",s+1);
		while(s[++n]!='\0');
		n--;
		ans=0;
		for(int i=2;i<=n;i++){
			if(s[i]=='o'&&s[i-2]=='t'&&s[i-1]=='w'&&s[i+1]=='n'&&s[i+2]=='e'){
				a[++len]=-i;
				ans--;
			}
			else{
				if(s[i-1]=='t'&&s[i]=='w'&&s[i+1]=='o'){
					ans++;
					a[++len]=i;
				}
				if(s[i-1]=='o'&&s[i]=='n'&&s[i+1]=='e'){
					ans++;
					a[++len]=i;
				}
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=len;i++){
			if(a[i-1]<0||(i<len&&a[i+1]<0)){
				continue;
			}
			if(a[i]<0){
				printf("%d ",-a[i]);
			}
			else{
				printf("%d ",a[i]);
			}
		}
		puts("");
	}
	return 0;
}