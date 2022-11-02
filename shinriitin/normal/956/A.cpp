#include <bits/stdc++.h>

const int max_N = 100 + 21;

int n,m,f[max_N];

int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}

char s[max_N][max_N];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+m;++i)f[i]=i;
	for(int i=1;i<=n;++i){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;++j)
			if(s[i][j]=='#'){
				f[find(i)]=find(n+j);
			}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[i][j]=='.'){
				int x = find(i);
				int y = find(n+j);
				if(x==y){
					return puts("No"),0;
				}
			}
	return puts("Yes"),0;
}