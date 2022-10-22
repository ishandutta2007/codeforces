#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n;
int ans[510][510];
bool check(int x,int y){
	if(x<=0||x>n||y<=0||y>n) return 0;
	if(ans[x][y]>0) return 0;
	return 1;
}
void dfs(int x,int y,int &s,int d){
	ans[x][y]=d;++s;
	if(s==d) return ;
	if(check(x,y-1)){
		dfs(x,y-1,s,d);
	}
	if(s==d) return ;
	if(check(x+1,y)){
		dfs(x+1,y,s,d);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) ans[i][i]=read();
	for(int i=1;i<=n;++i){
		int cnt=0;
		dfs(i,i,cnt,ans[i][i]);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j) printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}