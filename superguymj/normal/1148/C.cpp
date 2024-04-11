#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=300005;
int n,p[N],pos[N],tot;
struct data{int x,y;} dat[N*5];

void ins(int x,int y)
{
	dat[++tot]=(data){x,y};
}

void Swap(int x,int y)
{
	if(x>y) swap(x,y);
	if(2*(y-x)>=n) ins(x,y);
	else if(x<=n/2 && y>n/2)
	{
		int t1=1,t2=x,t3=y,t4=n;
		ins(t1,t3),ins(t1,t4),ins(t2,t4),ins(t1,t4),ins(t1,t3);
	}
	else
	{
		int t1=(y<=n/2)?n:1,t2=x,t3=y;
		ins(t1,t2),ins(t1,t3),ins(t1,t2);
	}
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&p[i]),pos[p[i]]=i;
	rep(i,1,n)
	{
		int x=pos[i];
		if(x==i) continue;
		pos[i]=i,pos[p[i]]=x;
		swap(p[i],p[x]),Swap(i,x);
	}
	printf("%d\n",tot);
	rep(i,1,tot) printf("%d %d\n",dat[i].x,dat[i].y);
	return 0;
}