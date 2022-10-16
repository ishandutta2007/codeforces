#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int n,m,ini[MAX],x[MAX],k,a,b,z;
pii e[MAX];
bool res[MAX];
 
bool cmp(pii a,pii b){
	return ini[a.fi]+ini[a.se]<ini[b.fi]+ini[b.se];
}
 
int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    cin>>n>>m;
    k = (n+m+1)/2;
    rep(i,1,m){
    	cin>>a>>b;
    	ini[a]++, ini[b]++;
    	x[a]++, x[b]++;
    	e[i] = {a,b};
	}
	if(k>=m){
		cout<<m<<endl;
		rep(i,1,m)cout<<e[i].fi<<' '<<e[i].se<<endl;
	}
	else {
		z = k;
		do {
			random_shuffle(e+1,e+1+m);
			k = m-z;
			rep(i,1,m){
				if(!k)break;
				if((x[e[i].fi]-1)*2>=ini[e[i].fi]&&(x[e[i].se]-1)*2>=ini[e[i].se]){
					--k;
					--x[e[i].fi], --x[e[i].se];
					res[i] = 1;
				}
			}
			if(k){
				rep(i,1,n)x[i] = ini[i];
				rep(i,1,m)res[i] = 0;
				continue;
			}
			cout<<z<<endl;
			rep(i,1,m){
				if(!res[i])cout<<e[i].fi<<' '<<e[i].se<<endl;
			}
		}while(k);
	}
	return 0;
}