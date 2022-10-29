#include<algorithm>
#include<unistd.h>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cstdio>
#include<ctime> 
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
bool vis[100005];
int n;
long long x[100005],y[100005];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

bool check(int a,int b)
{
	int s=2;
	while(b==a) b=rand()%n+1;
	memset(vis,0,sizeof(vis));
	vis[a]=1,vis[b]=1;
	rep(i,1,n) if(!vis[i])
	{
		if((y[i]-y[a])*(x[a]-x[b])==(y[a]-y[b])*(x[i]-x[a])) vis[i]=1,++s;
	}
	if(n-s<=2) return 1;
	rep(i,1,n) if(vis[i]==0) {a=i,++s,vis[i]=1; break;}
	rep(i,1,n) if(vis[i]==0) {b=i,++s,vis[i]=1; break;}
	rep(i,1,n) if(!vis[i])
	{
		if((y[i]-y[a])*(x[a]-x[b])==(y[a]-y[b])*(x[i]-x[a])) vis[i]=1,++s;
	}
	return n==s;
}

int id[100005];

bool cmpx(int a,int b){return x[a]<x[b];}
bool cmpy(int a,int b){return y[a]<y[b];}

bool query()
{
	rep(i,1,n) id[i]=i;
	sort(id+1,id+1+n,cmpx);
	
	int tot1=0;
	rep(i,1,n) if(i==1 || x[id[i]]!=x[id[i-1]]) ++tot1;
	if(tot1<=2) return 1;
	
	rep(i,1,n) id[i]=i;
	sort(id+1,id+1+n,cmpy);
	
	int tot2=0;
	rep(i,1,n) if(i==1 || y[id[i]]!=y[id[i-1]]) ++tot2;
	if(tot2<=2) return 1;

	return tot1==1 && tot2==1;
}

int main()
{
	n=getint();
	rep(i,1,n) x[i]=getint(),y[i]=getint();
	if(query()) return puts("YES"),0;
	if(n<=2) return puts("YES"),0;
	if(check(1,2) || check(2,3) || check(1,3)) return puts("YES"),0;
	return puts("NO"),0;
}