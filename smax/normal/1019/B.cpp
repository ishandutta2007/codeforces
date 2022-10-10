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

int query(int x) {
    cout << "? " << x + 1 << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int l = 0, r = n / 2, b0 = query(l) - query(r);
    if (b0 == 0) {
        cout << "! 1\n";
        return 0;
    } else if (b0 & 1) {
        cout << "! -1\n";
        return 0;
    }
    while (l < r) {
        int m = (l + r) / 2, b = query(m) - query(m + n / 2);
        if (b == 0) {
            cout << "! " << m + 1 << "\n";
            return 0;
        } else if (b < 0) {
            if (b0 < 0)
                l = m + 1;
            else
                r = m;
        } else {
            if (b0 < 0)
                r = m;
            else
                l = m + 1;
        }
    }

    cout << "! -1\n";

    return 0;
}