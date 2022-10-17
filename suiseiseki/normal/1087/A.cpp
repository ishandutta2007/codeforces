#include <cstdio>
char s[55];
char a[55];
int main(){
	int n=0;
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	int begin;
	if(n&1){
		begin=(n>>1)+1;
	}
	else{
		begin=(n>>1);
	}
	int len=0;
	a[++len]=s[begin];
	int left=begin-1,right=begin+1;
	while(left>=1&&right<=n){
		a[++len]=s[right++];
		a[++len]=s[left--];
	}
	if(!(n&1)){
		a[++len]=s[n];
	}
	puts(a+1);
	return 0;
}