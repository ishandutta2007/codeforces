#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define endl "\n"
const int MAX = 1e5+5;
const ll MAX2 = 11;
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

ll n,r,h,y[MAX],bit[MAX],ans,ret,res;
pll x[MAX];
inline void upd(int i,ll z){
	for(; i<=n ;i+=(i&-i))bit[i] = max(bit[i],z);
}
inline ll que(int i){
	ret = 0;
	for(; i; i-=(i&-i))ret = max(bit[i],ret);
	return ret;
}

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>r>>h, x[i] = {r*r*h,-i};
    sort(x+1,x+1+n);
    rep(i,1,n)y[-x[i].se] = i;
    rep(i,1,n)upd(y[i],que(y[i])+x[y[i]].fi);
    cout<<que(n)*pi<<endl;
	return 0;
}