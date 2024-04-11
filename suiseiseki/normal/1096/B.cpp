#include <cstdio>
#define Maxn 200000
#define Mod 998244353
char s[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	int left=1,right=1;
	for(int i=1;i<=n;i++){
		if(s[i]==s[i+1]){
			left++;
		}
		else{
			break;
		}
	}
	for(int i=n;i>0;i--){
		if(s[i]==s[i-1]){
			right++;
		}
		else{
			break;
		}
	}
	if(s[1]==s[n]){
		printf("%d\n",(int)(((long long)left+right+(long long)left*right+1)%Mod));
	}
	else{
		printf("%d\n",left+right+1);
	}
	return 0;
}