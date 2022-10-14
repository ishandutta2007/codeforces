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
int a[MAXN];
int buc[101];
int ttt[401000];
int *f=ttt+200100;
int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	int mxnum=0;
	int mxcnt=0;
	int mx=-1;
	for (int i=0;i<n;i++)
	{
		buc[a[i]]++;
		if (buc[a[i]]>mxcnt)
		{
			mxnum=1;
			mxcnt++;
			mx=a[i]; 
		}
		else if (buc[a[i]]==mxcnt)
		{
			mxnum++;
		}
	}
	WRT(mxnum)
	if (mxnum>=2)
	{
		cout<<n<<endl;
		return 0;
	}
	int ans=0;
	WRT(mx)
	for (int i=1;i<=100;i++)
	{
		if (i==mx)
			continue;
		int sum=0;
		for (int i=0;i<n;i++)
		{
			f[0-i-1]=f[0+i+1]=INF;
		}
		f[0]=-1;
		for (int j=0;j<n;j++)
		{
			if (a[j]==i)
				sum++;
			if (a[j]==mx)
				sum--; 
			//WRT(j)
			//WRT(f[sum])
			ans=max(ans,j-f[sum]);
			if (f[sum]==INF)
				f[sum]=j;
		}
	}
	cout<<ans<<endl;
	return ~~(0^_^0);
}