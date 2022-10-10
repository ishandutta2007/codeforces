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
        long long n;
        cin >> n;

        long long x = (n - 1) / 3 + 1, power = 1, a = 1;
        while (power < x) {
            x -= power;
            power *= 4;
            a *= 4;
        }
        a += x - 1;
        power = 1;
        x = a;
        long long b = 0, c = 0;
        while (x > 0) {
            if (x % 4 == 1) {
                b += power * 2;
                c += power * 3;
            } else if (x % 4 == 2) {
                b += power * 3;
                c += power;
            } else if (x % 4 == 3) {
                b += power;
                c += power * 2;
            }
            x /= 4;
            power *= 4;
        }

        cout << (n % 3 == 1 ? a : n % 3 == 2 ? b : c) << "\n";
    }

    return 0;
}