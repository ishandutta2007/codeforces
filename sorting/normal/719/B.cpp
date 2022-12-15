#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 3;

int dp[N][2][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> a(n + 1);
    for(int i = 0; i < n; ++i)
        a[i] = s[i] == 'r';

    int cnt[2][2]{};
    for(int i = 0; i < n; ++i)
        cnt[(i & 1)][(a[i] & 1)] += 1;

    int ans = N;
    for(int col = 0; col <= 1; ++col){
        int mn = min(cnt[0][!col], cnt[1][col]);
        int mx = max(cnt[0][!col], cnt[1][col]);
        check_min(ans, mx);
    }

    cout << ans << "\n";
}