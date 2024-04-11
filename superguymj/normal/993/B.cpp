#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,m,d[1000],x,s;
struct data{int x,y;} a[1000],b[1000];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int get(int i,int j)
{
	if(a[i].x==b[j].x && a[i].y!=b[j].y) return a[i].x;
	if(a[i].x==b[j].y && a[i].y!=b[j].x) return a[i].x;
	if(a[i].y==b[j].y && a[i].x!=b[j].x) return a[i].y;
	if(a[i].y==b[j].x && a[i].x!=b[j].y) return a[i].y;
	return 0;
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,n) a[i].x=getint(),a[i].y=getint();
	rep(i,1,m) b[i].x=getint(),b[i].y=getint();
	s=0;
	rep(i,1,n)
		rep(j,1,m)
		{
			x=get(i,j);
			if(!x) continue;
			if(!d[i]) d[i]=x;
			else if(d[i]!=x) {puts("-1");return 0;}
			if(!d[j+n]) d[j+n]=x;
			else if(d[j+n]!=x) {puts("-1");return 0;}
			if(s==0) s=x;
			else if(s!=x) s=-1;
		}
	if(s>0)
	{
		printf("%d",s);
		return 0;
	}
	else puts("0");
	return 0;
}