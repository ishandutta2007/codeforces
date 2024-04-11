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


char s[MAXN];
int len,m;
void init()
{

}

bool iter()
{
	for (int i=1;i<=len;i++)
		if (s[i]=='0' && (s[i-1]=='1' && s[i+1]!='1'
		||  s[i+1]=='1' && s[i-1]!='1') )
			s[i]='2';
	bool flag=false;
	for (int i=1;i<=len;i++)
		if (s[i]=='2')
		{
			s[i]='1';
			flag=true;
		}
	return flag;
}

void work()
{
	cin>>len>>m>>(s+1);
	while (m--)
	{
		if (!iter())
			break;
	}
	printf("%s\n",s+1);
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