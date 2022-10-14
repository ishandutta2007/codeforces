#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
LL a[MAXN];
int id[MAXN];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
LL w,c;
void work()
{
	scanf("%d%lld",&n,&w);
	c=(w+1)/2;
	for (int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		id[i]=i;
	}
	sort(id,id+n,cmp);
	LL sum=0;
	int i;
	for (i=0;i<n;i++)
	{
		sum+=a[id[i]];
		if (sum>=c)
			break;
	}
	int tmp=i;
	if (sum>=w)
	{
		if (a[id[i]]>=c && a[id[i]]<=w)
			printf("%d\n%d\n",1,id[i]+1);
		else
			printf("-1\n");
	}
	else if (sum>=c)
	{
		printf("%d\n",i+1);
		for (int i=0;i<=tmp;i++)
			printf("%d ",id[i]+1);
	}
	else
	{
		printf("-1\n");
	}
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}