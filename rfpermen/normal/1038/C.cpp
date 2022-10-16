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
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>>" << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=1e6+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-9;

ll n,z,a[2];
priority_queue<ll> x[2];
bool mv;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>z, x[0].push(z);
    rep(i,1,n)cin>>z, x[1].push(z);
    n*=2;
    rep(i,1,n){
    	if(x[mv].empty())x[mv^1].pop();
    	else if(x[mv^1].empty())a[mv]+=x[mv].top(), x[mv].pop();
    	else {
    		if(x[mv].top()>x[mv^1].top())a[mv]+=x[mv].top(), x[mv].pop();
    		else x[mv^1].pop();
		}
		mv^=1;
	}
	cout<<a[0]-a[1];
    return 0;
}