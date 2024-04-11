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
const int MAX=3e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,m,x,y;
deque<int> a,b;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>m; while(m--)cin>>x, a.pb(x);
    cin>>m; while(m--)cin>>x, b.pb(x);
    rep(k,0,105){
    	if(a.empty())return cout<<k<<" 2",0;
    	if(b.empty())return cout<<k<<" 1",0;
    	x = a.front(), a.pof();
    	y = b.front(), b.pof();
    	if(x>y)a.pb(y), a.pb(x);
    	else b.pb(x), b.pb(y);
	}
	cout<<-1;
    return 0;
}