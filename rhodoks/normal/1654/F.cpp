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

int rk[20][MAXN];
int n;
string s;
int it;
int a1[MAXN],a2[MAXN];
bool cmp(int x,int y)
{
	return make_pair(a1[x],a2[x])<make_pair(a1[y],a2[y]);
}

void init()
{

}

void work()
{
	MST(rk,-1);
	cin>>n>>s;
	int N=n;
	n=(1<<n);
	vector<int> buc(27);
	for (auto p:s)
		buc[p-'a'+1]++;
	for (int i=1;i<26;i++)
		buc[i]+=buc[i-1];
	for (int i=0;i<n;i++)
		rk[0][i]=buc[s[i]-'a'];
	for (it=1;it<=N;it++)
	{
		vector<int> v(n);
		for (int i=0;i<n;i++)
		{
			v[i]=i;
			a1[i]=rk[it-1][i];
			a2[i]=rk[it-1][i^(1<<(it-1))];
		}
		sort(v.begin(), v.end(),cmp);
		rk[it][v[0]]=0;
		for (int i=1;i<n;i++)
			if (a1[v[i]]==a1[v[i-1]] && a2[v[i-1]]==a2[v[i]])
				rk[it][v[i]]=rk[it][v[i-1]];
			else
				rk[it][v[i]]=i;
	}
	for (int i=0;i<n;i++)
		if (rk[N][i]==0)
		{
			for (int j=0;j<n;j++)
				putchar(s[j^i]);
			return ;
		}
}

int main()
{
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