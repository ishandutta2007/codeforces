#include <cstdio>
const int Maxn=200000;
char s[Maxn+5];
int n;
int st_1[Maxn+5],st_1_top,st_2[Maxn+5],st_2_top;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=0;
		while(s[++n]!='\0');
		n--;
		int ans=0;
		st_1_top=st_2_top=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='('){
				st_1[++st_1_top]=i;
			}
			else if(s[i]==')'){
				if(st_1_top>0){
					st_1_top--;
					ans++;
				}
			}
			else if(s[i]=='['){
				st_2[++st_2_top]=i;
			}
			else{
				if(st_2_top>0){
					st_2_top--;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}