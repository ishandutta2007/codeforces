#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
const int A = 1e6 + 13;
const int N = 1e7 + 13;
//const int N = 10;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(2);

int sum(int a, int b) {
    a += b;
    return (a < M ? a : a - M);
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

    return (k % 2 == 0 ? pw : mul(pw, n));
}

int cur = 1;
int go[N][2];
int sz[N];
//int cnt[N];

void add(int x, int d) {
    int v = 0;
    for(int i = 30; i >= 0; i--) {
        int c = ((x >> i) & 1);
        sz[v] += d;

        if(go[v][c] == -1) {
            go[cur][0] = go[cur][1] = -1;
            sz[cur] = 0;
//            cnt[cur] = 0;

            go[v][c] = cur;
            cur++;
        }

        v = go[v][c];
    }

    sz[v] += d;
//    cnt[v] += d;
}

int get(int x) {
    int v = 0;
    int res = 0;
    for(int i = 30; i >= 0; i--) {
        int c = ((x >> i) & 1) ^ 1;
        if(go[v][c] == -1 || sz[go[v][c]] == 0) {
            v = go[v][c ^ 1];
        } else {
            res |= (1 << i);
            v = go[v][c];
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    go[0][0] = go[0][1] = -1;
    add(0, 1);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        char c;
        int x;
        cin >> c >> x;

        if(c == '+')
            add(x, 1);
        else if(c == '-')
            add(x, -1);
        else
            cout << get(x) << '\n';
    }
}