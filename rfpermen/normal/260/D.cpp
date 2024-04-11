#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,x,y,nw,rem,tmp,z;
bool mv;
stack<pii> s[2];

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x>>y;
    	s[x].push({i,y});
	}
	nw = s[0].top().fi, rem = s[0].top().se, s[0].pop();
	while(1){
		if(s[mv^1].empty())break;
		while(!s[mv^1].empty()){
			x = s[mv^1].top().fi, y = s[mv^1].top().se, s[mv^1].pop();
			z = min(rem,y);
			cout<<nw<<' '<<x<<' '<<z<<endl;
			rem-= z, y-= z;
			if(!rem){
				tmp = nw;
				nw = x, rem = y;
				break;
			}
		}
		mv^=1;
	}
	while(!s[mv].empty())cout<<tmp<<' '<<s[mv].top().fi<<" 0\n", s[mv].pop();
    return 0;
}