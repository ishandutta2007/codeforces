#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    vector<int> cnt(p);
    map<int, vector<int>> add;
    map<int, vector<pair<int, int>>> rem;
    int neg = 0;
    for (int i=n-1; i>=0; i--) {
        int cur = a[i] - (a[n-1] - n);
        if (cur <= 0) {
            if ((i + 1) % p == 0) {
                cout << "0\n";
                return 0;
            }
        } else if (cur > i + 1) {
            neg++;
            add[a[n-1] - n + cur - (i + 1)].push_back(i);
        } else {
            cnt[(p - (i + 1 - cur) % p) % p]++;
            rem[a[i]].emplace_back(i, (p - (i + 1 - cur) % p) % p);
        }
    }

    int ti = 0;
    vector<int> ret;
    for (int x=a[n-1]-n+1; x<a[n-1]; x++) {
        ti = (ti + 1) % p;
        if (add.count(x))
            for (int i : add[x]) {
                neg--;
                cnt[ti]++;
                rem[a[i]].emplace_back(i, ti);
            }
        if (rem.count(x))
            for (auto [i, y] : rem[x]) {
                cnt[y]--;
                if ((i + 1) % p == 0)
                    goto done;
            }
        if (x > 0 && neg == 0 && cnt[ti] == 0)
            ret.push_back(x);
    }
    done:;

    cout << ret.size() << "\n";
    for (int x : ret)
        cout << x << " ";
    cout << "\n";

    return 0;
}