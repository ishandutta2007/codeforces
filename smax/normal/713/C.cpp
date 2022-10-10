#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    priority_queue<int> pq; // set containing all slope-changing points
    long long ret = 0;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        a -= i; // change strictly increasing condition to >=
        if (i == 0) {
            // f_i(x) = |x - a_i|
            pq.push(a); // we only add once because f_i(x) is a minimum of some prefix of i, so any positive slope is useless
        } else {
            // g_i(x) = f_{i-1}(x) + |x - a_i|
            // f_i(x) = min g_i(y) for all y <= x
            assert(!pq.empty());
            if (pq.top() <= a) {
                // function looks roughly the same, just that it now hits slope 0 at a_i since we add |x - a_i| function
                // no update to answer because a_i >= opt_{i-1}, so non-decreasing condition is maintained
                pq.push(a);
            } else {
                // function now hits slope 0 earlier than before
                // opt_{i-1} is still a point that minimizes f_i(x), so we can use it for answer
                ret += pq.top() - a;
                pq.pop();   // however, opt_{i-1} is no longer a slope changing point, so we must remove it for the future
                pq.push(a); // we add a_i twice because it causes a +2 change in slope
                pq.push(a);
            }
        }
    }
    cout << ret << "\n";

    return 0;
}