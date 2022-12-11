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

bool comp(const string &a, const string &b) {
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

string add(string a, string b) {
    if(a.size() > b.size()) swap(a, b);
    string res("0");
    while(!b.empty()) {
        if(a.empty()) {
            res.back() += b.back() - '0';
            if(res.back() > '9') {
                res.back() -= 10;
                res.push_back('1');
            } else
                res.push_back('0');
            b.pop_back();
        } else {
            res.back() += b.back() + a.back() - '0' - '0';
            if(res.back() > '9') {
                res.back() -= 10;
                res.push_back('1');
            } else
                res.push_back('0');
            a.pop_back();
            b.pop_back();
        }
    }
    while(res.back() == '0') res.pop_back();
    reverse(ALL(res));
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int l;
    string s;
    cin >> l >> s;
    int x = l / 2, y = l / 2 + 1;
    while(x > 0 && s[x] == '0') x--;
    while(y < l && s[y] == '0') y++;

    if(x == 0) x = y;
    if(y == l) y = x;

    string a = add(s.substr(0, x), s.substr(x));
    string b = add(s.substr(0, y), s.substr(y));

    if(comp(a, b))
        cout << a << endl;
    else
        cout << b << endl;

    return 0;
}