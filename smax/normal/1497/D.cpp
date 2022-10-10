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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> tag(n), s(n);
        for (int i=0; i<n; i++)
            cin >> tag[i];
        for (int i=0; i<n; i++)
            cin >> s[i];
        vector<long long> dist(n);
        for (int i=1; i<n; i++)
            for (int j=i-1; j>=0; j--)
                if (tag[i] != tag[j]) {
                    long long di = dist[i], dj = dist[j];
                    dist[i] = max(dist[i], dj + abs(s[i] - s[j]));
                    dist[j] = max(dist[j], di + abs(s[i] - s[j]));
                }
        cout << *max_element(dist.begin(), dist.end()) << "\n";
    }

    return 0;
}