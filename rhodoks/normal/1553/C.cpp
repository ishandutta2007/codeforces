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
void init()
{

}

void work()
{
	cin>>s;
	int ans=10;
	int score[2]={0,0};
	int left[2]={5,5}; 
	for (int i=0;i<10;i++)
		s[i]-='0';
	for (int i=0;i<10;i++)
	{
		left[i&1]--;
		if (s[i]=='?'-'0')
			score[i&1]+=(i&1);
		else
			score[i&1]+=(s[i]);
		if (score[0]+left[0]<score[1] || score[1]+left[1]<score[0])
		{
			ans=min(ans,i+1);
		}
	}
	score[0]=0;
	score[1]=0;
	left[0]=left[1]=5;
	for (int i=0;i<10;i++)
	{
		left[i&1]--;
		if (s[i]=='?'-'0')
			score[i&1]+=(i&1)^1;
		else
			score[i&1]+=(s[i]);
		if (score[0]+left[0]<score[1] || score[1]+left[1]<score[0])
		{
			ans=min(ans,i+1);
		}
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