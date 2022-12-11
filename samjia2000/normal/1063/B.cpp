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

const int N = 2005;
const int INF = 1e9;

int n,m;
int R,C;
int X,Y;
int Left[N][N],Right[N][N];
bool bz[N][N];
char s[N];
struct point{
	int x,y;
	point (const int x_=0,const int y_=0){x=x_;y=y_;}
}que[N*N];
int he,ta;

void flood_Left(int x,int y){
	if (x>1&&bz[x-1][y]&&Left[x-1][y]==INF){
		que[++ta]=point(x-1,y);
		Left[x-1][y]=Left[x][y];
		flood_Left(x-1,y);
	}
	if (x<n&&bz[x+1][y]&&Left[x+1][y]==INF){
		que[++ta]=point(x+1,y);
		Left[x+1][y]=Left[x][y];
		flood_Left(x+1,y);
	}
	if (y<m&&bz[x][y+1]&&Left[x][y+1]==INF){
		que[++ta]=point(x,y+1);
		Left[x][y+1]=Left[x][y];
		flood_Left(x,y+1);
	}
}

void flood_Right(int x,int y){
	if (x>1&&bz[x-1][y]&&Right[x-1][y]==INF){
		que[++ta]=point(x-1,y);
		Right[x-1][y]=Right[x][y];
		flood_Right(x-1,y);
	}
	if (x<n&&bz[x+1][y]&&Right[x+1][y]==INF){
		que[++ta]=point(x+1,y);
		Right[x+1][y]=Right[x][y];
		flood_Right(x+1,y);
	}
	if (y>1&&bz[x][y-1]&&Right[x][y-1]==INF){
		que[++ta]=point(x,y-1);
		Right[x][y-1]=Right[x][y];
		flood_Right(x,y-1);
	}
}

int main(){
	n=get();m=get();
	R=get();C=get();
	X=get();Y=get();
	fo(i,1,n){
		scanf("%s",s+1);
		fo(j,1,m)bz[i][j]=(s[j]=='.');
	}
	fo(i,1,n)fo(j,1,m)Left[i][j]=Right[i][j]=1e9;
	Left[R][C]=Right[R][C]=0;
	he=0,ta=1;
	que[1].x=R;
	que[1].y=C;
	flood_Left(R,C);
	while(he<ta){
		point u=que[++he];
		int x=u.x,y=u.y;
		if (y>1&&bz[x][y-1]&&Left[x][y-1]==INF){
			que[++ta]=point(x,y-1);
			Left[x][y-1]=Left[x][y]+1;
			flood_Left(x,y-1);
		}
	}
	he=0,ta=1;
	que[1].x=R;
	que[1].y=C;
	flood_Right(R,C);
	while(he<ta){
		point u=que[++he];
		int x=u.x,y=u.y;
		if (y<m&&bz[x][y+1]&&Right[x][y+1]==INF){
			que[++ta]=point(x,y+1);
			Right[x][y+1]=Right[x][y]+1;
			flood_Right(x,y+1);
		}
	}
	int ans=0;
	fo(i,1,n)
		fo(j,1,m)
		if (bz[i][j]&&Left[i][j]!=INF){
			int l,r;
			if (j>C)l=Left[i][j],r=Left[i][j]+j-C;
			else r=Right[i][j],l=Right[i][j]+C-j;
			if (l<=X&&r<=Y)ans++;
		}
	cout<<ans<<endl;
	return 0;
}