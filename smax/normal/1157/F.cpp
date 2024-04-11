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

int a[200000], cnt[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    sort(a, a + n);
    int i = 0, j = 0;
    array<int, 3> best{0, 0, 0};
    int prevCnt = 0;
    while (j < n) {
        if (j == 0 || a[j] == a[j-1])
            prevCnt++;
        else {
            if (a[j] - a[j-1] == 1 && (prevCnt > 1 || j - 1 == i)) {
                prevCnt = 1;
            } else {
                best = max(best, {j - i, i, j - 1});
                i = (a[j] - a[j-1] == 1 ? j - 1 : j);
                prevCnt = 1;
            }
        }
        j++;
    }
    best = max(best, {j - i, i, j - 1});

    cout << best[0] << "\n";
    for (int k=a[best[1]]; k<=a[best[2]]; k++)
        cout << k << " ";
    for (int k=a[best[2]]; k>=a[best[1]]; k--)
        for (int rep=0; rep<cnt[k]-1; rep++)
            cout << k << " ";
    cout << "\n";

    return 0;
}