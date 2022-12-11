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

const int N = 4e5+5;

int n;
struct point{
	int x,y;
	point(const int x_=0,const int y_=0){x=x_;y=y_;}
	
	void read(){x=get();y=get();}
}a[N];

bool cmp(point a,point b){return a.x==b.x?a.y<b.y:a.x<b.x;}

bool can[N];
int que[N],k;
int sta1[N],top1,sta2[N],top2;
bool bz[N];

LL cross(point a,point b,point c){return 1ll*(b.x-a.x)*(c.y-a.y)-1ll*(c.x-a.x)*(b.y-a.y);}

bool solve(bool fir=0){
	top1=top2=0;
	fo(i,1,n)
	if (can[i]){
		if (top1&&a[sta1[top1]].x==a[i].x)continue;
		while(top1>1&&cross(a[sta1[top1-1]],a[i],a[sta1[top1]])>=0)top1--;
		sta1[++top1]=i;
	}
	fd(i,n,1)
	if (can[i]){
		if (top2&&a[sta2[top2]].x==a[i].x)continue;
		while(top2>1&&cross(a[sta2[top2-1]],a[i],a[sta2[top2]])>=0)top2--;
		sta2[++top2]=i;
	}
	fo(i,1,top1)
	if ((a[sta1[i]].x&1)||(a[sta1[i]].y&1)){
		printf("Ani\n");
		exit(0);
	}
	fo(i,1,top2)
	if ((a[sta2[i]].x&1)||(a[sta2[i]].y&1)){
		printf("Ani\n");
		exit(0);
	}
	if (fir){
		fo(i,1,n)bz[i]=0;
		k=0;
		fo(i,1,top1)bz[que[++k]=sta1[i]]=1;
		fo(i,1,top2)if (!bz[sta2[i]])bz[que[++k]=sta2[i]]=1;
	}
}

int main(){
	n=get();
	fo(i,1,n)a[i].read();
	bool ext=0;
	fo(i,1,n)if (a[i].x==0&&a[i].y==0)ext=1;
	if (!ext)a[++n]=point(0,0);
	sort(a+1,a+1+n,cmp);
	fo(i,1,n)can[i]=1;
	solve(1);
	for(int x=3;x<=k;x+=2)can[que[x]]=0;
	solve();
	fo(i,1,n)can[i]=1;
	for(int x=2;x<=k;x+=2)can[que[x]]=0;
	solve();
	fo(i,1,n)can[i]=1;
	can[que[k]]=0;
	solve();
	printf("Borna\n");
	return 0;
}