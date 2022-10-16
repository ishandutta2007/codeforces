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
#define ff fi.fi
#define fs fi.se
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
const int MAX=5e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,m,x[MAX],y[MAX],a,b,com,d;
bool st;
pair<pii,pii> z[MAX];

int main(){
//	cout<<fixed<<setprecision(1);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)x[i] = 1e9;
    rep(j,1,m){
    	cin>>com>>a>>b>>d;
    	if(com==1)rep(i,a,b)y[i]+=d;
    	else rep(i,a,b)x[i] = min(x[i],d-y[i]);
		z[j] = {{com,a},{b,d}};
	}
	rep(i,1,n)y[i] = 0;
	rep(j,1,m){
		com = z[j].ff, a = z[j].fs, b = z[j].sf, d = z[j].ss;
    	if(com==1)rep(i,a,b)y[i]+=d;
    	else {
    		st = 0;
    		rep(i,a,b)if(x[i]+y[i]==d)st=1;
    		if(!st)return cout<<"NO\n",0;
		}
	}
	cout<<"YES\n";
	rep(i,1,n)cout<<x[i]<<' ';
    return 0;
}