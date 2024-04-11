//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

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

/*
*/
int n;
vector<int> a[N];
//map<vector<int>, pair<vector<int>, int>> g;
map<vector<int>, int> d;

//void calc(int i, vector<int> cur) {
//    if(i == n) {
//        vector<int> x = cur;
//        for(int j = 0; j < n; j++) if(cur[j] > 0) {
//            x[j]--;
//            g[cur].emlace_back(x, a[j][cur[j]] - a[j][x[j]]);
//            x[j]++;
//        }
//        return;
//    }
//
//    cur.push_back(0);
//    for(; cur.back() < a[i].size(); cur.back()++)
//        calc(i + 1, cur);
//}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;

    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;

        a[i].resize(k);
        for(int j = 0; j < k; j++)
            cin >> a[i][j];
    }

//    calc(0, vector<int>(0));

    int m;
    cin >> m;

    set<vector<int>> st;
    for(int i = 0; i < m; i++) {
        vector<int> b(n);
        for(int j = 0; j < n; j++) {
            cin >> b[j];
            b[j]--;
        }
        st.insert(b);
    }

    int ans = 0;
    vector<int> root(n);
    for(int i = 0; i < n; i++) {
        root[i] = a[i].size() - 1;
        ans += a[i].back();
    }

    d[root] = 0;
    set<pair<int, vector<int>>> q;
    q.insert({0, root});
    while(!q.empty()) {
        vector<int> v = q.begin()->s;
        q.erase(q.begin());

        if(st.count(v) == 0) {
            for(auto x : v)
                cout << x + 1 << ' ';
            return 0;
        }

        vector<int> u = v;
        for(int j = 0; j < n; j++) if(v[j] > 0) {
            u[j]--;
            int w = d[v] + a[j][v[j]] - a[j][u[j]];
            if(d.count(u) == 0 || d[u] > w) {
                q.erase({d[u], u});
                d[u] = w;
                q.insert({d[u], u});
            }
            u[j]++;
        }

    }
}