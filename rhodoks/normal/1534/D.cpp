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
int ans[MAXN];
int fxxk[MAXN];
void init()
{

}

void query(int pos)
{
	cout<<"? "<<pos<<endl;
	for (int i=1;i<=n;i++)
		scanf("%d",&ans[i]);
}
typedef pair<int,int> pii;
set<pii> st;
int visit[MAXN];
pii getpii(int x,int y)
{
	if (x>y)
		return {y,x};
	return {x,y};	
}
void work()
{
	cin>>n;
	query(1);
	for (int i=1;i<=n;i++)
		fxxk[i]=ans[i];
	int cnt[2]={0,0};
	for (int i=1;i<=n;i++)
	{
		cnt[ans[i]&1]++;
		if (ans[i]==1)
			st.insert({getpii(1,i)});
	}
	cnt[0]--;
	int tar=0;
	if (cnt[0]<cnt[1])
		tar=0;
	else
		tar=1;
	for (int i=2;i<=n;i++)
		if (fxxk[i]%2==tar)
		{
			query(i);
			int pos=i;
			for (int j=1;j<=n;j++)
				if (ans[j]==1)
					st.insert(getpii(pos,j));
		}
	cout<<"!"<<endl;
	for (auto p:st)
		cout<<p.first<<' '<<p.second<<endl;
}

int main()
{
	#ifdef _DEBUG_
	//freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}