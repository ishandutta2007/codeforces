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

char s[510][510];
int n,m;
void init()
{

}

void work()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		scanf("%s",s[i]);
	if (n==1)
	{
		for (int i=0;i<m;i++)
			putchar('X');
		putchar('\n');
		return;
	}
	for (int i=1;i<n;i+=3)
	{
		for (int j=0;j<m;j++)
			if (s[i][j]=='.')
				s[i][j]='F';
		bool f=false;
		if (i>1)
		{
			for (int j=0;j<m;j++)
				if (s[i-1][j]=='X')
				{
					s[i-2][j]='X';
					f=true;
					break;
				}
			if (!f)
			{
				for (int j=0;j<m;j++)
					if (s[i-2][j]=='X')
					{
						s[i-1][j]='X';
						f=true;
						break;
					}
			}
			if (!f)
				s[i-1][0]=s[i-2][0]='X';
		}
			
		//for (int 
	}
	if (n%3==1)
	{
		for (int i=0;i<m;i++)
			s[n-1][i]='F';
		vector<int> v;
		for (int j=0;j<m;j++)
			if (s[n-2][j]=='X')
				v.push_back(j);
		for (int j=1;j<v.size();j++)
			s[n-1][v[j]-1]='.';
		if (v.size()==0)
			s[n-2][0]='F';
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (s[i][j]=='F')
				s[i][j]='X';
	for (int i=0;i<n;i++)
		printf("%s\n",s[i]);
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