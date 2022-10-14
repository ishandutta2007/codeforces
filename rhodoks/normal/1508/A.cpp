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

string s[3];
int n;
void init()
{

}

void work()
{
	cin>>n;
	cin>>s[0]>>s[1]>>s[2];
	int ptr[3]={0,0,0};
	string ans;
	while (ptr[0]<2*n&&ptr[1]<2*n&&ptr[2]<2*n)
	{
		if (s[0][ptr[0]]==s[1][ptr[1]])
		{
			ans.push_back(s[0][ptr[0]]);
			ptr[0]++,ptr[1]++;
		}
		else if (s[0][ptr[0]]==s[2][ptr[2]])
		{
			ans.push_back(s[0][ptr[0]]);
			ptr[0]++,ptr[2]++;
		}
		else if (s[1][ptr[1]]==s[2][ptr[2]])
		{
			ans.push_back(s[1][ptr[1]]);
			ptr[1]++,ptr[2]++;
		}
	}
	int cnt=0;
	for (int i=0;i<3;i++)
	{
		if (ptr[i]==2*n)
			cnt++;
	}
	if (cnt==1)
	{
		for (int i=1;i<3;i++)
			if (ptr[i]==2*n)
			{
				swap(ptr[i],ptr[0]);
				swap(s[i],s[0]);
			}
		int id=ptr[1]>ptr[2]?1:2;
		for (int i=ptr[id];i<2*n;i++)
			ans.push_back(s[id][i]);
	}
	cout<<ans<<endl;
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