#include <bits/stdc++.h>
using namespace std; 
  
typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<ll> vl; 
typedef vector<vl> vvl; 
  
double EPS = 1e-9;      
int INF = 1000000005; 
long long INFF = 1000000000000000005LL; 
double PI = acos(-1); 
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 }; 
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 }; 
  
#ifdef TESTING 
#define DEBUG fprintf(stderr, "====TESTING====\n") 
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl 
#define debug(...) fprintf(stderr, __VA_ARGS__) 
#else 
#define DEBUG 
#define VALUE(x) 
#define debug(...) 
#endif 

#define tezi                ios_base::sync_with_stdio(false);\
                            cin.tie(0);\
                            cout.tie(0);        
#define endl                "\n"  
#define FOR(a, b, c)        for (int(a) = (b); (a) < (c); ++(a)) 
#define FORN(a, b, c)       for (int(a) = (b); (a) <= (c); ++(a)) 
#define FORD(a, b, c)       for (int(a) = (b); (a) >= (c); --(a)) 
#define FORSQ(a, b, c)      for (int(a) = (b); (a) * (a) <= (c); ++(a)) 
#define FORC(a, b, c)       for (char(a) = (b); (a) <= (c); ++(a)) 
#define FOREACH(a, b)       for (auto&(a) : (b)) 
#define rep(i, n)           FOR(i, 0, n) 
#define repn(i, n)          FORN(i, 1, n) 
#define MAX(a, b)           a = max(a, b) 
#define MIN(a, b)           a = min(a, b) 
#define SQR(x)              ((ll)(x) * (x)) 
#define RESET(a, b)         memset(a, b, sizeof(a)) 
#define fi                  first 
#define se                  second 
#define mp                  make_pair 
#define pb                  push_back 
#define ALL(v)              v.begin(), v.end() 
#define ALLA(arr, sz)       arr, arr + sz 
#define SIZE(v)             (int)v.size() 
#define SORT(v)             sort(ALL(v)) 
#define REVERSE(v)          reverse(ALL(v)) 
#define SORTA(arr, sz)      sort(ALLA(arr, sz)) 
#define REVERSEA(arr, sz)   reverse(ALLA(arr, sz)) 
#define PERMUTE             next_permutation 
#define tc(t)               while (t--)

ll power(ll x,ll y){
    if(y==0) return 1;
    return x*power(x,y-1); 
}

int p[300005];
vector<pii> ans;
int main(){
    tezi
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); 
    int n;
    cin >> n;
    FOR(i,1,n+1)cin>>p[i];
    FOR(i,1,n+1){
        while(p[i]!=i){
            if( 2*abs(p[i]-i)>=n ){
                ans.pb({p[i],i});
                swap(p[i],p[p[i]]);
            }else{
                if(i<=(n/2)){
                    if(p[i]<=n/2){
                        ans.pb({i,n});
                        ans.pb({n,p[i]});
                        ans.pb({i,n});
                        swap(p[i],p[n]);
                        swap(p[n],p[p[n]]);
                        swap(p[i],p[n]);
                    }else{
                        ans.pb({i,n});
                        ans.pb({n,1});
                        ans.pb({1,p[i]});
                        ans.pb({n,1});
                        ans.pb({i,n});
                        swap(p[i],p[n]);
                        swap(p[n],p[1]);
                        swap(p[1],p[p[1]]);
                        swap(p[1],p[n]);
                        swap(p[i],p[n]);
                    }
                }else{
                    if(p[i]>(n/2)){
                        ans.pb({i,1});
                        ans.pb({1,p[i]});
                        ans.pb({i,1});
                        swap(p[i],p[1]);
                        swap(p[1],p[p[1]]);
                        swap(p[i],p[1]);
                    }else{
                        ans.pb({i,1});
                        ans.pb({n,1});
                        ans.pb({n,p[i]});
                        ans.pb({n,1});
                        ans.pb({i,1});
                        swap(p[i],p[1]);
                        swap(p[n],p[1]);
                        swap(p[n],p[p[n]]);
                        swap(p[1],p[n]);
                        swap(p[i],p[1]);
                    }
                }
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(auto u:ans){
        cout<<u.fi<<" "<<u.se<<"\n";
    }
    return 0;
}


/*
######                  ####### #     #   ###   #     #    #    ####### ####### ######
#     #  ######  #    # #     # ##   ##    #    ##    #   # #      #    #     # #     #
#     #  #       ##   # #     # # # # #    #    # #   #  #   #     #    #     # #     #
#     #  #####   # #  # #     # #  #  #    #    #  #  # #     #    #    #     # ######
#     #  #       #  # # #     # #     #    #    #   # # #######    #    #     # #   #
#     #  #       #   ## #     # #     #    #    #    ## #     #    #    #     # #    #
######   ######  #    # ####### #     #   ###   #     # #     #    #    ####### #     #
*/