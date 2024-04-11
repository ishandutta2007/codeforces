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

using namespace std;

#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


typedef long long ll;


ll pos_tree[610000];
ll neg_tree[610000];
ll zero_tree[610000];

const ll INF = 1000000000000000000LL;

void solve()
{
    int t;
    for (cin >> t; t; t--) {
        int n; cin >> n;
        vector<ll> a(n);
        REP(i,n) cin >> a[i];
        
        vector<ll> pref_sums(n+1);
        partial_sum(all(a), pref_sums.begin()+1);
        
        for (int i = 0; i <= n+10; i++) pos_tree[i]=neg_tree[i]=zero_tree[i]=-INF;
        
        vector<ll> sorted_sums = pref_sums;
        sort(all(sorted_sums));
        sorted_sums.erase(unique(all(sorted_sums)), sorted_sums.end());
        
        int idx_z = lower_bound(all(sorted_sums), 0) - sorted_sums.begin();
        zero_tree[idx_z] = 0;
        
        int tree_n = sz(sorted_sums);
        
        for (int i = 0; i < n; i++) {
            int idx = lower_bound(all(sorted_sums), pref_sums[i]) - sorted_sums.begin();
            
            ll zero_val = zero_tree[idx];
            ll pos_val = -INF;
            ll neg_val = -INF;
            
            for (int x = idx+1; x <= tree_n; x += x&-x) neg_val = max(neg_val, neg_tree[x]);
            for (int x = idx+1; x > 0; x -= x&-x) pos_val = max(pos_val, pos_tree[x]);

            dbg(i, zero_val, pos_val, neg_val);
            ll val = max(zero_val, max(pos_val + i, neg_val - i));
            
            zero_tree[idx] = val;
            for (int x = idx+2; x <= tree_n; x += x&-x) pos_tree[x] = max(pos_tree[x], val - i);
            for (int x = idx; x > 0; x -= x&-x) neg_tree[x] = max(neg_tree[x], val + i);
        }
        
        int idx = (lower_bound(all(sorted_sums), pref_sums[n]) - sorted_sums.begin());
        ll zero_val = zero_tree[idx];
        ll pos_val = -INF;
        ll neg_val = -INF;
            
        for (int x = idx+1; x <= tree_n; x += x&-x) neg_val = max(neg_val, neg_tree[x]);
        for (int x = idx+1; x > 0; x -= x&-x) pos_val = max(pos_val, pos_tree[x]);
        ll val = max(zero_val, max(pos_val + n, neg_val - n));
        cout << val << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}