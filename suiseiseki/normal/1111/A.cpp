#include <cstdio>
#define Maxn 1000
char s[Maxn+5],t[Maxn+5];
bool a[Maxn+5],b[Maxn+5];
int main(){
	int n,m;
	n=m=0;
	scanf("%s",s+1);
	scanf("%s",t+1);
	while(s[++n]!='\0');
	n--;
	while(t[++m]!='\0');
	m--;
	if(n!=m){
		puts("No");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='a'||s[i]=='o'||s[i]=='u'||s[i]=='i'||s[i]=='e'){
			a[i]=1;
		}
	}
	for(int i=1;i<=m;i++){
		if(t[i]=='a'||t[i]=='o'||t[i]=='u'||t[i]=='i'||t[i]=='e'){
			b[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}