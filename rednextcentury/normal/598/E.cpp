#include <bits/stdc++.h>
#define read            freopen("jumping.in","r",stdin)
#define write           freopen("output.txt","w",stdout)
#define fr              first
#define sc              second
#define ll              long long
#define ld              long double
#define mp              make_pair
#define pb              push_back
#define OO              0x3f3f3f3f
#define pii             pair<ll,ll>
#define pdd             pair<double,double>
#define All(v)          v.begin(),v.end()
#define revAll(v)       v.rbegin(),v.rend()
#define reAssign(v, d)  memset(v, d, sizeof(v))
#define MAX_Heap(x)     priority_queue<x>
#define MIN_Heap(x)     priority_queue<x, vector<x>, greater<x> >
#define VIT(type)       vector<type>::iterator
#define SIT(type)       set<type>::iterator
#define MSIT(type)      multiset<type>::iterator
#define MIT(type1, type2)       map<type1,type2>::iterator

const ll        MOD     	  = 1e9 + 7;
const ll        EPS     	  = 1e-9;
const ld        PI            = acos(-1.0);
const int       MAXX          = 1e6 + 3;
const int       LOGMAXN       = 30;

using namespace std;

int n, m, k;
ll dp[32][32][51];

ll solve(int i, int j, int c){
    if(c == 0 || c == i * j) 
        return 0;
        
    ll &ret = dp[i][j][c];
    if(ret != -1)
        return ret;
        
    ll c1 = 1e12, c2 = 1e12;
    
    for(int l = 0; l <= c; l++){
        for(int x = 1; x < i; x++)
            c1 = min(c1, j * j + solve(x, j, c - l) + solve(i - x, j, l) );
        for(int x = 1; x < j; x++)
            c2 = min(c2, i * i + solve(i, x, c - l) + solve(i, j - x, l) );
    }
    
    return ret = min(c1, c2);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
        reAssign(dp, -1);
    while(t--) {
        cin >> n >> m >> k;
        ll res = solve(n, m, k);
        cout << res << endl;
    }
    //int x;
    //cin >> x;
    return 0;
}