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
int visit[510][510];
vector<int> Hpath;
int query1(int x,int y)
{
	cout<<1<<' '<<x<<' '<<y<<endl;
	fflush(stdout);
	int ans;
	cin>>ans;
	return ans;
}
 
 
int query2(int x,int y)
{
	cout<<2<<' '<<x<<' '<<y+1<<' ';
	for (int i=0;i<=y;i++)
		cout<<Hpath[i]<<' ';
	cout<<endl;
	fflush(stdout);
	int ans;
	cin>>ans;
	return ans;
}
 
vector<int> divide_and_conquer(int l,int r)
{
	if (l==r)
		return vector<int>({l});
	if (r==l+1)
		return query1(l,l+1) ? vector<int>({l,l+1}): vector<int>({l+1,l});
	int mid=(l+r)/2;
	vector<int> v1=divide_and_conquer(l,mid);
	vector<int> v2=divide_and_conquer(mid+1,r);
	vector<int> ans;
	while (!v1.empty() || !v2.empty())
	{
		if (v1.empty())
		{
			ans.push_back(v2.back());
			v2.pop_back();
			continue;
		}
		if (v2.empty())
		{
			ans.push_back(v1.back());
			v1.pop_back();
			continue;
		}
		if (query1(v1.back(),v2.back()))
		{
			ans.push_back(v2.back());
			v2.pop_back();
		}
		else
		{
			ans.push_back(v1.back());
			v1.pop_back();
		}
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
 
void init()
{
	
}
 
void work()
{
	cin>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			visit[i][j]=0;
	Hpath=divide_and_conquer(0,n-1);
	int ptr=n-1;
	int lst=n-1;
	for (int i=n-1;i>=0;i--)
	{
		WRT(i);
		for (int j=i;j<n;j++)
			visit[Hpath[i]][Hpath[j]]=1;
		while (ptr>0 && query2(Hpath[i],ptr-1))
			ptr--;
		if (i==ptr)
		{
			for (int i1=i;i1<=lst;i1++)
				for (int j1=i;j1<=lst;j1++)
					visit[Hpath[i1]][Hpath[j1]]=1;
			lst=i-1;
			ptr=i-1; 
		}
	}
	cout<<3<<endl; 
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
			putchar('0'+visit[i][j]);
		cout<<endl;
	}
	fflush(stdout);
	int ans;
	cin>>ans;
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