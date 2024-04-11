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
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<pii,int>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll tc,n,x,a,b,mx;
priority_queue<int> e,o;
bool mv;

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	rep(i,1,n){
    		cin>>x;
    		if(x&1)o.push(x);
    		else e.push(x);
		}
		mv = a = b = 0;
		while(!o.empty() || !e.empty()){
			mx = 0;
			if(!o.empty())mx = max(mx,(ll)o.top());
			if(!e.empty())mx = max(mx,(ll)e.top());
//			cout<<"mx = "<<mx<<endl;
			if(mx&1){
				o.pop();
				if(mv&1)b+= mx;
			}
			else {
				e.pop();
				if(!(mv&1))a+= mx;
			}
			mv^=1 ;
		}
//		cout<<">. "<<a<<' '<<b<<endl;
		if(a>b)cout<<"Alice\n";
		else if(b>a)cout<<"Bob\n";
		else cout<<"Tie\n";
	}
    return 0;
}