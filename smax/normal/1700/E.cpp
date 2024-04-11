#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for (auto &v : a)
        for (int &x : v)
            cin >> x;

    auto valid = [&] (int r, int c) -> bool {
        return 0 <= r && r < n && 0 <= c && c < m;
    };

    auto isGood = [&] (int r, int c) -> bool {
        if (a[r][c] == 1)
            return true;
        bool ok = false;
        for (int i=0; i<4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            ok |= valid(nr, nc) && a[nr][nc] < a[r][c];
        }
        return ok;
    };

    set<pair<int, int>> bad;
    for (int r=0; r<n; r++)
        for (int c=0; c<m; c++)
            if (!isGood(r, c))
                bad.emplace(r, c);

    if (bad.empty()) {
        cout << "0\n";
        return 0;
    }

    auto test = [&] (int ar, int ac, int br, int bc) -> bool {
        vector<pair<int, int>> stk;
        if (bad.count({ar, ac})) {
            bad.erase({ar, ac});
            stk.emplace_back(ar, ac);
        }
        for (int i=0; i<4; i++) {
            int nr = ar + dr[i], nc = ac + dc[i];
            if (bad.count({nr, nc})) {
                bad.erase({nr, nc});
                stk.emplace_back(nr, nc);
            }
        }
        if (bad.count({br, bc})) {
            bad.erase({br, bc});
            stk.emplace_back(br, bc);
        }
        for (int i=0; i<4; i++) {
            int nr = br + dr[i], nc = bc + dc[i];
            if (bad.count({nr, nc})) {
                bad.erase({nr, nc});
                stk.emplace_back(nr, nc);
            }
        }
        bool ret = bad.empty();
        if (bad.empty()) {
            swap(a[ar][ac], a[br][bc]);
            ret &= isGood(ar, ac);
            ret &= isGood(br, bc);
            for (int i=0; i<4; i++) {
                int nr = ar + dr[i], nc = ac + dc[i];
                if (valid(nr, nc))
                    ret &= isGood(nr, nc);
            }
            for (int i=0; i<4; i++) {
                int nr = br + dr[i], nc = bc + dc[i];
                if (valid(nr, nc))
                    ret &= isGood(nr, nc);
            }
            swap(a[ar][ac], a[br][bc]);
        }
        for (auto [r, c] : stk)
            bad.emplace(r, c);
        return ret;
    };

    auto [sr, sc] = *bad.begin();
    int ret = 0;
    for (int r=0; r<n; r++)
        for (int c=0; c<m; c++)
            if ((r != sr || c != sc) && test(sr, sc, r, c))
                ret++;
    for (int i=0; i<4; i++) {
        int nr = sr + dr[i], nc = sc + dc[i];
        if (valid(nr, nc))
            for (int r=0; r<n; r++)
                for (int c=0; c<m; c++)
                    if ((r != sr || c != sc) && (r != nr || c != nc) && test(nr, nc, r, c))
                        ret++;
    }

    if (ret == 0)
        cout << "2\n";
    else
        cout << "1 " << ret << "\n";

    return 0;
}