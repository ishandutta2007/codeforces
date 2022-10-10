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

int a[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    set<int> st;
    int j = n - 1;
    st.insert(a[j]);
    while (j > 0 && a[j-1] > a[j])
        st.insert(a[--j]);

    array<int, 3> best{n - j, -1, j};
    for (int i=0; i<n; i++) {
        if (i > 0 && a[i] <= a[i-1])
            break;
        while (st.count(a[i]))
            st.erase(a[j++]);
        best = max(best, {n - j + i + 1, i, j});
    }

    cout << best[0] << "\n";
    int l = 0, r = n - 1;
    while (l <= best[1] && r >= best[2]) {
        if (a[l] < a[r]) {
            cout << 'L';
            l++;
        } else {
            cout << 'R';
            r--;
        }
    }
    for (; l<=best[1]; l++)
        cout << 'L';
    for (; r>=best[2]; r--)
        cout << 'R';
    cout << "\n";

    return 0;
}