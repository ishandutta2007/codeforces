#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=200005,M=2005;
int n,m,k,x,y,t[N],B,s[M][M],L[M],blk[N],md[M],id[N],s1[M],s2[N];
struct D{int x,y;} dat[N];
 
int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}
 
int query(int x)
{
	int ret=0;
	rep(i,1,blk[x]-1) 
		ret+=s1[i];
	rep(i,L[blk[x]],x) ret+=s2[i];
	return ret;
}
 
void insx(int x,int y)
{
	if(x<=m)
	{
		s1[blk[x]]+=y;
		s2[x]+=y;
	}
}
 
void ins(int l,int r)
{
	insx(l,k),insx(r+1,-k);
}
 
void init()
{
	rep(i,1,m) blk[i]=(i-1)/B+1;
	repd(i,m,1) L[blk[i]]=i;
}

int main()
{
	n=getint(),m=getint(),B=500;
	init();
	rep(i,1,n) dat[i].x=getint(),dat[i].y=getint();
	rep(i,1,m)
	{
		rep(j,1,B) if((++md[j])>=j) md[j]-=j;
		int nw;
		k=getint(),x=getint();
		y=dat[x].x+dat[x].y;
		if(k==1) id[x]=i,nw=i;
		else nw=id[x],k=-1;
		if(y<=B)
		{
			int p=nw%y;
			rep(j,dat[x].x+1,y) s[y][p+j-1<y?p+j-1:p+j-1-y]+=k;
		}
		else
		{
			int ql=nw+dat[x].x,qr=nw+y-1;
			while(ql<=m) ins(ql,min(qr,m)),ql+=y,qr+=y;
		}
		int ret=0;
		rep(j,1,B) ret+=s[j][md[j]];
		printf("%d\n",ret+query(i));
	}
	return 0;
}