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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cuts = 0;
        vector<int> a(n), freq(n + 1), endPoints(n + 1);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            freq[a[i]]++;
            if (i > 0 && a[i] == a[i-1]) {
                cuts++;
                endPoints[a[i]]++;
                endPoints[a[i-1]]++;
            }
        }
        endPoints[a[0]]++;
        endPoints[a[n-1]]++;
        if (*max_element(freq.begin(), freq.end()) > (n + 1) / 2)
            cout << "-1\n";
        else
            cout << cuts + max(*max_element(endPoints.begin(), endPoints.end()) - (cuts + 2), 0) << "\n";
    }

    return 0;
}