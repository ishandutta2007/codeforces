#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int ok[550];
int n,m;
int a[310000][9];
int fmsk;
void setok(int x,int id)
{
	if (ok[x])
		return;
	ok[x]=id;
	for (int i=0;i<m;i++)
		if ((x&(1<<i))==0)
			setok(x^(1<<i),id);
}

int id1,id2;

bool check(int x)
{
	MST(ok,0);
	for (int i=1;i<=n;i++)
	{
		int tmp=0;
		for (int j=0;j<m;j++)
			if (a[i][j]>=x)
				tmp^=(1<<j);
		setok(fmsk^tmp,i);
		if (ok[tmp])
		{
			//WRT(tmp);
			id1=ok[tmp];
			id2=i;
			return true;
		}
	}
	return false;
}

int main()
{
	cin>>n>>m;
	fmsk=(1<<m)-1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	int l=0,r=1e9+7;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (check(mid))
			l=mid+1;
		else
			r=mid;
		//WRT(mid);
	}
	cout<<id1<<' '<<id2<<endl;
	return ~~(0^_^0);
}