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

const int N = 2e3+5;

int n,k;
char s[N][N];
int f[N][N];
struct point{
	int x,y;
	point(const int x_=0,const int y_=0){x=x_;y=y_;}
}que[N*N];
char ans[N*2];
int vis[N][N],tim;

int main(){
	n=get();k=get();
	fo(i,1,n){
		scanf("%s",s[i]+1);
	}
	f[1][1]=(s[1][1]=='a'?0:1);
	fo(i,1,n)
		fo(j,1,n)
		if (i>1||j>1){
			int d=(s[i][j]=='a'?0:1);
			f[i][j]=1e9;
			if (i>1)f[i][j]=f[i-1][j]+d;
			if (j>1)f[i][j]=min(f[i][j],f[i][j-1]+d);
		}
	fo(i,1,n)
		fo(j,1,n)
		if (f[i][j]<=k)s[i][j]='a';
	int he=1,ta=1;
	que[1]=point(1,1);
	ans[1]=s[1][1];
	fo(i,2,n*2-1){
		char mv='z';
		fo(u,he,ta){
			int x=que[u].x,y=que[u].y;
			if (x<n)mv=min(mv,s[x+1][y]);
			if (y<n)mv=min(mv,s[x][y+1]);
		}
		int p=he;
		he=ta+1;
		ans[i]=mv;
		tim++;
		int qt=ta;
		fo(u,p,qt){
			int x=que[u].x,y=que[u].y;
			if (x<n&&s[x+1][y]==mv&&vis[x+1][y]<tim){
				vis[x+1][y]=tim;
				que[++ta]=point(x+1,y);
			}
			if (y<n&&s[x][y+1]==mv&&vis[x][y+1]<tim){
				vis[x][y+1]=tim;
				que[++ta]=point(x,y+1);
			}
		}
	}
	fo(i,1,n*2-1)putchar(ans[i]);
	putchar('\n');
	return 0;
}