#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

struct rec
{
	int a,b,c;
};
vector<rec> re;

rec g(int a,int b,int c)
{
	rec tmp;
	tmp.a=a;
	tmp.b=b;
	tmp.c=c;
	return tmp;
}

int x[MAXN];
int n;
void work()
{
	re.clear();
	cin>>n;
	x[0]=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		x[0]+=x[i];
	}
	if (x[0]%n)
	{
		printf("-1\n");
		return;
	}
	x[0]/=n;
	//cout<<2*n-2<<endl;
	for (int i=n;i>=2;i--)
	{
		if (x[i]/i==0)
			continue;
		re.push_back(g(i,1,x[i]/i));
		x[1]+=x[i]-x[i]%i;
		x[i]=x[i]%i;
	}
	vector<pair<int,int> > tmp;
	for (int i=2;i<=n;i++)
		tmp.push_back({i-x[i],i});
	sort(tmp.begin(),tmp.end());
	for (int i=0;i<tmp.size() && re.size()+n+1<=3*n;i++)
	{
		if (x[1]<tmp[i].first)
			break;
		if (x[1]>=n && x[tmp[i].second]<=x[0])
			continue;
		re.push_back(g(1,tmp[i].second,tmp[i].first));
		re.push_back(g(tmp[i].second,1,1));
		x[1]+=x[tmp[i].second];
		x[tmp[i].second]=0;
	}
	for (int i=2;i<=n;i++)
	{
		re.push_back(g(1,i,x[0]-x[i]));
		x[1]-=x[0]-x[i];
		if (x[0]-x[i]<0 || x[1]<0)
		{
			printf("-1\n");
			return;
		}
	}
	cout<<re.size()<<endl;
	for (auto p:re)
		printf("%d %d %d\n",p.a,p.b,p.c);
	
}

int main()
{
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}