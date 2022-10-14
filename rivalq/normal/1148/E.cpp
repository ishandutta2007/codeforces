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


pair<ll,int> s[300005];
ll t[300005];
ll ch[300005];
vector<pair<pair<ll,ll>,ll>> ans;
set<pair<pll,int>> temp;

int main(){
    tezi
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); 
    int n;
    cin>>n;
    FOR(i,0,n){
        cin>>s[i].fi;
        s[i].se=i+1;
    }
    FOR(i,0,n)cin>>t[i];
    sort(s,s+n);
    sort(t,t+n);
    ll sum=0;
    FOR(i,0,n){
        ch[i]=t[i]-s[i].fi;
    }
    bool ok=1;
    FOR(i,0,n){
        sum += ch[i];
        if(sum<0){
            ok=0;
            break;
        }
    }
    if(sum)ok=0;
    if(ok){
        cout<<"YES\n";
        FOR(i,0,n){
            int cnt=0;
            while(t[i]-s[i].fi<0){
                cnt++;
                if(2*temp.begin()->first.first<=(s[i].fi-s[temp.begin()->second].fi)){
                    ans.pb(mp(mp(temp.begin()->first.second,s[i].se),temp.begin()->first.first));
                    s[temp.begin()->second].fi += temp.begin()->first.first;
                    s[i].fi -= temp.begin()->first.first;
                    temp.erase(temp.begin());
                }else{
                    ans.pb(mp(mp(temp.begin()->first.second,s[i].se),(s[i].fi-s[temp.begin()->second].fi)/2));
                    ll ch = (s[i].fi-s[temp.begin()->second].fi)/2;
                    s[temp.begin()->second].fi += ch;
                    s[i].fi -= ch;
                    int x = temp.begin()->second;
                    temp.erase(temp.begin());
                    temp.insert(mp(mp(t[x]-s[x].fi,s[x].se),x));
                }
            }
            if(t[i]-s[i].fi>0) temp.insert(mp(mp(t[i]-s[i].fi,s[i].se),i));
        }
        cout<<ans.size()<<"\n";
        for(auto u:ans){
            cout << u.fi.fi << " " << u.fi.se << " " << u.se << "\n";
        }
    }else{
        cout<<"NO";
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