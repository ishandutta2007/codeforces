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

const int digits[] = {0, 4, 7};

set<int> dp[25];
map<int, array<int, 6>> par[25];

array<long long, 6> solve(const vector<int> &v) {
    int n = v.size();
    for (int i=0; i<=n; i++) {
        dp[i].clear();
        par[i].clear();
    }
    dp[0].insert(0);
    for (int i=0; i<n; i++)
        for (int j : dp[i])
            for (int a : digits)
                for (int b : digits)
                    for (int c : digits)
                        for (int d : digits)
                            for (int e : digits)
                                for (int f : digits) {
                                    int sum = a + b + c + d + e + f + j;
                                    if (sum % 10 == v[i]) {
                                        dp[i+1].insert(sum / 10);
                                        par[i+1][sum/10] = {a, b, c, d, e, f};
                                    }
                                }
    if (!dp[n].count(0))
        return {-1, -1, -1, -1, -1, -1};
    array<long long, 6> ret{0, 0, 0, 0, 0, 0};
    int carry = 0;
    for (int i=n; i>0; i--) {
        assert(par[i].count(carry));
        array<int, 6> &cur = par[i][carry];
        carry = 10 * carry + v[i-1];
        for (int j=0; j<6; j++) {
            ret[j] = 10 * ret[j] + cur[j];
            carry -= cur[j];
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        vector<int> v;
        while (n > 0) {
            v.push_back(n % 10);
            n /= 10;
        }

        array<long long, 6> ret = solve(v);
        if (ret[0] == -1) {
            cout << "-1\n";
        } else {
            for (int i=0; i<6; i++)
                cout << ret[i] << " ";
            cout << "\n";
        }
    }

    return 0;
}