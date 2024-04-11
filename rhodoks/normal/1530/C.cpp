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

void init()
{

}

void work()
{
	int n,N;
	cin>>n;
	N=n;
	int x,y;
	priority_queue<int,vector<int>,greater<int> > pq1,pq2;
	priority_queue<int,vector<int>,less<int> > pq3;
	int sum1=0,sum2=0;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&x);
		pq1.push(x);
		sum1+=x;
	}
	for (int i=0;i<n;i++)
	{
		scanf("%d",&x);
		pq2.push(x);
		sum2+=x;
	}
	while (pq1.size()>n-n/4)
	{
		sum1-=pq1.top();
		pq1.pop();
	}
	pq3.push(-INF);
	while (pq2.size()>n-n/4)
	{
		sum2-=pq2.top();
		WRT(pq2.top());
		pq3.push(pq2.top());
		pq2.pop();
	}
	WRT(pq1.top());
	WRT(pq2.top());
	WRT(pq3.top());
	while (sum1<sum2)
	{
		pq1.push(100);
		pq2.push(0);
		sum1+=100;
		n++;
	while (pq1.size()>n-n/4)
	{
		sum1-=pq1.top();
		pq1.pop();
	}
	while (pq2.size()>n-n/4)
	{
		sum2-=pq2.top();
		pq3.push(pq2.top());
		pq2.pop();
	}
	WRT(pq2.top())
	WRT(pq3.top());
	while (pq2.top()<pq3.top())
	{
		int x=pq2.top();
		int y=pq3.top();
		sum2-=x;
		sum2+=y;
		pq2.pop();
		pq3.pop();
		pq2.push(y);
		pq3.push(x);
	}
	WRT(sum1)
	WRT(sum2);
	}
	cout<<n-N<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}