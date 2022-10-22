#include <bits/stdc++.h>
#define int long long

#define TASKNAME ""

using namespace std;

const int INF = 1e18 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
int dp[30001], dp2[30001];
void Push(deque<int> &d, int el){
    while (d.size() && el > d.back()) d.pop_back();
    d.push_back(el);
}
int Try(vector<int> &symb, int wh, int n, int m){
    for (int i=1; i <= n; i++) dp[i] = -INF;
    dp[0] = 0;
    for (int i=0; i < symb.size(); i++){
        int ct = symb[i];
        deque<int> dk;
        for (int j=0; j <= n; j++) dp2[j] = -INF;
        for (int j=0; j <= n; j++){
            dp2[j] = max(dp2[j], min(m, dp[j] + ct));
            Push(dk, dp[j]);
            if (j > ct && dk.front() == dp[j-ct-1]) dk.pop_front();
            dp2[j] = max(dp2[j], dk.front());
        }
        for (int j=0; j <= n; j++) dp[j] = dp2[j];
    }
    int kk = INF;
    for (int j=0; j <= n; j++){
        int a = n - j, b = m - dp[j];
        if (a+b > wh) continue;
        kk = min(kk, a*b);
    }
    return kk;
}
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    //cout << n << " " << m << " " << k << endl;
    string s;
    cin >> s;
    int a[26];
    for (int i=0; i < 26; i++) a[i] = 0;
    for (int i=0; i < k; i++) a[s[i] - 'A']++;
    int ans = INF;
    for (int i=0; i < 26; i++){
        vector<int> kek;
        for (int j=0; j < 26; j++) if (i != j) kek.push_back(a[j]);
        ans = min(ans, Try(kek, a[i], n, m));
    }
    cout << ans << endl;
}
signed main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int t;
    cin >> t;
    for (int i=0; i < t; i++) solve();
}