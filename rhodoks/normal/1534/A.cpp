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

#define MAXN 510
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

char s[MAXN][MAXN]; 
char t[2];
int n,m;
void init()
{

}

void work()
{
	cin>>n>>m;
	for (int i=0;i<n;i++)
		cin>>s[i];
	int cnt[2][2]={{0,0},{0,0}};
	char t[3];
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			if (s[i][j]=='R')
				cnt[0][(i+j)%2]++;
			if (s[i][j]=='W') 
				cnt[1][(i+j)%2]++;
		}
	if (cnt[0][0] && cnt[1][0])
	{
		cout<<"NO\n";
		return;
	}
	if (cnt[0][0] && cnt[0][1])
	{
		cout<<"NO\n";
		return;
	}
	if (cnt[1][0] && cnt[1][1])
	{
		cout<<"NO\n";
		return;
	}
	if (cnt[0][1] && cnt[1][1])
	{
		cout<<"NO\n";
		return;
	}
	if (cnt[0][0] || cnt[1][1])
	{
		t[0]='R';
		t[1]='W';
	}
	else 
	{
		t[0]='W';
		t[1]='R';
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			s[i][j]=t[(i+j)%2];
	cout<<"YES\n";
	for (int i=0;i<n;i++)
		cout<<s[i]<<'\n';
		
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