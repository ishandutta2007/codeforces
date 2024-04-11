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
 
int n;
int a[MAXN];
vector<pair<int,int> > v;
int col[MAXN];
queue<int> q[4];
 
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int pu=n;
	int pl=1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==1)
		{
			col[i]=pl;
			v.push_back({pl++,i});
			q[1].push(i);
		}
	}
	vector<int> tt;
	int fxxk=-1; 
	for (int i=1;i<=n;i++)
		if (a[i]>=2)
		{
			if (a[i]==3)
			{
				tt.push_back(i);
				fxxk=i;
			}
			else
				q[2].push(i);
		}
	vector<int> gg;
	while (!q[2].empty())
	{
		int tmp=q[2].front();
		q[2].pop();
		while (!q[1].empty() && q[1].front()<tmp)
		{
			gg.push_back(q[1].front());
			q[1].pop();
		}
		//MRK();
		if (q[1].empty())
		{
			cout<<-1;
			return 0;
		}
		int pos=q[1].front();
		gg.push_back(tmp);
		q[1].pop();
		v.push_back({col[pos],tmp});
	}
	while (!q[1].empty())
	{
		gg.push_back(q[1].front());
		q[1].pop();
	}
	if (tt.size())
	{
		if (gg.size()==0 || tt.back()>gg.back())
		{
			cout<<-1;
			return 0;
		}
		tt.push_back(gg.back());
		for (int i=0;i<tt.size()-1;i++)
		{
			v.push_back({pu-i,tt[i]});
			v.push_back({pu-i,tt[i+1]});
		}
	}
	cout<<v.size()<<endl;
	for (auto p:v)
		printf("%d %d\n",n+1-p.first,p.second); 
	return ~~(0^_^0);
}