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

const int MAXN = 1e6 + 5;
const int SZ = 177;

int p[MAXN], cnt[SZ], dpSmall[MAXN];
bool vis[MAXN];
bitset<MAXN> dpBig;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> p[i];
        p[i]--;
    }

    vector<int> big;
    int one = 0, two = 0;
    for (int i=0; i<n; i++)
        if (!vis[i]) {
            int u = i, len = 1;
            vis[u] = true;
            while (p[u] != i) {
                u = p[u];
                len++;
                vis[u] = true;
            }
            if (len < SZ)
                cnt[len]++;
            else
                big.push_back(len);
            if (len % 2)
                one++;
            two += len / 2;
        }

    // Solve for minimum
    dpBig[0] = 1;
    for (int x : big)
        dpBig |= dpBig << x;
    for (int j=0; j<=k; j++)
        dpSmall[j] = dpBig[j] - 1;
    for (int i=1; i<SZ; i++)
        for (int j=0; j<=k; j++) {
            if (dpSmall[j] >= 0)
                dpSmall[j] = 0;
            else if (j >= i && dpSmall[j-i] >= 0 && dpSmall[j-i] < cnt[i])
                dpSmall[j] = dpSmall[j-i] + 1;
            else
                dpSmall[j] = -1;
        }
    cout << k + (dpSmall[k] < 0) << " ";

    // Solve for maximum
    int change = min(two, k), ret = change * 2;
    k -= change;
    cout << ret + min(one, k) << "\n";

    return 0;
}