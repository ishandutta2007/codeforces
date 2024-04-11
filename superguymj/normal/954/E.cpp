#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=200005;
int n,T;
long long tot;
double ans;
struct data{long long a,t;} dat[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;	
	return x;
}

bool cmp(data a,data b)
{
	return a.t<b.t;
}

void solve_big()
{
	repd(i,n,1)
	{
		if(tot-dat[i].a*dat[i].t>0) tot-=dat[i].a*dat[i].t,ans-=dat[i].a;
		else {ans-=(double)tot/dat[i].t; break;}
	}
	printf("%.10lf\n",ans);
}

void solve_small()
{
	rep(i,1,n)
	{
		if(tot-dat[i].a*dat[i].t<0) tot-=dat[i].a*dat[i].t,ans-=dat[i].a;
		else {ans-=(double)tot/dat[i].t; break;}
	}
	printf("%.10lf\n",ans);
}

int main()
{
	n=getint(),T=getint();
	rep(i,1,n) ans+=(dat[i].a=getint());
	rep(i,1,n) dat[i].t=getint()-T;
	bool jdg=0;
	rep(i,1,n) if(dat[i].t>=0) {jdg=1; break;}
	if(!jdg) return puts("0"),0;
	jdg=0;
	rep(i,1,n) if(dat[i].t<=0) {jdg=1; break;}
	if(!jdg) return puts("0"),0;
	rep(i,1,n) tot+=dat[i].a*dat[i].t;
	sort(dat+1,dat+1+n,cmp);
	if(tot==0) return printf("%.10lf\n",ans),0;
	if(tot>0) solve_big();
	else solve_small();
	return 0;
}