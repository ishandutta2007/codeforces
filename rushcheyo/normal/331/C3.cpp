#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;
ll n;
map<pli,pli>f;

pli solve(ll n,int ma)
{
	if(n==0)return make_pair(0ll,0);
	if(n<10)return make_pair(1ll,max(int(ma-n),0));
	pli x=make_pair(n,ma);
	if(f.count(x))return f[x];
	ll pw=1,ans=0;
	while(n/10>=pw)pw*=10;
	for(;;)
	{
		int d=n/pw,m=max(ma,d);
		pli re=solve(n%pw,m);
		n-=n%pw,ans+=re.fi;
		if(re.se)n-=re.se;
		else if(m)n-=m,ans++;
		if(!d)break;
	}
	return f[x]=make_pair(ans,-n);
}

int main()
{
	cin>>n;
	cout<<solve(n,0).first<<endl;
}