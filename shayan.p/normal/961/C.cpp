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
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll dif[5][3];
ll per[4];
int main(){
	ll n;cin>>n;
	REP(i,4){
		string s;
		REP(j,n){
			cin>>s;
			REP(k,n){
				bool num=(((j+k)%2)==(s[k]-'0'));
				dif[i][0]+=(num);
				dif[i][1]+=(!num);
			}
		}
	}
	REP(i,4)
		per[i]=i;
	ll ans=inf;
	do{
		ll num=0;
		REP(i,4)
			num+=dif[per[i]][i%2];
		ans=min(ans,num);
	}while(next_permutation(per,per+4));
	cout<<ans;
}