#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 

#define sz(x) (int)(x).size()


typedef string str;
typedef long long ll;


#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

vector< pair<ll, ll> > br(vector<ll> x, int m) {
    vector< pair<ll, ll> > ret;
    
    for (int i = 0; i < sz(x); i++) {
        ll cnt = 1;
        while (x[i] % m == 0) {
            x[i] /= m;
            cnt *= m;
        }
        if (!ret.empty() && ret.back().first == x[i]) ret.back().second += cnt;
        else ret.emplace_back(x[i], cnt);
    }
    return ret;
}

void go() {
    int sa, m;
    cin >> sa >> m;
    
    vector<ll> a(sa);
    for (int i = 0; i < sa; i++) cin >> a[i];
    
    int sb;
    cin >> sb;
    vector<ll> b(sb);
    for (int i = 0; i < sb; i++) cin >> b[i];
    
    vector< pair<ll, ll> > aa = br(a,m);
    vector< pair<ll, ll> > bb = br(b,m);
    dbg(aa,bb);
    ps ( aa==bb ? "Yes" : "No" );
}

void solve()
{
    int t;
    for (cin >> t; t; t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}