#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1005;

int n;
int ax,ay,bx,by,cx,cy;
bool can[N][N],vis[N][N];
int fx[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

void dfs(int x,int y){
	if (can[x][y])return;
	if (vis[x][y])return;
	vis[x][y]=1;
	fo(i,0,7){
		int x1=x+fx[i][0],y1=y+fx[i][1];
		if (x1>0&&x1<=n&&y1>0&&y1<=n){
			dfs(x1,y1);
		}
	}
}

int main(){
	n=get();
	ax=get(),ay=get();
	bx=get(),by=get();
	cx=get(),cy=get();
	for(int x=ax,y=ay;x<=n&&y<=n;x++,y++)can[ax][ay]=1;
	for(int x=ax,y=ay;x>0&&y>0;x--,y--)can[ax][ay]=1;
	for(int x=ax,y=ay;x<=n&&y>0;x++,y--)can[ax][ay]=1;
	for(int x=ax,y=ay;x>0&&y<=n;x--,y++)can[ax][ay]=1;
	fo(i,1,n)can[ax][i]=can[i][ay]=1;
	dfs(bx,by);
	if (vis[cx][cy])printf("YES\n");
	else printf("NO\n");
	return 0;
}