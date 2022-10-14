#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 510000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int fa[MAXN];
int getfa(int i)
{
	if (i==fa[i])
		return i;
	else
		return fa[i]=getfa(fa[i]);
}

void merge(int i,int j)
{
	//cout<<i<<'-'<<j<<endl;
	fa[getfa(i)]=getfa(j);
}

int num[MAXN];

int main()
{
	RPT(i,0,MAXN)
		fa[i]=i;
	int n,m;
	cin>>n>>m;
	RPT(i,0,m)
	{
		int k;
		cin>>k;
		if (k==0)
			continue;
		int last,x;
		scanf("%d",&last);
		RPT(i,0,k-1)
		{
			scanf("%d",&x);
			merge(x,last);
			last=x;
		}
	}
	//MRK();
	RPT(i,1,n+1)
	{
		//WRT(getfa(i));
		num[getfa(i)]++;
	}
	RPT(i,1,n+1)
		printf("%d ",num[getfa(i)]);
	
	return ~~(0^_^0);
}