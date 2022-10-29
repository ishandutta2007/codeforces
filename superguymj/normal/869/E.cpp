#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<ctime>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=2505;
int n,m,q,tp,a1,a2,b1,b2;
int t[N][N],x;
map <int,int> mp[N][N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int ran()
{
	return rand()<<15|rand();
}

int get(int x,int y)
{
	return (x-1)*m+y;
}

void ins(int x,int y,int c)
{
	for(int i=x; i<=n; i+=i&-i)
		for(int j=y; j<=m; j+=j&-j)
			t[i][j]^=c;
}

int query(int x,int y)
{
	int rt=0;
	for(int i=x; i; i-=i&-i)
		for(int j=y; j; j-=j&-j)
			rt^=t[i][j];
	return rt;
}

int main()
{
	srand(19260817);
	n=getint(),m=getint(),q=getint();
	while(q--)
	{
		tp=getint();
		if(tp==1)
		{
			a1=getint(),b1=getint();
			a2=getint(),b2=getint();
			mp[a1][b1][get(a2,b2)]=x=ran();
			ins(a1,b1,x),ins(a2+1,b1,x);
			ins(a1,b2+1,x),ins(a2+1,b2+1,x);
		}
		if(tp==2)
		{
			a1=getint(),b1=getint();
			a2=getint(),b2=getint();
			x=mp[a1][b1][get(a2,b2)];
			ins(a1,b1,x),ins(a2+1,b1,x);
			ins(a1,b2+1,x),ins(a2+1,b2+1,x);
		}
		if(tp==3)
		{
			a1=getint(),b1=getint();
			a2=getint(),b2=getint();
			puts(query(a1,b1)==query(a2,b2)?"Yes":"No");
		}
	}
	return 0;
}