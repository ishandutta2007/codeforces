#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pl4 pair<pll,pll>
#define S second
#define F first
#define PB push_back
#define MP make_pair
using namespace std;
ll a[1000000],n,k;
const ll inf=1e18;
int main()
{
	cin>>n>>k;
	for(ll i=0;i<n;i++) a[i]=i+1;
	if(k%2==0) {cout<<-1;return 0;}
	deque<pll> q;q.PB(MP(0,n));//baste 0 va baz n
	ll num=1;
	while(q.size()&&num!=k)
	{
		pll p=q.front();q.pop_front();
		ll mid=(p.F+p.S)/2;
		if(p.F+1!=p.S) {q.PB(MP(p.F,mid));q.PB(MP(mid,p.S));num+=2;swap(a[mid],a[mid-1]);}
	}
	if(num!=k) {cout<<-1;return 0;}
	for(ll i=0;i<n;i++) cout<<a[i]<<" ";
}