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
};
  //main unionfind friends(N+1);
  //  friends.unite(a,b);
  //

int main() {
    ll TT; cin >> TT;
    rep(ii,TT){
        ll N,K; cin >> N >> K;
        vector<ll> ans;
        ll p[N];
        rep(i,N) cin >> p[i];
        ll ini[N+1];
        rep(i,N+1) ini[i] = 0;
        rep(i,N){
            ll s = (p[i]-i+N)%N;
            ini[s]++;
        }
        vector<ll> cand;
        rep(i,N+1){
            if(ini[i]>=(N-2*K)){
                if(i==0) cand.push_back(N);
                else cand.push_back(i);
            }
        }
        for(ll x:cand){
            unionfind place(N+1);
            rep(i,N){
                place.unite((x+i)%N,p[i]%N);
            }
            ll cnt = 0;
            rep(i,N){
                if(place.root(i)==i){
                    cnt++;
                }
            }
            if((N-cnt)<=K){
                ans.push_back((N-(x-1))%N);
            }
        }
        sort(ans.begin(),ans.end());
        cout << ans.size() << " ";
        for(ll y:ans){
            cout << y << " ";
        }
        cout << endl;
    }    
    //cout << ans << endl;
}