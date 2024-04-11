// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}



const int maxn=200005;
int p[maxn];
int sz[maxn];
vector<int> vec[maxn];

int comp = 0;

void clear(int n=maxn){
    rep(i,0,maxn)p[i]=i,sz[i]=1,vec[i].push_back(i);
}
int root(int x){
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
void merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2)return;
    comp--;
    if(sz[p1]>=sz[p2]){
        p[p2]=p1;
        sz[p1]+=sz[p2];
        for(auto i:vec[p2])vec[p1].push_back(i);
        vec[p2].clear();
    }
    else{
        p[p1]=p2;
        sz[p2]+=sz[p1];
        for(auto i:vec[p1])vec[p2].push_back(i);
        vec[p1].clear();
    }
}

int solve(){
 		int n,q,s,d; cin >> n >> q >> s >> d;
 		
                vector<int>a(n + 1);
                rep(i,1,n + 1){
                        cin >> a[i];
                }

                clear();
                comp = n;
                set<int> st;
                map<int,int> mp;
                for(int i = 1; i <= n; i++){
                        st.insert(a[i]);
                        mp[a[i]] = i;
                }
                vector<vector<pii>> g(n + 1);

                auto add_edge = [&](int u,int v,int w){
                        g[u].push_back({v,w});
                        g[v].push_back({u,w});
                };

                auto find_best = [&](int x) -> pair<int,int> {
                        auto itr = st.lower_bound(x);
                        pair<int,int> best = {1e9,-1};
                        if(itr != st.end()){
                                mins(best,make_pair(*itr - x,mp[*itr]));
                        }
                        if(itr != st.begin()){
                                itr--;
                                mins(best,make_pair(x - *itr,mp[*itr]));
                        }
                        return best;
                };

                while(comp > 1){
                        vector<int> vis(n + 1);
                        for(int i = 1; i <= n and comp > 1; i++){
                                if(root(i) == i and !vis[i]){
                                        // erase
                                        for(auto j:vec[i]){
                                                st.erase(a[j]);
                                        }
                                        // find best
                                        pair<int,pii> best = {1e9,{-1,-1}};

                                        for(auto j:vec[i]){
                                                auto s = find_best(a[j] - d);
                                                pair<int,pii> p = {s.x,{s.y,j}};
                                                mins(best,p);
                                                s = find_best(a[j] + d);
                                                p = {s.x,{s.y,j}};
                                                mins(best,p);
                                        }

                                        for(auto j:vec[i]){
                                                st.insert(a[j]);
                                        }
                                        add_edge(best.y.x,best.y.y,best.x);
                                        merge(i,best.y.x);
                                        vis[root(i)] = 1;
                                }
                        }
                }

                vector<int> dp(n + 1,LLONG_MAX);

                dp[s] = 0;

                function<void(int,int)> dfs = [&](int u,int p){
                        for(auto [i,w]:g[u]){
                                if(i != p){
                                        dp[i] = max(w,dp[u]);
                                        dfs(i,u);
                                }
                        }
                };
                dfs(s,s);
                rep(i,0,q){
                        int j,k; cin >> j >> k;
                        cout << ((dp[j] <= k)?"Yes":"No") << endl;
                }

 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}