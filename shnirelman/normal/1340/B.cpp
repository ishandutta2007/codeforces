#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int INF = 1e9;
const int N = 2000 + 13;

int msk[] = {1 + 2 + 4 + 16 + 32 + 64,
            4 + 32,
            1 + 4 + 8 + 16 + 64,
            1 + 4 + 8 + 32 + 64,
            2 + 8 + 4 + 32,
            1 + 2 + 8 + 32 + 64,
            1 + 2 + 8 + 16 + 32 + 64,
            1 + 4 + 32,
            1 + 2 + 4 + 8 + 16 + 32 + 64,
            1 + 2 + 4 + 8 + 32 + 64};

bool dp[N][N * 7];

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin  >> s;

        a[i] = 0;
        for(int j = 0; j < 7; j++) {
            a[i] += ((s[j] == '1') << (j));
        }
    }

    dp[n][0] = true;

    int mns = 0, mxs = 0;

    vector<pii> c(n);
    for(int i = n - 1; i >= 0; i--) {
        int mn = 1e9;
        int mx = 0;
        set<int> st;
        for(int xi = 0; xi < 10; xi++) {
            int x = msk[xi];
            if((a[i] | x) == x) {
                int cnt = 0;
                for(int l = 0; l < 10; l++)
                    if((x & (1 << l)) && ((a[i] & (1 << l)) == 0)) {
                        cnt++;
                    }

                st.insert(cnt);

                mn = min(mn, cnt);
                mx = max(mx, cnt);
            }
        }


        for(int j = 0; j < 7 * n; j++)
            for(auto x : st)
            if(dp[i + 1][j]) {
                dp[i][j + x] = true;
            }

        mns += mn;
        mxs += mx;

        c[i] = {mn, mx};
    }

//    for(int i = 0; i < 20; i++)
//        if(dp[0][i])
//            cout << i << ' ';
//    cout << endl;

//    vector<pii> suf(n + 1, {0, 0});
//    for(int i = n - 1; i >= 0; i--) {
//        suf[i].f = suf[i + 1].f + c[i].f;
//        suf[i].s = suf[i + 1].s + c[i].s;
//    }

    if(mns > k || mxs < k) {
        cout << -1;
        return;
    }


    string ans = "";
    for(int i = 0; i < n; i++) {
        for(int xi = 9; xi >= 0; xi--) {
            int x = msk[xi];
            if((a[i] | x) == x) {
                int cnt = 0;
                for(int l = 0; l < 10; l++)
                    if((x & (1 << l)) && ((a[i] & (1 << l)) == 0)) {
                        cnt++;
                    }
                if(dp[i + 1][k - cnt]) {
                    ans += char(xi + '0');
                    k -= cnt;
                    break;
                }

            }
        }
    }


    cout << (ans.size() < n ? "-1" : ans);
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}