//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 33;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 400;

mt19937 rnd(0);

int di[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dj[] = {-1, 0, 1, 1, 1, 0, -1, -1};


int n;
int t[N];

bool dp[K][K][N][8];
bool a[K][K];

void calc(int i, int j, int cur, int dir) {
    if(cur == n)
        return;
    if(dp[i][j][cur][dir])
        return;

    dp[i][j][cur][dir] = true;

    for(int ind = 0; ind < t[cur]; ind++) {
        i += di[dir];
        j += dj[dir];
        a[i][j] = true;
    }

    calc(i, j, cur + 1, (dir + 1) % 8);
    calc(i, j, cur + 1, (dir + 7) % 8);
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> t[i];

    calc(K / 2, K / 2, 0, 1);

    int ans = 0;
    for(int i = 0; i < K; i++)
        for(int j = 0; j < K; j++)
            ans += a[i][j];

    cout << ans << endl;
}