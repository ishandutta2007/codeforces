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

const int MAX = 505;

bool ckmax(int &a, int b) {
    return a < b ? a = b, true : false;
}

int a[MAX], b[MAX], nxt[MAX][2*MAX], dp[MAX][MAX], par[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> b[i];
        v.push_back(b[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i=0; i<n; i++)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    for (int i=0; i<m; i++)
        b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin();

    for (int j=0; j<n+m; j++)
        nxt[m][j] = -1;
    for (int i=m-1; i>=0; i--)
        for (int j=0; j<n+m; j++)
            nxt[i][j] = (b[i] == j ? i : nxt[i+1][j]);

    memset(dp, 128, sizeof(dp));
    dp[0][0] = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<=m; j++) {
            // skip element
            if (ckmax(dp[i+1][j], dp[i][j]))
                par[i+1][j] = j;
            // take element
            int pos = nxt[j][a[i]];
            if ((j == 0 || a[i] > b[j-1]) && pos != -1 && ckmax(dp[i+1][pos+1], dp[i][j] + 1))
                par[i+1][pos+1] = j;
        }

    int j = max_element(dp[n], dp[n] + m + 1) - dp[n];
    vector<int> ret;
    for (int i=n; i>0; i--) {
        if (j != par[i][j])
            ret.push_back(v[b[j-1]]);
        j = par[i][j];
    }
    reverse(ret.begin(), ret.end());

    cout << ret.size() << "\n";
    for (int x : ret)
        cout << x << " ";
    cout << "\n";

    return 0;
}