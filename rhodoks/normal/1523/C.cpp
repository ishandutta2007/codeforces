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
int a;
vector<int> ans;

void output()
{
	for (int i=0;i<ans.size()-1;i++)
		cout<<ans[i]<<'.';
	cout<<ans[ans.size()-1]<<endl;
}
void init()
{

}

stack<int> rec;
void work()
{
	cin>>n;
	ans.clear();
	cin>>a;
	ans.push_back(1);
	output();
	int forbid;
	for (int i=1;i<=n-1;i++)
	{
		forbid=-1;
		cin>>a;
		while (1)
		{
			if (a==1 && a!=forbid)
			{
				rec.push(0);
				ans.push_back(1);
				output();
				break;
			}
			if (a==ans.back()+1  && a!=forbid)
			{
				rec.push(ans.back());
				ans.pop_back();
				ans.push_back(a);
				output();
				break;
			}
			assert(rec.size());
			//while (rec.top()!=0)
			ans.pop_back();
			/*
			if (rec.top()!=-1)
				ans.push_back(rec.top());
			if (forbid==-1)
				forbid= rec.top() == -1 ? 1 : rec.top()+1;
			rec.pop();
			*/
		}
	}
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