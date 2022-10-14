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

#define MAXN 210000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5
#define B 800
#define _ 0
using namespace std;

template <class DataType> 
class BinaryIndexTree
{
public:
	vector<DataType> bit;
	
	BinaryIndexTree(int _size=MAXN)
	{
		bit.resize(_size+2);
	}
	
	int lowbit(int x)
	{
		return x&-x;
	}
	
	void add(int x,int a)
	{
		for (;x<bit.size();x+=lowbit(x))
			bit[x]+=a;
	}
	
	DataType query(int x)
	{
		DataType ans=0;
		for (;x;x-=lowbit(x))
			ans+=bit[x];
		return ans;
	}
	
	DataType query(int x,int y)
	{
		return query(y)-query(x-1);
	}
};
#define BIT BinaryIndexTree

BIT<int> bit;
vector<int> buc[MAXN];
int n,m;
int x[MAXN],y[MAXN];
int rec[MAXN];
void init()
{
	for (int i=1;i<=B;i++)
		buc[i].resize(B);
}

void work()
{
	BIT<int> bit(MAXN);
	cin>>n>>m;
	int op,v;
	for (int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&op,&v);
		int w=3-op*2;
		//cout<<v<<' '<<w<<'!'<<endl;
		if (op==1)
			rec[v]=i;
		if (x[v]+y[v]<=B)
		{
			int beg=(rec[v]+x[v])%(x[v]+y[v]);
			//cout<<"beg"<<beg<<' '<<x[v]+y[v]<<endl;
			if (beg+y[v]-1<x[v]+y[v])
			{
				for (int j=beg;j<=beg+y[v]-1;j++)
					buc[x[v]+y[v]][j]+=w;
			}
			else
			{
				for (int j=beg;j<x[v]+y[v];j++)
					buc[x[v]+y[v]][j]+=w;
				for (int j=0;j<=beg+y[v]-1-(x[v]+y[v]);j++)
					buc[x[v]+y[v]][j]+=w;
				//for (int j=0;j<x[v]+y[v];j++)
				//	cout<<buc[x[v]+y[v]][j];
				//cout<<endl;
			}
		}
		else
		{
			int beg=rec[v]+x[v];
			while (beg<m)
			{
				bit.add(beg,w);
				bit.add(beg+y[v],-w);
				beg+=x[v]+y[v];
			}
		}
		int ans=0;
		for (int j=2;j<=B;j++)
			ans+=buc[j][i%j];
		//cout<<ans<<' ';
		ans+=bit.query(i);
		printf("%d\n",ans);
	}
}

int main()
{
	//freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	init();
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}