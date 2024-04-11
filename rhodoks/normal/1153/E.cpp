#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=x;i<y;i++)
#define DRPT(i,x,y) for (REG int i=x;i>y;i--)
#define MST(a,b) memset(a,b,sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<x<<endl;

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int main()
{
	int x1=-1,x2=-1;
	int n;
	int ans;
	cin>>n;
	RPT(i,1,n)
	{
		printf("? %d %d %d %d\n",1,i,n,i);
		fflush(stdout);
		scanf("%d",&ans);
		if (ans%2==1)
			if (x1==-1)
				x1=i;
			else
				x2=i;
	}
	if (x1!=-1 && x2==-1)
		x2=n;
		
	
	if (x1!=-1)
	{
		int f1,f2;
		int l,r,mid;
		l=1;
		r=n;
		while (l<r)
		{
			mid=(l+r)/2;
			printf("? %d %d %d %d\n",l,x1,mid,x1);
			fflush(stdout);
			scanf("%d",&ans);
			if (ans%2==1)
				r=mid;
			else
				l=mid+1;
		}
		f1=l;
		l=1;
		r=n;
		while (l<r)
		{
			mid=(l+r)/2;
			printf("? %d %d %d %d\n",l,x2,mid,x2);
			fflush(stdout);
			scanf("%d",&ans);
			if (ans%2==1)
				r=mid;
			else
				l=mid+1;
		}
		f2=l;
		printf("! %d %d %d %d\n",f1,x1,f2,x2);
		fflush(stdout);
		return 0;
	}
	x1=-1;
	x2=-1;
	RPT(i,1,n)
	{
		printf("? %d %d %d %d\n",i,1,i,n);
		fflush(stdout);
		scanf("%d",&ans);
		if (ans%2==1)
			if (x1==-1)
				x1=i;
			else
				x2=i;
	}
	if (x1!=-1 && x2==-1)
		x2=n;
	int f1,f2;
	int l,r,mid;
	l=1;
	r=n;
	while (l<r)
	{
		mid=(l+r)/2;
		printf("? %d %d %d %d\n",x1,l,x1,mid);
		fflush(stdout);
		scanf("%d",&ans);
		if (ans%2==1)
			r=mid;
		else
			l=mid+1;
	}
	f1=l;
	printf("! %d %d %d %d\n",x1,l,x2,l);
	fflush(stdout);
	

	return ~~(0^_^0);
}