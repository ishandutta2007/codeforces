#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

int n,m,ans,vis[110];
char c[110][55];
queue<int>q;
stack<int>s;

inline int check(int x,int y){
	for(int i=1;i <= m;i++)
		if(c[x][i] != c[y][m-i+1])
			return 0;
	return 1;
}

inline int checkk(int x){
	for(int i=1;i <= m;i++)
		if(c[x][i] != c[x][m+1-i])
			return 0;
	return 1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i <= n;i++)
		scanf("%s",c[i]+1);
	for(int i=1;i <= n;i++)
		for(int j=i+1;j <= n;j++)
			if(check(i,j))
				ans += 2*m , q.push(i) , s.push(j) , vis[i] = vis[j] = 1;
	for(int i=1;i <= n;i++)
		if(checkk(i) && !vis[i]){
			ans += m , q.push(i);
			break;
		}
	printf("%d\n",ans);
	while(!q.empty())
		printf("%s",c[q.front()]+1) , q.pop();
	while(!s.empty())
		printf("%s",c[s.top()]+1) , s.pop();
}