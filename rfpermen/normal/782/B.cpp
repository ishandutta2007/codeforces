#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
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
#define endl "\n"
const int MAX = 1e5+5;
const ll MAX2 = 11;
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int n;
double x[MAX],v[MAX],le,ri,m1,m2,a1,a2,ans;
inline double dabs(double z){
	if(z<0.0)return -z;
	return z;
}

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n)cin>>v[i];
    le = 1, ri = 1e10, ans = 1e18;
    rep(k,1,1000){
    	m1 = le+(ri-le)/3.0;
    	m2 = le+(ri-le)*2.0/3.0;
    	a1 = a2 = 0.0;
    	rep(i,1,n){
    		a1 = max(a1,dabs(m1-x[i])/v[i]);
    		a2 = max(a2,dabs(m2-x[i])/v[i]);
		}
		if(a1>a2)le = m1;
		else ri = m2;
		ans = min(ans,min(a1,a2));
	}
	cout<<ans<<endl;
	return 0;
}