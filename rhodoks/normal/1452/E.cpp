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

int n,m,k;
int l[MAXN],r[MAXN];
template <class DataType> 
class PrefixSum2
{
public:
	vector<DataType> v[2];
	
	PrefixSum2(int n)
	{
		v[0].resize(n+2);
		v[1].resize(n+2);
	}
	
	vector<int> &operator[](int n) 
	{
		return v[n];
	}
	
	DataType query(int x1,int x2)
	{
		if (x1>x2)
			return 0;
		if (x1<=0)
			x1=1;
		if (x2>=v.size())
			x2=v.size()-1;
		return v[x2]-v[x1-1];
	}
	
	void work()
	{
		for (int i=1;i<v[0].size();i++)
		{
			v[1][i]+=v[1][i-1];
			v[0][i]+=v[0][i-1]+v[1][i];
		}
	}
	
	void output()
	{
		for (int i=1;i<v[0].size()-1;i++)
			cout<<v[0][i]<<' ';
		cout<<endl;
	}
	
	void AddApL(int l,int r,int al,int d)
	{
		if (r>=v[0].size())
			r=v[0].size()-1;
		if (l>r)
			return;
		v[0][l]+=al;
		v[0][r+1]-=al+(r-l)*d;
		v[1][l+1]+=d;
		v[1][r+1]-=d;
	}
	
	
	void AddApR(int l,int r,int ar,int d)
	{
		if (l<=0)
			l=1;
		if (l>r)
			return;
		v[0][l]+=ar-(r-l)*d-d;
		v[0][r+1]-=ar;
		v[1][l]+=d;
		v[1][r+1]-=d;
	}
}; 

void work()
{
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
		cin>>l[i]>>r[i];
	int ans=0;
	for (int i=1;i<=n-k+1;i++)
	{
		PrefixSum2<int> ps(n+2);
		for (int j=1;j<=m;j++)
		{
			int tmp1=min(r[j],i+k-1)-max(l[j],i)+1;
			if (tmp1<=0)
				tmp1=0;
			int L,R,x; 
			if (r[j]-l[j]+1>k)
			{
				L=l[j];
				R=r[j]-k+1;
			}
			else
			{
				L=max(1,r[j]-k+1);
				R=l[j];
			}
			x=min(r[j]-l[j]+1,k);
			ps.AddApL(L,R,max(x,tmp1),0);
			//WRT(tmp1)
			//WRT(x);
			if (tmp1>=x)
			{
				ps.AddApL(R+1,n,tmp1,0);
				ps.AddApR(1,L-1,tmp1,0);
			}
			else
			{
				ps.AddApL(R+1,R+x-tmp1,x-1,-1);
				ps.AddApL(R+x-tmp1+1,n,tmp1,0);
				
				ps.AddApR(L-(x-tmp1),L-1,x-1,1);
				ps.AddApR(1,L-(x-tmp1)-1,tmp1,0);
			}
		}
		ps.work();
		for (int i=1;i<=n;i++)
			ans=max(ans,ps[0][i]);
	}
	cout<<ans<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}