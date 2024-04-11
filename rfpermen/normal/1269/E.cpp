#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> pbds;
pbds op;

ll n,x,z[MAX],bit[MAX],ans,pos,mid;
 
inline void upd(int i){
	for(; i<=n; i+=(i&-i))++bit[i];
	return;
}
int ret;
inline int que(int i){
	ret = 0;
	for(;i>0;i-=(i&-i))ret+=bit[i];
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x, z[x] = i;
    auto it = op.begin();
	rep(i,1,n){
		ans+=que(n-z[i]+1), upd(n-z[i]+1);
		pos = op.order_of_key(z[i]), mid = i>>1;
		ans-= min(pos,i-pos-1);
		if(i!=1 && (i&1)){
			if(pos<mid)ans+= *op.find_by_order(mid-1) - z[i] - (mid-pos);
			else if(pos>mid)ans+= z[i] - *op.find_by_order(mid) - (pos-mid);
		}
		else if(i!=1){
			if(pos<mid)ans+= *op.find_by_order(mid-1) - z[i] - (mid-pos);
			else ans+= z[i] - *op.find_by_order(mid-1) - (pos-mid+1);
		}
		op.insert(z[i]);
		cout<<ans<<' ';
	}
	cout<<endl;
    return 0;
}