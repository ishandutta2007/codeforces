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
        ll x,y,a,b; cin >> x >> y >> a >> b;
        ll m = min(a,b); ll red = max(a,b)-m;
        // binary search
        //"r"
        ll l,r,ans;
        l = 0; r = 2e9; //
        while(l<r){
            ll c = (l+r)/2;
            //c
            bool ok = true;
            ll x1 = x; ll y1 = y;
            x1 -= m*c; y1 -= m*c;
            if(x1<0||y1<0) ok = false;
            if(red>0&&x1/red+y1/red<c) ok = false;
            if(ok){//c"l"
                l = c+1;
            }
            else r = c;
        }
        ans = l-1;
        cout << ans << "\n";
    }
    
    //cout << ans << endl;
}