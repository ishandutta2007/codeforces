#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
//#define endl "\n"
const int MAX = 1e6+5;
const ll MAX2 = 11;
const int MOD = 1000000000 + 7;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

ll n,m,b,cnt,mx,x,y,z;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>b; z=b, m=n;
    if(n==1)return cout<<0,0;
    x = sqrt(b);
    mx = 1e18;
    rep(i,2,x){
    	if(z%i)continue;
    	cnt = y = 0;
    	while(z%i==0)cnt++, z/=i;
    	n = m;
    	while(n){
    		y+=n/i;
    		n/=i;
		}
		mx = min(mx,y/cnt);
	}
	if(z!=1){
		ll i = z;
		cnt = y = 0;
    	while(z%i==0)cnt++, z/=i;
    	n = m;
    	while(n){
    		y+=n/i;
    		n/=i;
		}
		mx = min(mx,y/cnt);
	}
	cout<<mx<<endl;
	return 0;
}