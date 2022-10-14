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
#define MOD1 998244353  
#define MOD2 1000000007
#define BASE1 19260817
#define BASE2 19491001
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,m;
vector<vector<int> > v;
unordered_map<LL,int> mp;
void init()
{

}

void insert(vector<int> &v)
{
	for (int i=0;i<(1<<m);i++)
	{
		LL m1=0,m2=0;
		for (int j=0;j<m;j++)
			if (i&(1<<j))
			{
				m1=(m1*BASE1+v[j+1])%MOD1;
				m2=(m2*BASE2+v[j+1])%MOD2;
			}
		mp[m1*m2]++;
	}
}


void erase(vector<int> &v)
{
	for (int i=0;i<(1<<m);i++)
	{
		LL m1=0,m2=0;
		for (int j=0;j<m;j++)
			if (i&(1<<j))
			{
				m1=(m1*BASE1+v[j+1])%MOD1;
				m2=(m2*BASE2+v[j+1])%MOD2;
			}
		mp[m1*m2]--;
	}
}

int check(vector<int> &v)
{
	int ans=0;
	for (int i=0;i<(1<<m);i++)
	{
		LL m1=0,m2=0;
		for (int j=0;j<m;j++)
			if (i&(1<<j))
			{
				m1=(m1*BASE1+v[j+1])%MOD1;
				m2=(m2*BASE2+v[j+1])%MOD2;
			}
		if (__builtin_popcount(i)%2)
			ans-=mp[m1*m2];
		else
			ans+=mp[m1*m2];
		//if (mp[tmp])
		//	cout<<i<<' '<<mp[tmp]<<endl;
	}
	return ans;
}

void work()
{
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		v.push_back(vector<int>(m+1));
		for (int j=0;j<=m;j++)
			scanf("%d",&v.back()[j]);
		swap(v.back()[0],v.back()[m]);

		//for (auto p:v.back())
		//	cout<<p<<' ';
		//cout<<endl;

		sort(v.back().begin()+1, v.back().end());
	}
	sort(v.begin(), v.end());
	int ptr=0;
	int ans=INF*2;
	for (ptr=0;ptr<n;ptr++)
	{
		if (!check(v[0]))
			insert(v[ptr]);
		else
		{
			ans=min(ans,v[ptr][0]+v[0][0]);
			break;
		}
	}
	ptr--;
	for (int i=1;i<n;i++)
	{
		while (ptr>=0 && v[i][0]+v[ptr][0]>=ans)
			erase(v[ptr--]);
		WRT(i)
		WRT(ptr)
		if (ptr>=0)
		{
			//WRT(check(v[i]))
			if (check(v[i]))
			{
				erase(v[ptr--]);
				while (check(v[i]))
					erase(v[ptr--]);
				insert(v[++ptr]);
				ans=min(ans,v[i][0]+v[ptr][0]);
			}
		}

	}
	if (ans==2*INF)
		ans=-1;
	cout<<ans<<endl;
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