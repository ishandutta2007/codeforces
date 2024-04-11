#include <cstdio>
const int Maxn=1000000;
int n;
char s[Maxn+5];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	if(n&1){
		puts("-1");
		return 0;
	}
	int num=0;
	for(int i=1;i<=n;i++){
		if(s[i]==')'){
			num++;
		}
	}
	if((num<<1)!=n){
		puts("-1");
		return 0;
	}
	int ans=0;
	num=0;
	bool in_c=0;
	int las=-1;
	for(int i=1;i<=n;i++){
		if(in_c){
			if(s[i]=='('){
				num++;
			}
			else{
				num--;
			}
			if(num==0){
				in_c=0;
				ans+=i-las+1;
				las=-1;
			}
			continue;
		}
		if(s[i]=='('){
			num++;
		}
		else{
			if(num==0){
				las=i;
				in_c=1;
			}
			num--;
		}
	}
	printf("%d\n",ans);
	return 0;
}