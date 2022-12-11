#include <bits/stdc++.h>
// #include <atcoder/all>
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
/*-------------------------------------------*/

int RES;
int And(int i, int j) {
    i++, j++;
    cout << "AND " << i << " " << j << endl;
    cin >> RES;
    return RES;
}
int Or(int i, int j) {
    i++, j++;
    cout << "OR " << i << " " << j << endl;
    cin >> RES;
    return RES;
}

int n;
int ans[1 << 16];
int a[1 << 16];
int cnt[1 << 16]{1};
void init() {
    FOR(i, 1, n) {
        cout << "XOR 1 " << i + 1 << endl;
        cin >> a[i];
        cnt[a[i]]++;
    }
}
int Xor(int i, int j) { return a[i] xor a[j]; }

void Answer() {
    cout << "!";
    rep(i, n) cout << " " << ans[i];
    cout << endl;
    exit(0);
}

void solve1() {
    int x = max_element(cnt, cnt + n) - cnt;
    vector<int> v;
    rep(i, n) if(a[i] == x) v.push_back(i);
    ans[0] = And(v[0], v[1]) xor a[v[0]];
    FOR(i, 1, n) ans[i] = ans[0] xor a[i];
    Answer();
}

void solve2() {
    int x = -1;
    rep(i, n) if(a[i] == n - 1) x = i;
    int y = 1;
    if(y == x) y++;
    int x_0x = Xor(0, x);
    int x_0y = Xor(0, y);
    int x_xy = Xor(x, y);
    int s_0x = x_0x;
    int s_0y = x_0y + 2 * And(0, y);
    int s_xy = x_xy + 2 * And(x, y);
    int sum = (s_0x + s_0y + s_xy) / 2;
    ans[0] = sum - s_xy;
    FOR(i, 1, n) ans[i] = ans[0] xor a[i];
    Answer();
}

int main() {
    cin >> n;
    init();

    if(*max_element(cnt, cnt + n) > 1)
        solve1();
    else
        solve2();

    return 0;
}