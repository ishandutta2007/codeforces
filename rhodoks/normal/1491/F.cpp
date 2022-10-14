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

int n,querycnt;
int ans[MAXN];
void init()
{

}

int query(int l1,int r1,int l2,int r2)
{
	querycnt++;
	cout<<"? "<<r1-l1+1<<' '<<r2-l2+1<<endl;
	for (int i=l1;i<=r1;i++)
		cout<<i<<' ';
	cout<<endl;
	for (int i=l2;i<=r2;i++)
		cout<<i<<' ';
	cout<<endl;
	int x;
	cin>>x;
	return x;
}

void work()
{
	querycnt=0;
	cin>>n;
	for (int i=1;i<=n;i++)
		ans[i]=0;
	int ptr=1;
	int cnt=0;
	for (ptr=1;ptr<n;ptr++)
		if (cnt=query(ptr,ptr,ptr+1,n))
			break;
	for (int i=1;i<ptr;i++)
		ans[i]=1;
	for (int i=ptr+1;i<n;i++)
	{
		int tmp=query(ptr,ptr,i,i);
		cnt-=tmp;
		if (tmp==0)
			ans[i]=1;
	}
	if (cnt==0)
		ans[n]=1;
	if (ptr>1)
	{
		int l=1;
		int r=ptr;
		while (l<r)
		{
			int mid=(l+r)/2;
			if (mid==ptr)
				break;
			if (query(1,mid,ptr,ptr))
				r=mid;
			else
				l=mid+1;
		}
		ans[r]=0;
	}
	cnt=0;
	cout<<"! ";
	for (int i=1;i<=n;i++)
		if (ans[i])
			cnt++;
	cout<<cnt<<' ';
	for (int i=1;i<=n;i++)
		if (ans[i])
			cout<<i<<' ';
	cout<<endl;
	WRT(querycnt);
}

int main()
{
	#ifdef _DEBUG_
	//freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
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