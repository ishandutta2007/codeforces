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

int permutation[MAXN];
int p[MAXN];
int n,m;
LL fac[MAXN];
LL id;
LL sum[MAXN];
int visit[MAXN];
void gen(LL id)
{
	LL tmp=id;
	for (int i=1;i<=m;i++)
		visit[i]=0;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
			if (!visit[j])
				if (tmp>=fac[m-i])
				{
					tmp-=fac[m-i];
				}
				else
				{
					p[i]=j+n-m;
					sum[i+n-m]=sum[i+n-m-1]+p[i];
					visit[j]=1;
					break;
				}
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	fac[0]=1;
	for (int i=1;i<22;i++)
		fac[i]=fac[i-1]*i;
	for (int i=1;i<=22;i++)
		permutation[i]=i;
	/*
	m=20;
	gen(19);
	for (int i=1;i<=m;i++)
		cout<<p[i]<<' ';
	cout<<endl;
	for (int i=1;;i++)
	{
		next_permutation(permutation+1,permutation+21);
		cout<<i<<'\t';
		for (int i=1;i<=20;i++)
			cout<<permutation[i]<<' ';
		cout<<endl;
	}
	return 0;
	*/
	cin>>n;
	for (int i=1;i<=n;i++)
		sum[i]=sum[i-1]+i;
	m=min(n,20);
	int t;
	cin>>t;
	int op,x,y;
	while (t--)
	{
		scanf("%d%d",&op,&x);
		if (op==1)
		{
			scanf("%d",&y);
			gen(id);
			printf("%lld\n",sum[y]-sum[x-1]);
		}
		else
		{
			id+=x;
		}
	}
	return ~~(0^_^0);
}