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

LL n,k;
LL a[MAXN];
LL cnt[MAXN]; 
LL sum=0;

typedef pair<LL,LL> pll;

bool check(LL mid)
{
	LL x=mid;
	sum=0;
	//WRT(x);
	for (LL i=0;i<n;i++)
	{
		sum+=(a[i]-1)/x+1;
		cnt[i]=(a[i]-1)/x+1;
	}
	return sum<=k;
}

LL getans(LL a,LL c)
{
	return a%c*(LL)(a/c+1)*(a/c+1)
			+(c-a%c)*(LL)(a/c)*(a/c);
}
struct cmp
{
bool operator()(pll p1,pll p2)
{
	return getans(p1.first,p1.second)-getans(p1.first,p1.second+1)<
		getans(p2.first,p2.second)-getans(p2.first,p2.second+1);
}
};
priority_queue<pll,vector<pll>,cmp> v;

int main()
{
	LL l=1,r=INF;
	cin>>n>>k;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		cnt[i]=1;
	}
	for (int i=0;i<n;i++)
		v.push({a[i],cnt[i]});
	//sort(v.begin(),v.end(),cmp);
	//WRT(k-sum);
	for (int i=0;i<k-n;i++)
	{
		auto tmp=v.top();
		v.pop();
		tmp.second++;
		v.push(tmp);
	}
	//	v[i].second++;
	LL ans=0;
	for (int i=0;i<n;i++)
	{
		auto tmp=v.top();
		v.pop();
		ans+=getans(tmp.first,tmp.second);
	}
	cout<<ans;
	return ~~(0^_^0);
}