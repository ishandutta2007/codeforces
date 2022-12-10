#include<set>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Mp make_pair
#define Update(x) for (int i=L[b[x]];i<=R[b[x]];i++) P[i]=Mp(A[i],i);\
	sort(P+L[b[x]],P+R[b[x]]+1);
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=5e5+19,Sc=800;
typedef long long LL;
typedef int one[N];
typedef pair<LL,int> Pli;
Pli P[N];Pli p;
LL A[N],D[Sc];
int b[N],L[Sc],R[Sc];
int n,Q,S,t,Ql,Qr,x,Min,Max;

int main()
{
	memset(L,60,sizeof(L));
	n=IN(),Q=IN(),S=sqrt(n)+1;
	For(i,1,n+1) t=b[i]=(i-1)/S+1,L[t]=min(L[t],i),R[t]=max(R[t],i);
	For(i,1,n+1) A[i]=IN(),P[i]=Mp(A[i],i);
	For(i,1,t+1) sort(P+L[i],P+R[i]+1);
	while (Q--)
		if (IN()==1)
		{
			Ql=IN(),Qr=IN(),x=IN();
			if (b[Ql]==b[Qr])
			{
				For(i,Ql,Qr+1) A[i]+=x;
				Update(Ql);
			} else
			{
				for (int i=Ql;i<=R[b[Ql]];i++) A[i]+=x;
				for (int i=L[b[Qr]];i<=Qr;i++) A[i]+=x;
				Update(Ql);Update(Qr);
				For(i,b[Ql]+1,b[Qr]) D[i]+=x;
			}
		} else
		{
			x=IN(),Min=n+1,Max=0;
			for (int i=1;i<=t;i++)
				if (p=P[lower_bound(P+L[i],P+R[i]+1,Mp(x-D[i],0))-P],p.first==x-D[i]) {Min=p.second;break;}
			for (int i=t;i>=1;i--)
				if (p=P[upper_bound(P+L[i],P+R[i]+1,Mp(x-D[i]+1,0))-P-1],p.first==x-D[i]) {Max=p.second;break;}
			printf("%d\n",Min<=Max?Max-Min:-1);
		}
}