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
	
#define int LL
	
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
		if (x==0)
			return query(y);
		return query(y)-query(x-1);
	}
};
#define BIT BinaryIndexTree
int n;
LL a[MAXN];
LL sum[MAXN];
BIT<LL> bit1,bit2;
void init()
{

}

void work()
{
	cin>>n;
	LL ans=0;
	LL sum=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		ans+=(LL)a[i]*(i-1)+sum;
		ans+=bit1.query(1,a[i]);
		for (int k=a[i];k-a[i]<=300100;k+=a[i])
		{
			ans+=bit2.query(k-a[i],k-1)*(k/a[i]-1)*a[i];
		}
		for (int k=a[i];k<=300100;k+=a[i])
			bit1.add(k,-a[i]);
		bit2.add(a[i],-1);
		sum+=a[i];
		printf("%lld ",ans);
	}
}

signed main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
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