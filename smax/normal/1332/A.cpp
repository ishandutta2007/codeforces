#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
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
        long long a, b, c, d, x, y, x1, y1, x2, y2;
        cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;

        bool xd = true, yd = true;
        if (x1 == x2 && (a > 0 || b > 0))
            xd = false;
        else if (x1 == x && b == 0 && a > 0)
            xd = false;
        else if (x2 == x && a == 0 && b > 0)
            xd = false;

        // walk as far in one direction as possible
        if (a > b) {
            int tmp = max(x1, x - a);
            a -= x - tmp;
            x = tmp;
            DEBUG(a)

            int mn = min(a, b);
            a -= mn, b -= mn;
            DEBUG(b)
            xd &= (a == 0 && b <= x2 - x1);
        } else {
            int tmp = min(x2, x + b);
            b -= tmp - x;
            x = tmp;

            int mn = min(a, b);
            a -= mn, b -= mn;
            xd &= (b == 0 && a <= x2 - x1);
        }

        if (y1 == y2 && (c > 0 || d > 0))
            yd = false;
        else if (y1 == y && d == 0 && c > 0)
            yd = false;
        else if (y2 == y && c == 0 && d > 0)
            yd = false;

        if (c > d) {
            int tmp = max(y1, y - c);
            c -= y - tmp;
            y = tmp;

            int mn = min(c, d);
            c -= mn, d -= mn;
            yd &= (c == 0 && d <= y2 - y1);
        } else {
            int tmp = min(y2, y + d);
            d -= tmp - y;
            y = tmp;

            int mn = min(c, d);
            c -= mn, d -= mn;
            yd &= (d == 0 && c <= y2 - y1);
        }

        cout << (xd && yd ? "YES" : "NO") << "\n";
    }

    return 0;
}