#include<bits/stdc++.h>
using namespace std;

int n,m,fa[105];
char s[55][55];
int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<n+m;i++)fa[i]=i;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)if(s[i][j]=='#'){
			int x=i,y=j+n;
			int p=find(x),q=find(y);
			if(p!=q)fa[q]=p;
		}
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(find(i)==find(j+n)){
		if(s[i][j]=='.'){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}