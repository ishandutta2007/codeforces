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

string grid[1000];
bool stamped[1000][1000] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> grid[i];

    for (int i=1; i<n-1; i++)
        for (int j=1; j<m-1; j++) {
            bool ok = true;
            for (int d=-1; d<=1; d++)
                for (int e=-1; e<=1; e++)
                    if ((d || e) && grid[i+d][j+e] == '.') {
                        ok = false;
                        break;
                    }
            if (ok)
                for (int d=-1; d<=1; d++)
                    for (int e=-1; e<=1; e++)
                        if (d || e)
                            stamped[i+d][j+e] = true;
        }

    bool ok = true;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (grid[i][j] == '#' && !stamped[i][j]) {
                ok = false;
                break;
            }

    cout << (ok ? "YES" : "NO") << "\n";

    return 0;
}