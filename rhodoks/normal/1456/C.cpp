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
LL c[MAXN];
priority_queue<LL,vector<LL>,less<LL> > pq;;
int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	sort(c+1,c+1+n,greater<int>());
	int ptr=1;
	LL b=0;
	LL ans=0;
	for (;ptr<=n;ptr++)
	{
		if (b<0 && k>=1)
			break;
		ans+=b;
		b+=c[ptr];
		//cout<<ptr<<' '<<b<<' '<<ans<<endl;
	} 
	if (ptr<=n)
	{
		pq.push(b);
		//sort(c+ptr,c+n+1);
		for (int i=0;i<k;i++)
			pq.push(0);
		for (int i=ptr;i<=n;i++)
		{
			LL pos=pq.top();
			pq.pop();
			ans+=pos;
			pos+=c[i];
			pq.push(pos);
		}
	}
	cout<<ans<<endl;
	return ~~(0^_^0);
}