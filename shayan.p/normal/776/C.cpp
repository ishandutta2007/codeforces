// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1e5+10;
const ll BIG=1e15;

#pragma GCC Optimize("Ofast")

int a[maxn];
map<ll,int>mp;
ll scale;
int n,k;

ll check(ll t){
	mp.clear();
		scale=0;
		
	ll ans=0;
	REP(i,n){
		if(mp.count(t-scale-a[i]))
			ans+=mp[t-scale-a[i]];
		if(a[i]==t)
			ans++;
		scale+=a[i];
		mp[a[i]-scale]++;
	}
	return ans;
}

int main(){
	scanf("%d%d",&n,&k);
	
	REP(i,n){
		scanf("%d",&a[i]);
	}
		
	if(k==1){
		cout<<check(1);
		return 0;
	}
	if(k==-1){
		cout<<check(-1)+check(1);
		return 0;
	}
	
	ll t=1,ans=0;
	while(abs(t)<BIG){
		ans+=check(t);
		t*=ll(k);
	}
	cout<<ans;
}