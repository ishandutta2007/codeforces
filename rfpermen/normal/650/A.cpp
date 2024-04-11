#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pdd pair<double,double> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

ll n,x,y,ans;
map<int,ll> a,b;
map<pii,ll> c;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);sgdfgsergtser
//	freopen("output
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    while(n--){
    	cin>>x>>y;
    	a[x]++;
    	b[y]++;
    	c[{x,y}]++;
	}
	for(auto i:c)ans-=i.se*(i.se-1)/2;
	for(auto i:a)ans+=i.se*(i.se-1)/2;
	for(auto i:b)ans+=i.se*(i.se-1)/2;
	cout<<ans<<endl;
    return 0;
}