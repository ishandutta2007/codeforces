#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 400 + 3;
const int INF = 1e9;

int n, m;
string s[N];
int a[N][N], la[N][N], ua[N][N], t[N][N];

int row_zero(int i, int l, int r){
    return la[i][r] - la[i][l - 1];
}
int row_one(int i, int l, int r){
    return r - l + 1 - row_zero(i, l, r);
}
int col_zero(int j, int l, int r){
    return ua[r][j] - ua[l - 1][j];
}
int col_one(int j, int l, int r){
    return r - l + 1 - col_zero(j, l, r);
}
int rect_zero(int x1, int y1, int x2, int y2){
    return t[x2][y2] - t[x1 - 1][y2] - t[x2][y1 - 1] + t[x1 - 1][y1 - 1];
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> s[i];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            a[i][j] = (s[i - 1][j - 1] == '1');

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            la[i][j] = a[i][j] + la[i][j - 1];
            ua[i][j] = a[i][j] + ua[i - 1][j];
        }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            t[i][j] = a[i][j] + t[i - 1][j] + t[i][j - 1] - t[i - 1][j - 1];

    int ans = INF;
    for(int l = 1; l <= m; ++l){
        for(int r = l + 3; r <= m; ++r){
            int curr = INF;
            for(int i = n - 4; i >= 1; --i){
                curr += !a[i + 1][l] + !a[i + 1][r] + row_zero(i + 1, l + 1, r - 1);
                check_min(curr, row_one(i + 4, l + 1, r - 1) + col_one(l, i + 1, i + 3) + col_one(r, i + 1, i + 3) + rect_zero(i + 1, l + 1, i + 3, r - 1));
                check_min(ans, curr + row_one(i, l + 1, r - 1));
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}