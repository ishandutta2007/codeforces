#include <cstdio>
char s[200005],t[200005];
int main(){
	int len_s=0,len_t=0;
	scanf("%s%s",s+1,t+1);
	while(s[++len_s]!='\0');
	while(t[++len_t]!='\0');
	len_s--,len_t--;
	while(s[len_s]==t[len_t]&&len_s>0&&len_t>0){
		len_s--,len_t--;
	}
	printf("%d\n",len_s+len_t);
	return 0;
}