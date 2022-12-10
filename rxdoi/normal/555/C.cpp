#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=10000000;
int n,Q,x,y;
char s[5];

struct Seg
{
	#define Mid (L+R>>1)
	int Lsn[N],Rsn[N],Max[N],Tc,Ql,Qr,Qx,v,res,Rt;

	void Update(int &x,int L,int R)
	{
		if (!x) x=++Tc;
		if (Ql<=L&&R<=Qr) {Max[x]=max(Max[x],v);return;}
		if (Ql<=Mid) Update(Lsn[x],L,Mid);
		if (Qr>Mid) Update(Rsn[x],Mid+1,R);
	}
	void Qmax(int x,int L,int R)
	{
		res=max(res,Max[x]);
		if (!x||L==R) return;
		Qx<=Mid?Qmax(Lsn[x],L,Mid):Qmax(Rsn[x],Mid+1,R);
	}

	void Modify(int L,int R,int V) {Ql=L,Qr=R,v=V;Update(Rt,1,n);}
	int Query(int x) {return Qx=x,res=0,Qmax(Rt,1,n),res;}
} Su,Sl;

int main()
{
	n=IN(),Q=IN();
	while (Q--)
	{
		x=IN(),y=IN(),scanf("%s",s);
		if (s[0]=='U')
		{
			int t=Su.Query(x);printf("%d\n",y-t);
			Su.Modify(x,x,y);
			Sl.Modify(t+1,y,x);
		} else
		{
			int t=Sl.Query(y);printf("%d\n",x-t);
			Su.Modify(t+1,x,y);
			Sl.Modify(y,y,x);
		}
	}
}