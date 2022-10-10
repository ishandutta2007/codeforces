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

int a[200005], b[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++)
        cin >> b[i];

    multiset<int> stA, stB;
    map<int, int> lastA, lastB;
    long long ret = 0;
    for (int i=0, j=0; i<n; i++) {
        stA.insert(a[i]);
        stB.insert(b[i]);
        lastA[a[i]] = i;
        lastB[b[i]] = i;
        while (j <= i && *stA.rbegin() > *stB.begin()) {
            stA.erase(stA.find(a[j]));
            stB.erase(stB.find(b[j]));
            if (lastA[a[j]] == j)
                lastA.erase(a[j]);
            if (lastB[b[j]] == j)
                lastB.erase(b[j]);
            j++;
        }
        if (!stA.empty() && *stA.rbegin() == *stB.begin())
            ret += min(lastA[*stA.rbegin()], lastB[*stA.rbegin()]) - j + 1;
    }
    cout << ret << "\n";

    return 0;
}