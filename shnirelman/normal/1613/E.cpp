#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e6 + 113;
const int M = 998244353;//1e9 + 7;
const int A = 26;

int di[] = {0, -1, 0, 1};
int dj[] = {-1, 0, 1, 0};

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

/*
*/

string s[N];

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int labi = -1, labj = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == 'L') {
                labi = i;
                labj = j;
            }
        }
    }

//    vector<vector<int>> cnt(n, )

    vector<vector<char>> used(n, vector<char>(m, 0));

    queue<pii> q;
    q.push({labi, labj});
    used[labi][labj] = 1;

    while(!q.empty()) {
        int i = q.front().f;
        int j = q.front().s;

        q.pop();

        for(int k = 0; k < 4; k++) {
            int i1 = i + di[k];
            int j1 = j + dj[k];

            if(i1 < 0 || i1 >= n || j1 < 0 || j1 >= m || s[i1][j1] == '#' || used[i1][j1])
                continue;

            int cnt = 0;
            for(int k1 = 0; k1 < 4; k1++) {
                int i2 = i1 + di[k1];
                int j2 = j1 + dj[k1];

                if(0 <= i2 && i2 < n && 0 <= j2 && j2 < m && s[i2][j2] == '.' && !used[i2][j2])
                    cnt++;
            }

            if(cnt <= 1) {
                used[i1][j1] = 1;
                q.push({i1, j1});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << (s[i][j] != '.' ? s[i][j] : (used[i][j] ? '+' : '.'));
        }
        cout << '\n';
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}