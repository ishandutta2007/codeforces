#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

pair<int, int> c[300000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, x1, x2;
    cin >> n >> x1 >> x2;
    for (int i=0; i<n; i++) {
        cin >> c[i].first;
        c[i].second = i;
    }

    for (int swapped=1; swapped>=0; swapped--) {
        swap(x1, x2);
        vector<pair<int, int>> v1, v2;
        sort(c, c + n);
        for (int i=1; i<n; i++) {
            int pos = lower_bound(c, c + n, make_pair((x2 + i - 1) / i, 0)) - c;
            if (n - pos >= i) {
                for (int j=0; j<n; j++) {
                    if (pos <= j && j < pos + i)
                        v2.push_back(c[j]);
                    else
                        v1.push_back(c[j]);
                }
                break;
            }
        }
        if (v1.empty() || v2.empty())
            continue;

        int pos = v1.size() - 1;
        while (pos >= 0 && x1 > v1[pos].first * (v1.size() - pos))
            pos--;
        if (pos < 0)
            continue;
        v1.erase(v1.begin(), v1.begin() + pos);

        if (swapped)
            v1.swap(v2);
        cout << "Yes\n" << v1.size() << " " << v2.size() << "\n";
        for (int i=0; i<v1.size(); i++)
            cout << v1[i].second + 1 << " \n"[i==v1.size()-1];
        for (int i=0; i<v2.size(); i++)
            cout << v2[i].second + 1 << " \n"[i==v2.size()-1];

        return 0;
    }
    cout << "No\n";

    return 0;
}