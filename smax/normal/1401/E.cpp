#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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

#define MAX 1000000

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct Line {
    // 0 - start of horizontal line
    // 1 - vertical line
    // 2 - end of horizontal line
    int x, l, r, y, type;

    Line(int _x, int _y, int _type) : x(_x), y(_y), type(_type) {}

    Line(int _x, int _l, int _r, int _type) : x(_x), l(_l), r(_r), type(_type) {}

    bool operator < (const Line &other) const {
        if (x == other.x)
            return type < other.type;
        return x < other.x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<Line> lines;
    long long ret = 1;
    for (int i=0; i<n; i++) {
        int y, lx, rx;
        cin >> y >> lx >> rx;
        lines.emplace_back(lx, y, 0);
        lines.emplace_back(rx, y, 2);
        if (lx == 0 && rx == MAX)
            ret++;
    }
    for (int i=0; i<m; i++) {
        int x, ly, ry;
        cin >> x >> ly >> ry;
        lines.emplace_back(x, ly, ry, 1);
        if (ly == 0 && ry == MAX)
            ret++;
    }

    sort(lines.begin(), lines.end());
    ordered_set st;
    for (Line &l : lines) {
        if (l.type == 0) {
            // start of horizontal line
            st.insert(l.y);
        } else if (l.type == 1) {
            // vertical line
            ret += st.order_of_key(l.r + 1) - st.order_of_key(l.l);
        } else {
            // end of horizontal line
            st.erase(l.y);
        }
    }

    cout << ret << "\n";

    return 0;
}