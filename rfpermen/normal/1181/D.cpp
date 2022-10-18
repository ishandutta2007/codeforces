#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

ll n,m,q,x[MAX],y[MAX],z,k,le,ri,mid,res;
vector<int> v[MAX];

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>m>>n>>q;
    rep(i,1,m)y[i] = n;
    rep(i,1,m){
    	cin>>z;
    	++x[z];
    	v[x[z]].pb(z);
    	--y[x[z]];
	}
	rep(i,1,m)y[i]+=y[i-1], sort(all(v[i]));
	while(q--){
		cin>>k;
		k-=m;
		if(k>n*m-m){
			res = (k-(n-1)*m)%n;
			if(res==0)res = n;
			cout<<res<<endl;
		}
		else {
			le = 0, ri = m;
			while(le<=ri){
				mid = le+ri>>1;
				if(k>y[mid])res = mid, le = mid+1;
				else ri = mid-1;
			}
			k-=y[res];
			++res, z = 0;
			if(!v[res].empty()){
				le = 0, ri = v[res].size()-1;
				while(le<=ri){
					mid = le+ri>>1;
					if(v[res][mid]<=k+mid)z = le = mid+1;
					else ri = mid-1;
				}
			}
			cout<<k+z<<endl;
		}
	}
	return 0;
}