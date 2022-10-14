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

vector<int> g[MAXN];
int isfib[MAXN];
int fib[MAXN];
int n;
int flag[MAXN];
int sze[MAXN];
void init()
{
	fib[1]=fib[2]=1;
	isfib[1]=2;
	for (int i=3;i<=30;i++)	
	{
		fib[i]=fib[i-1]+fib[i-2];
		//WRT(fib[i]);
		isfib[fib[i]]=i;
	}
	//WRT(fib[27]);
	LL ans=0;
	for (int i=27;i>=1;i--)
	{
		ans+=fib[i]*(fib[28-i]);
		//WRT( fib[i]*(fib[28-i]));
	}
	//WRT(ans);
}

int fx,fy;
void dfs(int pos,int f,int fibid)
{
	sze[pos]=1;
	for (auto p:g[pos])
	{
		if (p==f || flag[p])
			continue;
		dfs(p,pos,fibid);
		sze[pos]+=sze[p]; 
	}
	//cout<<
	if (sze[pos]==fib[fibid-1])
	{
		fx=pos;
		fy=f;
	}
	if (sze[pos]==fib[fibid-2])
	{
		fx=f;
		fy=pos;
	}
}

bool check(int pos,int f,int fibid)
{
	if (fibid<=3)
		return true;
	fx=fy=0;
	dfs(pos,f,fibid);
	int findx=fx,findy=fy; 
	//cout<<fx<<'-'<<fy<<endl;
	if (findx==0)
		return false;
	flag[findy]++;
	bool f1=check(findx,findy,fibid-1);
	flag[findy]--;
	flag[findx]++;
	bool f2=check(findy,findx,fibid-2);
	flag[findx]--;
	return f1 && f2;
}

void work()
{
	cin>>n;
	int x,y;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if (n<=3)
	{
		cout<<"YES"<<endl;
		return;
	}
	if (!isfib[n])
	{
		cout<<"NO"<<endl;
		return;
	}
	if (check(1,1,isfib[n]))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
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