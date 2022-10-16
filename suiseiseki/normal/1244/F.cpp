#include <cstdio>
#define Maxn 200000
#define val(i) ((i%n+n)%n)
int n,k;
char s[Maxn+5];
int dis_l[Maxn+5],dis_r[Maxn+5];
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	if(!(n&1)){
		bool flag=1;
		for(int i=0;i<n-1;i++){
			if(s[i]==s[i+1]){
				flag=0;
				break;
			}
		}
		if(flag){
			if(k&1){
				for(int i=0;i<n;i++){
					putchar(s[i]=='B'?'W':'B');
				}
				putchar('\n');
			}
			else{
				for(int i=0;i<n;i++){
					putchar(s[i]);
				}
				putchar('\n');
			}
			return 0;
		}
	}
	for(int i=0;i<n;i++){
		if(s[val(i)]==s[val(i-1)]){
			dis_l[val(i)]=dis_l[val(i-1)]=0;
			for(int j=val(i+1);j!=val(i-1);j=val(j+1)){
				if(s[val(j)]==s[val(j-1)]){
					dis_l[val(j)]=0;
					dis_l[val(j-1)]=0;
				}
				else{
					dis_l[val(j)]=dis_l[val(j-1)]+1;
				}
			}
			dis_r[val(i)]=dis_r[val(i-1)]=0;
			for(int j=val(i-2);j!=i;j=val(j-1)){
				if(s[val(j)]==s[val(j+1)]){
					dis_r[val(j)]=0;
					dis_r[val(j+1)]=0;
				}
				else{
					dis_r[val(j)]=dis_r[val(j+1)]+1;
				}
			}
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(dis_l[i]<=dis_r[i]){
			if(k>=dis_l[i]){
				putchar(s[val(i-dis_l[i])]);
			}
			else{
				if(k&1){
					putchar(s[i]=='W'?'B':'W');
				}
				else{
					putchar(s[i]);
				}
			}
		}
		else{
			if(k>=dis_r[i]){
				putchar(s[val(i+dis_r[i])]);
			}
			else{
				if(k&1){
					putchar(s[i]=='W'?'B':'W');
				}
				else{
					putchar(s[i]);
				}
			}
		}
	}
	putchar('\n');
	return 0;
}