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

int a[1000];
vector<pair<int, int>> ret;
vector<int> order;

void solve() {
    for (int x : order) {
        int init = x;
        DEBUG(a[init])
        for (int j=init-1; j>=0; j--) {
            if (a[j] > a[init]) {
                ret.emplace_back(j, init);
                DEBUG(ret)
//                swap(a[v[j]], a[v[init]]);
            }
        }
//        solve(i+1, init-1, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    int ii = 0;
    vector<int> v;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if (a[j] < a[i]) {
                v.push_back(i);
                v.push_back(j);
                ii++;
            }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    order = v;
    sort(order.begin(), order.end(), [] (int x, int y) {
        if (a[x] == a[y])
            return x < y;
        return a[x] < a[y];
    });
//    for (int i=1; i<v.size(); i++)
//        if (a[v[i]] == a[v[i-1]]) {
//            cout << "-1\n";
//            return 0;
//        }

    DEBUG(v)
    solve();
    DEBUG(ret)
    reverse(ret.begin(), ret.end());
    for (auto &p : ret) {
        swap(a[p.first], a[p.second]);
    }
    DEBUG(ii)
    assert((int)ret.size() == ii);
//    DEBUG(ret)

    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if (a[j] < a[i]) {
                cout << "-1\n";
                return 0;
            }

    cout << ret.size() << "\n";
    for (auto &p : ret)
        cout << p.first + 1 << " " << p.second + 1 << "\n";

    return 0;
}