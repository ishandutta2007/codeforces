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

#define MAXN 500100
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int x,y;
int a[MAXN<<1];
int l[MAXN],r[MAXN];
int pa[MAXN];
int ord[MAXN];

bool cmp(int x,int y)
{
	return l[x]<l[y];
}

int getpa(int x)
{
	return pa[x]==x ? x:pa[x]=getpa(pa[x]);
}

void merge(int x,int y)
{
	pa[getpa(x)]=getpa(y);
}

bool query(int x,int y)
{
	return getpa(x)==getpa(y);
}

int edge_cnt=0; 

set<int> st;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		pa[i]=i;
		scanf("%d%d",&l[i],&r[i]);
		a[l[i]]=-i;
		a[r[i]]=i;
		ord[i]=i;
	}
	sort(ord+1,ord+n+1,cmp);
	for (int j=1;j<=n;j++)
	{
		int i=ord[j];
		//cout<<l[i]<<'-'<<r[i]<<endl;
		while (*st.begin()<l[i] && st.size()>0)
			st.erase(st.begin());
		for (auto p:st)
		{
			if (p>r[i])
				break;
			//MRK();
			if (query(i,a[p]))
			{
				cout<<"NO";
				return 0;
			}
			merge(i,a[p]);
			edge_cnt++;
			if (edge_cnt>=n)
			{
				cout<<"NO";
				return 0;
			}
		}
		st.insert(r[i]);
	}
	for (int i=2;i<=n;i++)
		if (!query(1,i))
			{
				cout<<"NO";
				return 0;
			}
	cout<<"YES";
	return ~~(0^_^0);
}