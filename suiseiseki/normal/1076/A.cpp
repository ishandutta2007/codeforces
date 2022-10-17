#include <cstdio>
char s[200005];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	int x=-1;
	for(int i=1;i<n;i++){
		if(s[i]>s[i+1]){
			x=i;
			break;
		}
	}
	if(x==-1){
		x=n;
	}
	for(int i=1;i<=n;i++){
		if(i==x){
			continue;
		}
		putchar(s[i]);
	}
	puts("");
	return 0;
}
/////