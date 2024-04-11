#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 320;

int n,q,a,b,ans,ty,k,x,cnt[320][MAX],na,nb,tmp;
deque<int> dq[320];

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    dq[0].pb(0);
    rep(i,1,n){
    	cin>>x;
    	++cnt[i/block][x];
    	dq[i/block].pb(x);
	}
	cin>>q;
	while(q--){
		cin>>ty>>a>>b;
		a = (a+ans-1)%n + 1, b = (b+ans-1)%n + 1;
		if(a>b)swap(a,b);
		na = a/block, nb = b/block;
		a%= block, b%= block;
		if(ty==1){
			tmp = dq[nb][b];
			dq[nb].erase(dq[nb].begin()+b);
			if(na==nb)dq[na].insert(dq[na].begin()+a,tmp);
			else {
				++cnt[na][tmp], --cnt[nb][tmp];
				dq[na].insert(dq[na].begin()+a,tmp);
				asd(i,na,nb){
					--cnt[i][dq[i].back()];
					++cnt[i+1][dq[i].back()];
					dq[i+1].pf(dq[i].back());
					dq[i].pob();
				}
			}
		}
		else {
			cin>>k;
			k = (k+ans-1)%n + 1;
//			cout<<">> "<<a<<' '<<b<<" "<<k<<endl;
			ans = 0;
			if(na==nb){
				rep(i,a,b)if(dq[na][i]==k)++ans;
			}
			else {
				asd(i,a,block)if(dq[na][i]==k)++ans;
				rep(i,0,b)if(dq[nb][i]==k)++ans;
				asd(i,na+1,nb)ans+= cnt[i][k];
			}
			cout<<ans<<endl;
		}
	}
    return 0;
}