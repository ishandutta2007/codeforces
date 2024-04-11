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
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

int di[] = {-1, -1, 1, 1};
int dj[] = {-1, 1, -1, 1};

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;
    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);
    if(k % 2)
        return mul(pw, n);
    else
        return pw;
}
/*
1
2 2 1 1 2 1 25
*/

int inv100 = pow2(100, M - 2);

vector<char> used[4][N];
int p1[N];

void solve() {
    int n, m, i, j, x, y, p;
    cin >> n >> m >> i >> j >> x >> y >> p;

    i--;
    j--;
    x--;
    y--;

    int k = 3;

    int len = 0;
    int cyc = 0;
    vector<int> pos;

    for(int k = 0; k < 4; k++)
        for(int i = 0; i < n; i++) {
            used[k][i].resize(m, 0);
        }

    while(true /* !used[k][i][j]*/) {
//        cout << k << ' ' << i << ' ' << j << endl;



        int i1 = i + di[k], j1 = j + dj[k];

        if(i1 < 0 || i1 >= n)
            k ^= 2;
        if(j1 < 0 || j1 >= m)
            k ^= 1;

        if(used[k][i][j])
            break;

        if(i == x || j == y) {
            pos.push_back(len);
        }

        used[k][i][j] = true;

        i += di[k];
        j += dj[k];

        len++;
    }

//    cout << len << endl;
//    for(auto x : pos)
//        cout << x << ' ';
//    cout << endl;

//    return;

    p1[0] = 1;
    p1[1] = mul(100 - p, inv100);
    for(int i = 2; i < N; i++) {
        p1[i] = mul(p1[i - 1], p1[1]);
    }

//    cout << "p p1 " << mul(p, inv100) << ' ' << p1[1] << endl;


    int res = 0;
    for(int i = 0; i < pos.size(); i++) {
        res = sum(res, mul(pos[i], mul(p1[i], mul(p, inv100))));
    }

//    cout << res << endl;

    int ans = mul(sum(res, mul(p1[pos.size()], len)), pow2(dif(1, p1[pos.size()]), M - 2));
//    cout << pos.size() << ' ' << len << ' ' << p1[pos.size()] << endl;
//    cout << mul(p1[pos.size()], len) << endl;
//    cout << sum(res, mul(p1[pos.size()], len)) << endl;
//    cout << dif(1, p1[pos.size()]) << endl;

    cout << ans << endl;

    for(int k = 0; k < 4; k++)
        for(int i = 0; i < n; i++) {
            used[k][i].erase(used[k][i].begin(), used[k][i].end());
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