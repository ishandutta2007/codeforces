#pragma GCC omptimize("unroll-loops")
#pragma optimize("SEX_ON_THE_BEACH")
#pragma GCC optimize("no-stack-protector")
#pragma comment(linker, "/STACK:1000000000")
#include<bits/stdc++.h>
 
using namespace std;
 
//#define need_tree
 
#ifdef need_tree
    #include<ext/pb_ds/assoc_container.hpp>
    using namespace __gnu_pbds;
    template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#endif // need_tree
 
using ll = int64_t;
using ull = uint64_t;
using dd = double;
using ldd = long double;
using si = int16_t;
using pii = pair<int32_t, int32_t>;
using pll = pair<int64_t, int64_t>;
 
ll get_seed(string s)
{
    ll ans = 0;
    for (int i = 0; i < s.size(); ++i)
        ans += s[i];
    return ans;
}
 
int popcount(int x)
{
    return __builtin_popcount(x);
}
 
ll popcountll(ll x)
{
    return __builtin_popcount(x);
}
 
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
 
// debug defines
#ifdef HOME
    int jjj;
    #define PO cout << "Pomelo" << endl;
    #define OL cout << "Oliva" << endl;
 
    #define debug(x) cout << #x << " " << x << endl;
    #define debug_p(x) cout << #x << " " << x.ff << " " << x.ss << endl;
    #define debug_v(x) cout << #x << " "; for (auto iii : x) cout << iii << " "; cout << endl;
    #define debug_vp(x) cout << #x << " "; for (auto ii : x) cout << '[' << ii.ff << " " << ii.ss << ']'; cout << endl;
    #define say(x) cout << x << endl;
 
    #define wait() cin >> jjj;
#else
    #define PO 0;
    #define OL 0;
 
    #define debug(x) 0;
    #define debug_p(x) 0;
    #define debug_vp(x) 0;
    #define debug_v(x) 0;
    #define debug_vp(x) 0;
    #define say(x) 0;
 
    #define wait() 0;
#endif // HOME
// end of debug definess
 
int _size = 22;
 
void solve(int test_number)
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    vector<int> dp(1 << _size, -1);
    for (int i : arr)
        dp[i] = i;
    for (int i = 0; i < _size; ++i)
        for (int j = 0; j < (1 << _size); ++j)
            if ((j >> i) & 1)
                dp[j] = max(dp[j], dp[j ^ (1 << i)]);
    for (int i = 0; i < arr.size(); ++i) {
        cout << dp[(1 << _size) - 1 - arr[i]] << " ";
    }
}
 
signed main()
{
 
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t;
    t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i)
        solve(i);
 
    return 0;
}
 
//debug_test
/*
 
*/