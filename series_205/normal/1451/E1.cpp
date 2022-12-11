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
int Xor(int i, int j) {
    i++, j++;
    cout << "XOR " << i << " " << j << endl;
    cin >> RES;
    return RES;
}

int n;
int ans[1 << 16];

void Answer() {
    cout << "!";
    rep(i, n) cout << " " << ans[i];
    cout << endl;
    exit(0);
}

int main() {
    cin >> n;
    int xor01 = Xor(0, 1);
    int xor02 = Xor(0, 2);
    int xor12 = xor01 xor xor02;
    int sum01 = xor01 + 2 * And(0, 1);
    int sum02 = xor02 + 2 * And(0, 2);
    int sum12 = xor12 + 2 * And(1, 2);

    int sum = (sum01 + sum02 + sum12) / 2;
    ans[0] = sum - sum12;
    ans[1] = sum - sum02;
    ans[2] = sum - sum01;

    FOR(i, 3, n) ans[i] = ans[0] xor Xor(0, i);

    Answer();

    return 0;
}