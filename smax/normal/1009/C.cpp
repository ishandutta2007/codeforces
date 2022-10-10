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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    long long ret = 0, all = (long long) n * (n - 1) / 2, half = (n % 2 ? (long long) (n / 2) * (n / 2 + 1) : (long long) (n / 2) * (n / 2 + 1) / 2 + (long long) (n / 2) * (n / 2 - 1) / 2);
    for (int i=0; i<m; i++) {
        int x, d;
        cin >> x >> d;
        ret += n * x;
        if (d > 0)
            ret += all * d;
        else
            ret += half * d;
    }

    cout << fixed << setprecision(10) << (double) ret / n << "\n";

    return 0;
}