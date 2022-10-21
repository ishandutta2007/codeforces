#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define what_is(x) cerr << #x << " is " << x << endl;

const int N = 2015;

int msk[10];
int cnt[N];
int curmask[N];
int n, k;
bool dp[N][N];
int pv[N][N];

void track(int d, int rem) {
    if(d == n + 1) return ;
    for(int x = 9; x >= 0; x--) {
        if((msk[x] | curmask[d]) == msk[x]) {
            int nxt = (cnt[msk[x]] - cnt[curmask[d]]);
//        cout << x << " " << d + 1 << " " << rem - nxt << endl;
            if(rem >= nxt && dp[d + 1][rem - nxt]) {
                cout << x;
                track(d + 1, rem - nxt);
                return ;
            }
        }
    }
}

int main() {
    vector<vi> dg =
            {
                    {1, 2, 3, 5, 6, 7},
                    {3, 6},
                    {1, 3, 4, 5, 7},
                    {1, 3, 4, 6, 7},
                    {2, 3, 4, 6},
                    {1, 2, 4, 6, 7},
                    {1, 2, 4, 5, 6, 7},
                    {1, 3, 6},
                    {1, 2, 3, 4, 5, 6, 7},
                    {1, 2, 3, 4, 6, 7}
            };
    for(int i = 0; i < 10; i++) {
        for(int x : dg[i]) msk[i] |= (1 << (x - 1));
    }
    for(int i = 1; i < (1 << 7); i++) cnt[i] = cnt[i / 2] + i % 2;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < 7; j++) curmask[i] |= ((str[j] == '1') << j);
//        cout << i << ": " << curmask[i] << endl;
    }
    dp[n + 1][0] = true;
    for(int i = n + 1; i >= 1; i--) {
        for(int j = 0; j <= k; j++) {
            if(!dp[i][j]) continue;
//            cout << i << " " << j << endl;
            for(int x = 0; x < 10; x++) {
                if((msk[x] | curmask[i - 1]) == msk[x]) {
                    int nxt = j + (cnt[msk[x]] - cnt[curmask[i - 1]]);
                    if(nxt <= k) dp[i-1][nxt] = true;
                }
            }
        }
    }
    if(!dp[1][k]) cout << "-1" << endl;
    track(1, k);
    cout << '\n';
}