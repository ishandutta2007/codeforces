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

int a[200000], pref[200000][200];
vector<int> jump[200];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        for (int i=0; i<200; i++)
            jump[i].clear();

        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            a[i]--;
            jump[a[i]].push_back(i);
            for (int j=0; j<200; j++)
                pref[i][j] = (i > 0 ? pref[i-1][j] : 0) + (j == a[i]);
        }

        int ret = 1;
        for (int i=0; i<200; i++)
            for (int k=0; k<jump[i].size(); k++) {
                int l = jump[i][k], r = jump[i][jump[i].size()-k-1];
                if (l + 1 > r)
                    break;
                for (int j=0; j<200; j++)
                    ret = max(ret, 2 * k + 2 + pref[r-1][j] - pref[l][j]);
            }

        cout << ret << "\n";
    }

    return 0;
}