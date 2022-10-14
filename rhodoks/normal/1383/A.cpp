#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

class Union_Find_Set 
{
	int *pa;
	
	
public:
	int getpa(int x)
	{
		return pa[x]==x ? x:(pa[x]=getpa(pa[x]));
	}
	
	Union_Find_Set(int set_size=MAXN)
	{
		pa=new int[set_size+2];
	}
	
	~Union_Find_Set()
	{
		delete pa;
	}
	
	void init(int n)
	{
		for (int i=0;i<=n;i++)
			pa[i]=i;
	}
	
	void merge(int x,int y)
	{
		pa[getpa(x)]=getpa(y);
	}
	
	bool query(int x,int y)
	{
		return getpa(x)==getpa(y);
	}
};
typedef Union_Find_Set UFS;

int n;
char A[MAXN],B[MAXN];
int to[21][21];


void work()
{
	scanf("%d%s%s",&n,A,B);
	MST(to,0);
	UFS ufs(20);
	ufs.init(20);
	for (int i=0;i<n;i++)
		to[A[i]-'a'][B[i]-'a']|=1;
	int ans=0;
	for (int i=0;i<20;i++)
		for (int j=0;j<20;j++)
		{
			if (i==j)
				continue;
			if (to[i][j] && i>j)
			{
				printf("-1\n");
				return;
			}
			if (to[i][j] && i<j)
			{
				if (!ufs.query(i,j))
				{
					ufs.merge(i,j);
					ans++;
				}
			}
		}
	printf("%d\n",ans);
}

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		work();
		
	} 
	return ~~(0^_^0);
}