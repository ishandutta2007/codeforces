/* You can't connect the dots looking forward 
   you can only connect them looking backwards. */

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout.precision(10);cout << fixed;
#define dbset(x) for(int i=0 ; i<x.size(); i++) cerr << x[i] << " "; cerr << endl;
#define inf 1000000007
#define INF 1000000000000000000LL
#define PI 3.14159265358979323846
#define mod 1000000007
#define mod1 1000696969
#define flusz fflush(stdout);
#define VI vector<int>
#define VPI vector < pair<int,int> >
#define PII pair<int, int>
#define BIT bitset<N>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORR(x, y, z) for(int x = y; x >= (z); --x)
using namespace std;

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

const int N = (1<<19);
const int M = (1<<20)+7;
const int X = (1<<20);

int test;

int n,k;

int l,r = inf;

int t[N];

int czy[N];

bool check(int x){
    FOR(i,1,n){
        czy[i] = 0;
    }

    int r = 0;

    FOR(l,1,n){
        if (czy[l-1] == 1){
            while(r <= n && t[r] <= t[l] + x){
                if (r-l+1 >= k){
                    czy[r] = 1;
                }

                r++;
            }
        }
    }

    return czy[n] == 1;
}

void solve()
{
    cin >> n >> k;

    if (k == 1){
        cout << 0;
        return;
    }

    FOR(i,1,n){
        cin >> t[i];
    }

    czy[0] = 1;

    sort(t+1,t+1+n);

    while(l!=r){
        int mid = (l+r)/2;

        if (check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }

    cout << l;
    return;
}

int32_t main()
{
    boost

    test=1;

    while(test--)
    {
        solve();
    }

  return 0;
}