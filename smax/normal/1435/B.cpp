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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> row(n, vector<int>(m)), col(m, vector<int>(n));
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                cin >> row[i][j];
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                cin >> col[i][j];

        vector<vector<int>> ret(n, vector<int>(m));
        int chk = -1;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (row[i][j] == col[0][0]) {
                    // found top row, found where first column belongs
                    ret[0] = row[i];
                    chk = j;
                    for (int k=0; k<n; k++)
                        ret[k][j] = col[0][k];
                    goto done;
                }
        done:;
        assert(chk != -1);
        DEBUG(ret, chk)
        for (int i=0; i<n; i++)
            if (row[i][0] != ret[0][0]) {
                for (int k=0; k<n; k++)
                    if (row[i][chk] == ret[k][chk]) {
                        ret[k] = row[i];
                        break;
                    }
            }

        DEBUG(ret)
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++)
                cout << ret[i][j] << " ";
            cout << "\n";
        }
    }

    return 0;
}