#include <cstdio>
#define Maxn 100
char s[Maxn+5];
char ans[Maxn+5];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int t;
	int n;
	int a,b,c;
	scanf("%d",&t);
	int num_a,num_b,num_c;
	while(t--){
		scanf("%d",&n);
		scanf("%d%d%d",&a,&b,&c);
		num_a=num_b=num_c=0;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++){
			if(s[i]=='R'){
				num_a++;
			}
			else if(s[i]=='P'){
				num_b++;
			}
			else{
				num_c++;
			}
		}
		if(mn(num_a,b)+mn(num_b,c)+mn(num_c,a)>=(n+1)>>1){
			puts("YES");
			for(int i=1;i<=n;i++){
				if(a>0&&s[i]=='S'){
					ans[i]='R';
					a--;
				}
				else if(b>0&&s[i]=='R'){
					ans[i]='P';
					b--;
				}
				else if(c>0&&s[i]=='P'){
					ans[i]='S';
					c--;
				}
				else{
					ans[i]='\0';
				}
			}
			for(int i=1;i<=n;i++){
				if(ans[i]=='\0'){
					if(a>0){
						ans[i]='R';
						a--;
					}
					else if(b>0){
						ans[i]='P';
						b--;
					}
					else{
						ans[i]='S';
						c--;
					}
				}
			}
			for(int i=1;i<=n;i++){
				putchar(ans[i]);
			}
			puts("");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}