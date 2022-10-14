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
vector<int> v;
void work()
{
	cin>>n;
	int x;
	for (int i=0;i<n;i++)
	{
		cin>>x;
		v.push_back(x-1);
	}
	if (n==1)
	{
		cout<<0<<endl;
		return ;
	}
	if (v[n-1]==0)
		cout<<n/2*2-1<<endl;
	else
		cout<<n/2*2<<endl;
		
	//for (auto p:v)
	//	WRT(p);
	//exit(0);
	for (int i=0;i<n/2;i++)
	{
		int p=0;
		vector<int> tmp;
		
		for (;v[p]!=i;p++);
		//WRT(p);
		if (n-(p-i)==1 && i==0)
		{
			
		}
		else
		{
			cout<<n-(p-i)<<' ';
			for (int j=0;j<i;j++)
				cout<<1<<' ';
			cout<<p-i+1<<' ';
			for (int j=p+1;j<n;j++)
				cout<<1<<' ';
			cout<<endl;
		}
		
		for (int j=n-1;j>p;j--)
			tmp.push_back(v[j]);
		for (int j=i;j<=p;j++)
			tmp.push_back(v[j]);
		for (int j=i-1;j>=0;j--)
			tmp.push_back(v[j]);
			
		v=tmp;
		//for (auto p:v) cout<<p<<"  ";
		//cout<<endl;
		tmp.clear();
		p=0;
		
		
		for (;v[p]!=n-i-1;p++);
		cout<<n-(p-i)<<' ';
		for (int j=0;j<i;j++)
			cout<<1<<' ';
		cout<<p-i+1<<' ';
		for (int j=p+1;j<n;j++)
			cout<<1<<' ';
		cout<<endl;
		
		for (int j=n-1;j>p;j--)
			tmp.push_back(v[j]);
		for (int j=i;j<=p;j++)
			tmp.push_back(v[j]);
		for (int j=i-1;j>=0;j--)
			tmp.push_back(v[j]);
			
		
		v=tmp;
		//for (auto p:v) cout<<p<<"  ";
		//cout<<endl;
	}
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