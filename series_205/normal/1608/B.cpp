#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << p.first << ' ' << p.second;
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &x : v) is >> x;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for(size_t i = 0; i < v.size(); i++) os << (i ? " " : "") << v[i];
    return os;
}
struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;
/*-------------------------------------------*/

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    deque<int> deq(n);
    iota(ALL(deq), 1);
    if(abs(a - b) > 1 || a + b > n - 2) {
        cout << -1 << "\n";
    } else {
        vector<int> ans;
        bool nxt;
        if(a >= b) {
            ans.push_back(deq.front());
            deq.pop_front();
            nxt = true;
        } else {
            ans.push_back(deq.back());
            deq.pop_back();
            nxt = false;
        }
        while(a + b > 0) {
            if(!nxt) {
                ans.push_back(deq.front());
                deq.pop_front();
                b--;
            } else {
                ans.push_back(deq.back());
                deq.pop_back();
                a--;
            }
            nxt = !nxt;
        }
        while(!deq.empty()) {
            if(deq.front() > ans.back()) {
                ans.push_back(deq.front());
                deq.pop_front();
            } else {
                ans.push_back(deq.back());
                deq.pop_back();
            }
        }

        cout << ans << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}