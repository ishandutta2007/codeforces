#include<cstdio>

int n;
char s[1005][1005];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	int ans=0;
	for(int i=2;i<n;i++)
		for(int j=2;j<n;j++)
			if(s[i][j]=='X'&&s[i-1][j-1]=='X'&&s[i-1][j+1]=='X'&&s[i+1][j-1]=='X'&&s[i+1][j+1]=='X')
				ans++;
	printf("%d\n",ans);
}