#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=2005;
int n,tot;
struct data{int u,v;} dat[N];
vector <int> p;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

vector <int> query(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	vector <int> ret;
	rep(i,1,n)
	{
		scanf("%d",&x);
		ret.pb(x);
	}
	return ret;
}

void add(int x,vector <int> p)
{
	rep(i,1,n) if(p[i-1]==1) dat[++tot]=(data){x,i};
}

void find(int x)
{
	vector <int> tmp=query(x);
	add(x,tmp);
}

int main()
{
	n=getint();
	vector <int> p=query(1);
	int c=0;
	rep(i,1,n-1) if(p[i]&1) ++c;
	if(2*c>n-1)
	{
		add(1,p);
		rep(i,1,n-1) if(!(p[i]&1)) find(i+1);
	}
	else
	{
		rep(i,1,n-1) if(p[i]&1) find(i+1);
	}
	puts("!");
	rep(i,1,n-1) printf("%d %d\n",dat[i].u,dat[i].v);
	fflush(stdout);
	return 0;
}