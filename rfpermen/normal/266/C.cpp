#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
const int MAX = 2e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,a,b,id,y[MAX];
bool x[MAX][MAX],st,z[MAX];
vector<piii> ans;

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,n){
    	cin>>a>>b;
    	x[a][b] = 1;
	}
	id = 1;
	rap(j,n,1){
		st = 0;
		rep(i,1,n)st|=x[i][j];
		if(st){
			while(id<j){
				st = 0;
				rep(i,1,n)st|=x[i][id];
				if(!st)break;
				++id;
			}
			if(id<j){
				rep(i,1,n)x[i][id] = x[i][j];
				rep(i,1,n)x[i][j] = 0;
				ans.pb({2,{id,j}});
				++id;
			}
			else break;
		}
	}
	id = n;
	rep(i,1,n){
		st = 0;
		rep(j,1,n)st|=x[i][j];
		if(st){
			while(id>i){
				st = 0;
				rep(j,1,n)st|=x[id][j];
				if(!st)break;
				--id;
			}
			if(id>i){
				rep(j,1,n)x[id][j] = x[i][j];
				rep(j,1,n)x[i][j] = 0;
				ans.pb({1,{id,i}});
				--id;
			}
			else break;
		}
	}
	rep(i,1,n)rep(j,1,n)if(x[i][j])y[i] = j;
	rep(i,1,n){
		if(y[i]>=i){
			rep(j,i+1,n)if(y[j]<i){
				swap(y[i],y[j]), ans.pb({1,{i,j}});
				break;
			}
		}
	}
//	rep(i,1,n)cout<<y[i]<<endl;
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i.fi<<" "<<i.sf<<' '<<i.ss<<endl;
	return 0;
}