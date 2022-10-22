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
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 30;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;

/*
2 3
1 2
*/

int cur = 0;
int g[N * LOGN][2];
//int sz[N * 30];
int ind[N * LOGN];

void add(int x, int idx) {
    int v = 0;
    for(int i = LOGN - 1; i >= 0; i--) {
//        sz[v]++;
        int c = ((x >> i) & 1);
        if(g[v][c] == -1) {
            g[v][c] = cur;
            g[cur][0] = g[cur][1] = -1;
            cur++;
//            sz[cur] = 0;
        }

//        cout << "add " << v << ' ' << c << ' ' << g[v][c] << endl;

        v = g[v][c];
    }
//    sz[v]++;
    ind[v] = idx;
}

pii get(int x) {
    int v = 0;
    int res = 0;
    for(int i = LOGN - 1; i >= 0; i--) {
        int c = ((x >> i) & 1) ^ 1;

        if(g[v][c] == -1)
            c ^= 1;
//        cout << "get " << v << ' ' << c << ' ' << g[v][c] << endl;
        res += ((c << i) ^ (x & (1 << i)));
        v = g[v][c];
    }

//    cout << "get finish " << v << ' ' << ind[v] << ' ' << cur << ' ' << res << endl;
    return {res, ind[v]};
}


int n, k;
int a[N];
int mx = 0;



vector<int> solve(vector<int> pos) {
    if(pos.size() == 1)
        return pos;
//    for(auto i : pos) {
//        cout << i << ' ';
//    }
//    cout << endl;
//    exit(0);
    for(int i = 0; i <= cur; i++) {
        g[i][0] = g[i][1] = ind[i] = -1;
    }

    cur = 1;
    g[0][0] = g[0][1] = -1;

    for(int i : pos) {
        int x = (a[i] & ((1 << mx + 1) - 1));
        add(x, i);
    }

    for(int i : pos) {
        auto p = get(a[i] & ((1 << mx + 1) - 1));
//        cout << "solve " << i << ' ' << a[i] << ' '<< p.f << ' ' << p.s << endl;
        if(p.f >= k && p.s != i) {
            vector<int> res = {i, p.s};
            return res;
        }

    }

    return vector<int>(1, pos[0]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(k == 0) {
        cout << n << endl;
        for(int i = 0; i < n; i++) {
            cout << i + 1 << ' ';
        }
        cout << endl;
        return 0;
    }


    for(int i = 0; i < LOGN; i++) {
        if(k & (1 << i))
            mx = i;
    }

    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        mp[a[i] >> mx + 1].push_back(i);
    }

    vector<int> res;
    for(auto p : mp) {
        auto b = solve(p.s);
//        cout << p.f << endl;
//        for(auto i : p.s)
//            cout << a[i] << ' ';
//        cout << endl;
//        for(auto i : b)
//            cout << i << ' ';
//        cout << endl << endl;
        for(auto x : b)
            res.push_back(x);
    }

    if(res.size() <= 1) {
        cout << -1 << endl;
        return 0;
    }

    cout << res.size() << endl;
    for(int i : res)
        cout << i + 1 << ' ';
    cout << endl;
}