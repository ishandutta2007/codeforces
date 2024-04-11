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

    int t;
    cin >> t;
    while (t--) {
        long long n, l, r;
        cin >> n >> l >> r;
        l--, r--;

        long long sub = 2 * n - 2;
        int st = 1;
        while (sub > 0 && sub <= l) {
            l -= sub;
            r -= sub;
            sub -= 2;
            st++;
        }

        vector<int> seq;
        while (r >= seq.size()) {
            if (st == n) {
                seq.push_back(1);
                break;
            }
            for (int i=st+1; i<=n; i++) {
                seq.push_back(st);
                seq.push_back(i);
            }
            st++;
        }

        for (int i=l; i<=r; i++)
            cout << seq[i] << " ";
        cout << "\n";
    }

    return 0;
}