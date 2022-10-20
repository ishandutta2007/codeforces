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

//
// nminfactor
vector<int> min_factor;
vector<int> sieve(int n) {
    vector<int> res(n+1);
    iota(res.begin(), res.end(), 0);
    for (int i = 2; i*i <= n; ++i) {
        if (res[i] < i) continue;
        for (int j = i*i; j <= n; j += i) {
            if (res[j] == j) res[j] = i;
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll T; cin >> T;
    min_factor = sieve(40000); //n
    vector<ll> pr;
    rep(i,40000){
        if(min_factor[i]==i&&i>=2){
            pr.push_back(i);
        }
    }
    rep(ii,T){
        ll a,b,k; cin >> a >> b >> k;
        string ans = "YES";
        ll c = 0; ll aa = a,bb = b;
        for(ll x:pr){
            while(aa%x==0){
                aa /= x; c++;
            }
            while(bb%x==0){
                bb /= x; c++;
            }
        }
        if(aa>1) c++;
        if(bb>1) c++;
        if(k>c) ans = "NO";
        if(a%b!=0&&b%a!=0){
            if(k<2) ans = "NO";
        }
        else if(a==b){
            if(k==1) ans = "NO";
        }
        else{
            if(k==0) ans = "NO";
        }
        cout << ans << "\n";
    }
    
    //cout << ans << endl;
}