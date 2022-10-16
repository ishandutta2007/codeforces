#include <cstdio>
const int Maxn=200000;
int n;
int a,b,k;
char s_a[Maxn+5],s_b[Maxn+5];
int main(){
	scanf("%d%d%d",&a,&b,&k);
	if(a==0||b==1){
		if(k==0){
			puts("Yes");
			for(int i=1;i<=b;i++){
				putchar('1');
			}
			for(int i=1;i<=a;i++){
				putchar('0');
			}
			puts("");
			for(int i=1;i<=b;i++){
				putchar('1');
			}
			for(int i=1;i<=a;i++){
				putchar('0');
			}
			puts("");
		}
		else{
			puts("No");
		}
		return 0;
	}
	if(k>=a+b-1){
		puts("No");
		return 0;
	}
	n=a+b;
	s_b[n]='1';
	s_a[n-k]='1';
	b--;
	for(int i=1;i<=n;i++){
		if(s_a[i]=='1'){
			if(s_b[i]=='1'){
				continue;
			}
			s_b[i]='0';
		}
		else if(s_b[i]=='1'){
			s_a[i]='0';
		}
		else{
			if(b>0){
				b--;
				s_a[i]=s_b[i]='1';
			}
			else{
				s_a[i]=s_b[i]='0';
			}
		}
	}
	puts("Yes");
	for(int i=1;i<=n;i++){
		putchar(s_a[i]);
	}
	puts("");
	for(int i=1;i<=n;i++){
		putchar(s_b[i]);
	}
	puts("");
	return 0;
}