#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
const int MAX = 1e7+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,x,p[MAX],z[MAX],ls;
ll res;
pii ans;
pll a,b;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    res = 1e18;
    rep(i,1,n){
    	cin>>x;
    	if(z[x]){
    		if(x<res)res = x, ans = {z[x],i};
		}
		else z[x] = i;
	}
	rep(i,1,10000000){
		a.fi = b.fi = -1;
		for(int j = i; j<=10000000; j+=i){
			if(!z[j])continue;
			if(a.fi==-1)a = {j,z[j]};
			else {
				b = {j,z[j]};
				break;
			}
		}
		if(b.fi!=-1){
			if(a.fi*b.fi/i<res)res = a.fi*b.fi/i, ans = {a.se,b.se};
		}
	}
	if(ans.fi>ans.se)swap(ans.fi,ans.se);
	cout<<ans.fi<<' '<<ans.se<<endl;
	return 0;
}