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


int t,n,x[MAXN];
int mi[MAXN];
void work()
{
	map<int,int> mp1,mp2;
	cin>>n;
	mi[0]=INF;
	for (int i=1;i<=n;i++)
	{
		mi[i]=INF;
		scanf("%d",&x[i]);
		int d=i-mp1[x[i]];
		mp2[x[i]]=max(mp2[x[i]],d);
		mp1[x[i]]=i;
	}
	for (auto p:mp1)
	{
		mp2[p.first]=max(mp2[p.first],n+1-p.second);
		mi[mp2[p.first]]=min(mi[mp2[p.first]],p.first);
	}
	for (int i=1;i<=n;i++)
	{
		mi[i]=min(mi[i-1],mi[i]);
		if (mi[i]==INF)
			printf("%d ",-1);
		else
			printf("%d ",mi[i]);
	}
	putchar('\n');
		
}

int main()
{
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}