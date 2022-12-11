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

const int N = 55;

int n,m;
int a[N][N];
struct point{
	int x,y;
	point(const int x_=0,const int y_=0){x=x_;y=y_;}
}st[N],ed[N];
struct move{
	int x1,y1,x2,y2;
	move(const int x1_=0,const int y1_=0,const int x2_=0,const int y2_=0){x1=x1_;y1=y1_;x2=x2_;y2=y2_;}
}A[10000],B[10000];
int ka,kb;
int dis[N][N],vis[N][N],tim;
int fx[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int lst[N][N];
point que[N*N];

void floodfill(int x,int y){
	int he=0,ta=1;
	que[1]=point(x,y);
	vis[x][y]=1;
	for(;he<ta;){
		point u=que[++he];
		if(!a[u.x][u.y])
		fo(t,0,3){
			point v=point(u.x+fx[t][0],u.y+fx[t][1]);
			if (v.x<1||v.x>n||v.y<1||v.y>n||vis[v.x][v.y]==tim)continue;
			dis[v.x][v.y]=dis[u.x][u.y]+1;
			lst[v.x][v.y]=t^1;
			vis[v.x][v.y]=tim;
			que[++ta]=v;
		}
	}
}

void getplan(point *p,int &k,move *s){
	k=0;
	fo(i,1,n)fo(j,1,n)a[i][j]=0;
	fo(i,1,m)a[p[i].x][p[i].y]=i;
	fo(i,1,m)
	if (!a[1][i]){
		dis[1][i]=0;
		tim++;
		floodfill(1,i);
		int kx=0,ky=0,d=1e9;
		fo(j,i+1,n)
		if (vis[1][j]==tim&&a[1][j]&&dis[1][j]<d){
			kx=1,ky=j;
			d=dis[1][j];
		}
		fo(x,2,n)
			fo(y,1,n)
			if (vis[x][y]==tim&&a[x][y]&&dis[x][y]<d){
				d=dis[x][y];
				kx=x,ky=y;
			}
		for(int x=kx,y=ky;x!=1||y!=i;){
			int x_=x+fx[lst[x][y]][0],y_=y+fx[lst[x][y]][1];
			swap(a[x_][y_],a[x][y]);
			s[++k]=move(x,y,x_,y_);
			x=x_,y=y_;
		}
	}
	fo(i,1,m)
	if (a[1][i]!=i){
		int w=0;
		fo(j,i+1,m)if (a[1][j]==i){w=j;break;}
		if (n==2){
			s[++k]=move(1,1,2,1);
			s[++k]=move(1,2,1,1);
			s[++k]=move(2,1,2,2);
			s[++k]=move(2,2,1,2);
			swap(a[1][1],a[1][2]);
		}
		else{
			s[++k]=move(1,i,2,i);
			s[++k]=move(2,i,3,i);
			s[++k]=move(1,w,2,w);
			fo(x,i,w-1)s[++k]=move(3,x,3,x+1);
			fd(x,w,i+1)s[++k]=move(2,x,2,x-1);
			s[++k]=move(2,i,1,i);
			s[++k]=move(3,w,2,w);
			s[++k]=move(2,w,1,w);
			swap(a[1][i],a[1][w]);
		}
	}
}

int main(){
	n=get();m=get();
	fo(i,1,m){
		st[i].x=get();st[i].y=get();
	}
	getplan(st,ka,A);
	fo(i,1,m){
		ed[i].x=get();ed[i].y=get();
	}
	getplan(ed,kb,B);
	printf("%d\n",ka+kb);
	fo(i,1,ka)printf("%d %d %d %d\n",A[i].x1,A[i].y1,A[i].x2,A[i].y2);
	putchar('\n');
	fd(i,kb,1)printf("%d %d %d %d\n",B[i].x2,B[i].y2,B[i].x1,B[i].y1);
	return 0;
}