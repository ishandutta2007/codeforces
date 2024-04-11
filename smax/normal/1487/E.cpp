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

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    vector<int> a(n1), b(n2), c(n3), d(n4);
    for (int i=0; i<n1; i++)
        cin >> a[i];
    for (int i=0; i<n2; i++)
        cin >> b[i];
    for (int i=0; i<n3; i++)
        cin >> c[i];
    for (int i=0; i<n4; i++)
        cin >> d[i];
    int m1, m2, m3;
    vector<vector<int>> adj1(n1), adj2(n2), adj3(n3);
    cin >> m1;
    for (int i=0; i<m1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj1[x].push_back(y);
    }
    cin >> m2;
    for (int i=0; i<m2; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj2[x].push_back(y);
    }
    cin >> m3;
    for (int i=0; i<m3; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj3[x].push_back(y);
    }

    multiset<int> st3(d.begin(), d.end());
    vector<int> dp3(n3);
    for (int i=0; i<n3; i++) {
        for (int v : adj3[i])
            st3.erase(st3.find(d[v]));
        dp3[i] = c[i] + (st3.empty() ? INF : *st3.begin());
        for (int v : adj3[i])
            st3.insert(d[v]);
    }
    DEBUG(dp3);
    multiset<int> st2(dp3.begin(), dp3.end());
    vector<int> dp2(n2);
    for (int i=0; i<n2; i++) {
        for (int v : adj2[i])
            st2.erase(st2.find(dp3[v]));
        dp2[i] = b[i] + (st2.empty() ? INF : *st2.begin());
        for (int v : adj2[i])
            st2.insert(dp3[v]);
    }
    DEBUG(dp2);
    multiset<int> st1(dp2.begin(), dp2.end());
    vector<int> dp1(n1);
    for (int i=0; i<n1; i++) {
        for (int v : adj1[i])
            st1.erase(st1.find(dp2[v]));
        dp1[i] = a[i] + (st1.empty() ? INF : *st1.begin());
        for (int v : adj1[i])
            st1.insert(dp2[v]);
    }
    DEBUG(dp1);

    int ret = *min_element(dp1.begin(), dp1.end());
    cout << (ret >= INF ? -1 : ret) << "\n";

    return 0;
}