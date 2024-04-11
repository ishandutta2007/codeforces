#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e3+5;
const ll MAX2 = 11;
const ll MOD = 131071;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int tc,n,k,nw,par[MAX],num[MAX],chl[MAX],fn,dec;
queue<int> z[MAX];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>n>>k;
    	nw = n*(n-1)>>1;
    	if(nw<k){cout<<"NO\n"; continue;}
    	rep(i,1,n){
    		while(!z[i-1].empty())z[i-1].pop();
    		z[i-1].push(i);
    		par[i] = num[i] = i-1, chl[i-1] = 1;
		}
		chl[n] = 0;
    	rap(i,n,2){
    		if(chl[i]||chl[par[i]]==2||nw==k)break;
    		chl[par[i]] = 0;
    		
    		++nw;
    		rap(j,i-2,0){
    			if(z[j].empty())break;
    			--nw;
    			fn = z[j].front();
    			if(nw==k)break;
			}
			par[i] = fn;
			chl[fn]++;
			if(chl[fn]==2)z[num[fn]].pop();
			num[i] = num[fn]+1;
			z[num[i]].push(i);
		}
		if(nw!=k)cout<<"NO\n";
		else {
			cout<<"YES\n";
			rep(i,2,n)cout<<par[i]<<' '; cout<<endl;
		}
	}
    return 0;
}