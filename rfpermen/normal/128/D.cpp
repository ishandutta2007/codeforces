#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
 
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
#define out(x,y) cout << ">> " << x << " " << y << endl
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
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,x[MAX],cnt[MAX],nw,lp,hit;

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    sort(x+1,x+1+n);
    rep(i,2,n)if(x[i]-x[i-1]>1)return cout<<"NO\n",0;
    rep(i,1,n)cnt[x[i]-x[1]]++;
    if(!cnt[1])return cout<<"NO\n",0;
    
    --cnt[1], nw = hit = 1;
    while(1){
    	if(cnt[nw]==0)break;
    	if(cnt[nw-1]>1){
    		--cnt[nw-1];
    		--cnt[nw];
		}
		else {
			if(!cnt[nw+1])return cout<<"NO\n",0;
			++nw;
			--cnt[nw];
		}
	}
	
	bool st = 0;
	rep(i,0,n){
		if(cnt[i]){
			if(cnt[i]!=1 || st)return cout<<"NO\n",0;
		}
		else st = 1;
	}
	cout<<"YES\n";
    return 0;
}