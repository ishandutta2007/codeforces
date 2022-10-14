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

int n,k;

int cnt[MAXN];
queue<int> q;
void init()
{

}
vector<vector<int> > v;
int query(vector<int> v)
{
	cout<<"?";
	for (auto p:v)
		cout<<' '<<p;
	cout<<endl;
	int ans=0;
	cin>>ans;
	return ans;
	
}
void work()
{
	cin>>n>>k;
	for (int i=1;i<=2*n+2;i++)
	{
		bool ok=0;
		for (int j=1;j*n<=i*k;j+=2)
		{
			//cout<<i<<' '<<j<<endl;
			if (i*k-j*n>=2*n)
				continue;
			WRT(1);
			if ((i*k-j*n)%2==1)
				continue;
			WRT(2);
			if (i*k-j*n!=0 && j+2>i)
				continue;
			ok=1;
			for (int p=1;p<=n;p++)
				cnt[p]=j;
			for (int p=1;p<=(i*k-j*n)/2;p++)
				cnt[p]+=2;
		}
		/*
		if ((k*i/n)%2==1 && (k*i%n)%2==0 && (k*i%n==0 || k*i/n+2<=i))
		{
			WRT(i);
			//for (int i=1;i<=n;i++)
			//	cnt[i]+=k*i/n;
			//for (int i=1;i<=k*i%n;i++)
			//	cnt[i]++;
		}
		*/
		if (ok)
		{
			WRT(i);
			v.resize(i);
			int ptr=0;
			for (int j=1;j<=n;j++)
				while (cnt[j]--)
				{
					v[ptr].push_back(j);
					ptr=(ptr+1)%i;
				}
			int xorsum=0;
			for (auto p:v)
				xorsum^=query(p);
			cout<<"! "<<xorsum<<endl;
			return ;
		}
	}
	cout<<-1<<endl;
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