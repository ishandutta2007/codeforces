//https://codeforces.com/contest/1003/problem/D
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
#define FOR(a, b, c)        for (ll(a) = (b); (a) < (c); ++(a)) 
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

int a[32]={0};
map <ll,ll> m;
int main(){
    ll n,q,b,c=0;
    cin>>n>>q;
    FOR(i,0,n){
        c=-1;
        cin>>b;
        while(b){
            c++;
            b/=2;
        }
        a[c] += 1;
        m[c]++;
    }
    FOR(i,0,q){
        int diff[32]={0};
        ll ans=0;
        ll ch=-1;
        cin>>b;
        while(b){
            ch++;
            if(b%2){
                int t=1,check=ch;
                while( (a[check]-diff[check])<t ){
                    ans += a[check]-diff[check];
                    t -= a[check]-diff[check];
                    diff[check] += a[check]-diff[check];
                    check--;
                    if(check<0){
                        cout<<-1<<"\n";goto out;
                    }
                    t*=2;
                }
                diff[check] += t;
                ans+=t;
            }
            b/=2;
        }
        cout<<ans<<"\n";
        out:;
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