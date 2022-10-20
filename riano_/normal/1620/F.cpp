#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=(n)-1;(i)>=0;(i)--)
#define rrep2(i,n,k) for(int (i)=(n)-1;(i)>=(n)-(k);(i)--)
#define vll(n,i) vector<long long>(n,i)
#define v2ll(n,m,i) vector<vector<long long>>(n,vll(m,i))
#define v3ll(n,m,k,i) vector<vector<vector<long long>>>(n,v2ll(m,k,i))
#define v4ll(n,m,k,l,i) vector<vector<vector<vector<long long>>>>(n,v3ll(m,k,l,i))
#define all(v) v.begin(),v.end()
#define chmin(k,m) k = min(k,m)
#define chmax(k,m) k = max(k,m)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

//vector output
template <typename T>
void out(vector<T> &v){
    for(T x:v) cout << x << " ";
    cout << "\n"; return;
}
//Graph
struct graph {
    long long N;
	vector<vector<tuple<long long,long long,int>>> G;
    vector<long long> par_v;
    vector<long long> par_e;
    int edge_count = 0;
    
	graph(long long n) {
        N = n;
		G = vector<vector<tuple<long long,long long,int>>>(N);
        par_v = vector<long long>(N,-1);
        par_e = vector<long long>(N,-1);
	}

    graph(long long n,long long m,bool weighted = false,bool directed = false) {
        N = n;
		G = vector<vector<tuple<long long,long long,int>>>(N);
        par_v = vector<long long>(N,-1);
        par_e = vector<long long>(N,-1);
        for(int i=0;i<m;i++){
            long long a,b,c; cin >> a >> b;
            if(weighted) cin >> c;
            else c = 1;
            unite(a,b,c,directed);
        }
	}

    void unite(long long a,long long b,long long cost = 1,bool directed = false){
        G[a].emplace_back(b,cost,edge_count);
        if(!directed) G[b].emplace_back(a,cost,edge_count);
        edge_count++;
    }
};
//map add
template <typename T>
void add(map<T,ll> &cnt,T a,ll n = 1){
    if(cnt.count(a)) cnt[a] += n;
    else cnt[a] = n;
}  

const ll mod = 998244353;

int main(){
	riano_; 
    ll T,N; cin >> T;
    rep(ii,T){
        cin >> N; vector<ll> ans;
        auto dp = v2ll(N,2,2e9);
        auto pv = v2ll(N,2,-1);
        rep(i,2) dp[0][i] = -2e9;
        ll a[N];
        rep(i,N) cin >> a[i];
        rep(i,N-1){
            rep(j,2){
                ll c = a[i+1];
                if(j==1) c *= -1;
                rep(k,2){
                    ll x = a[i];
                    if(k==1) x *= -1;
                    ll y = dp[i][k];
                    if(x>y) swap(x,y);
                    if(y<c){
                        if(dp[i+1][j]>x){
                            dp[i+1][j] = x; pv[i+1][j] = k;
                        }
                    }
                    else if(x<c){
                        if(dp[i+1][j]>y){
                            dp[i+1][j] = y; pv[i+1][j] = k;
                        }
                    }
                }
            }
        }
        if(dp[N-1][0]<2e9){
            ans.emplace_back(a[N-1]); ll nw = 0;
            rrep(i,N-1){
                nw = pv[i+1][nw];
                if(nw==0) ans.emplace_back(a[i]);
                else ans.emplace_back(a[i]*(-1));
            }
            reverse(all(ans));
            cout << "YES" << "\n";
            out(ans);
        }
        else if(dp[N-1][1]<2e9){
            ans.emplace_back(a[N-1]*(-1)); ll nw = 1;
            rrep(i,N-1){
                nw = pv[i+1][nw];
                if(nw==0) ans.emplace_back(a[i]);
                else ans.emplace_back(a[i]*(-1));
            }
            reverse(all(ans));
            cout << "YES" << "\n";
            out(ans);
        }
        else{
            cout << "NO" << "\n";
        }
        
    }
    //cout << ans << endl;
}