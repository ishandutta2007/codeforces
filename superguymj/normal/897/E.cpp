#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<set>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=100005;
typedef long long LL;
int n,m,op,seed,vmax,tot,l,r,ret;
LL c1,c2,a[N],x,y;
struct data{LL x; int len;} dat[N];
set <int> s;
set <int>::iterator p;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int rnd()
{
	ret=seed;
	seed=(seed*7ll+13)%1000000007;
	return ret;
}

bool cmp(data a,data b)
{
	return a.x<b.x;
}

LL getmi(LL a,int x)
{
	LL rt=1;
	a%=y;
	while(x)
	{
		if(x&1) rt=rt*a%y;
		a=a*a%y,x>>=1;
	}
	return rt;
}

int main()
{
	n=getint(),m=getint(),seed=getint(),vmax=getint();
	rep(i,1,n) a[i]=rnd()%vmax+1;
	rep(i,0,n+1) s.insert(i);
	while(m--)
	{
		op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1;
		if(l>r) swap(l,r);
		if(op==3) x=rnd()%(r-l+1)+1;
		else x=rnd()%vmax+1;
		if(op==4) y=rnd()%vmax+1;
 		
 		if(op==1)
 		{
 			p=--s.upper_bound(r),c2=a[*p];
 			p=s.lower_bound(r+1);
			if(*p!=r+1) s.insert(r+1),a[r+1]=c2;
			p=--s.upper_bound(l),c1=a[*p];
 			if(*p!=l) s.insert(l);
 			a[l]=c1+x;
 			for(p=s.upper_bound(l); *p<=r; ++p) a[*p]+=x;
 		}
 		if(op==2)
 		{
 			p=--s.upper_bound(r),c2=a[*p];
 			p=s.lower_bound(r+1);
 			if(*p!=r+1) s.insert(r+1),a[r+1]=c2;
 			p=--s.upper_bound(l),c1=a[*p];
 			if(*p!=l) s.insert(l);
 			a[l]=x;
 			for(p=s.upper_bound(l); *p<=r; )
 				s.erase(*p),p=s.upper_bound(l);
 		}
 		if(op==3 || op==4)
 		{
 			p=--s.upper_bound(l),dat[tot=1]=(data){a[*p],l};
 			for(++p; *p<=r; ++p)
			 	dat[++tot]=(data){a[*p],*p};
 			rep(i,1,tot) dat[i].len=i==tot?r-dat[i].len+1:dat[i+1].len-dat[i].len;
 			if(op==3)
 			{
 				sort(dat+1,dat+1+tot,cmp);
 				rep(i,1,tot)
 				{
 					if(x<=dat[i].len)
 					{
 						printf("%I64d\n",dat[i].x);
 						break;
 					}
 					x-=dat[i].len;
 				}
 			}
 			else
 			{
 				LL ans=0;
 				rep(i,1,tot) ans=(ans+getmi(dat[i].x,x)*dat[i].len)%y;
 				printf("%I64d\n",ans);
 			}
 		}
	}
	return 0;
}