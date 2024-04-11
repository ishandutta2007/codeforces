#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t,f[404][404];
char c[410],s[410]; 

int main()
{
	scanf("%d",&t);
	while(t--){
		memset(c,0,sizeof(c));
		memset(s,0,sizeof(s));
		scanf("%s%s",c+1,s+1);
		int n = strlen(c+1),m = strlen(s+1);
		int flag = 0;
		for(int k=1;k <= m;k++){
			f[0][0] = k-1;
			for(int i=1;i <= n;i++){
				for(int j=0;j <= k;j++){
					f[i][j] = f[i-1][j];
					if(j && c[i] == s[j])
						f[i][j] = max(f[i][j],f[i-1][j-1]);
					if(c[i] == s[f[i-1][j]+1])
						f[i][j] = max(f[i][j],f[i-1][j]+1);
				}
			}
			if(f[n][k-1] == m){
				puts("YES");
				flag = 1;
				for(int i=1;i <= n;i++)
					for(int j=0;j < k;j++)
						f[i][j] = 0;
				break;
			}
			for(int i=1;i <= n;i++)
				for(int j=0;j < k;j++)
					f[i][j] = 0;
		}
		if(!flag)
			puts("NO");
	}
}