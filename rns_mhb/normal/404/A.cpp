#include<stdio.h>

char s[400][400];

int main(){
	//freopen("in.txt","r",stdin);
	int i,n,j;
	char a,b;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)gets(s[i]);
	a=s[0][0];b=s[0][1];
	if(a==b)return puts("NO");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j || i+j==n-1){
				if(a!=s[i][j])break;
			}
			else if(b!=s[i][j])break;
		}
		if(j<n)break;
	}
	if(i<n)return puts("NO");
	puts("YES");
	return 0;
}