#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T, size_t N> ostream& operator << (ostream &os, const array<T, N> &a) {os << "("; for (int i=0; i<(int)N; i++) {if (i) os << ", "; os << a[i];} return os << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

long long a[200000], pref[200000], suff[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> a[i];

    sort(a, a + n);

    for (int i=0; i<n; i++)
        pref[i] = (i > 0 ? pref[i-1] : 0) + a[i];
    for (int i=n-1; i>=0; i--)
        suff[i] = (i < n - 1 ? suff[i+1] : 0) + a[i];

    long long ret = LLONG_MAX;
    for (int i=0, j=0; i<n; i=j) {
        while (j < n && a[j] == a[i])
            j++;
        if (j - i >= k)
            ret = 0;
        else {
            if (j < n && n - i >= k)
                ret = min(ret, suff[j] - (n - j) * (a[i] + 1) + k - j + i);
            if (i > 0 && j >= k)
                ret = min(ret, i * (a[i] - 1) - pref[i-1] + k - j + i);
            ret = min(ret, i * (a[i] - 1) - (i > 0 ? pref[i-1] : 0) + (j < n ? suff[j] : 0) - (n - j) * (a[i] + 1) + k - j + i);
        }
    }

    cout << ret << "\n";

    return 0;
}