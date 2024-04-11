#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 998244353;


//Unionfind
struct unionfind {
	//-1
	//id
	  vector<long long> r;
	  unionfind(long long N) {
		    r = vector<long long>(N, -1);
	  }
	  long long root(long long x) {
		    if (r[x] < 0) return x;
		    return r[x] = root(r[x]);
	  }
	  bool unite(long long x, long long y) {
		    x = root(x);
		    y = root(y);
		    if (x == y) return false;
		    if (r[x] > r[y]) swap(x, y);
		    r[x] += r[y];
		    r[y] = x;
		    return true;
	  }
	  long long size(long long x) {
		    return max(-r[root(x)],0LL);
	  }
  
  // 2x, ytrue
    bool same(long long x, long long y) { 
        long long rx = root(x);
        long long ry = root(y);
        return rx == ry;
    }
    void eval(ll i,ll x){
        r[i] = (-1)*x;
    }
};
  //main unionfind friends(N+1);
  //  friends.unite(a,b);
  //

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll T; cin >> T;
    rep(ii,T){
        ll N; cin >> N;
        ll a[N]; ll sum = 0;
        rep(i,N){
            cin >> a[i];
            sum += a[i];
        }
        if(sum%N!=0){
            cout << -1 << "\n";
        }
        else{
            ll mm = sum/N;
            ll ans = 0;
            rep(i,N){
                if(a[i]>mm) ans++;
            }
            cout << ans << "\n";
        }

    }
    
    //cout << ans << endl;
}