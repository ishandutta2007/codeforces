#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int INF = 1e9;
const int N = 203;

int get(int h, int t) {
    return h * N + t;
}

pii get(int i) {
    return {i / N, i % N};
}

int dp[N * N];
pii a[N], b[N];
vector<int> g[N * N], r[N * N];
vector<int> ts;
bool used[N * N];
int col[N * N], sz[N * N], d[N * N], tin[N * N], tout[N * N];
int T = 1;

void dfs1(int v) {
    used[v] = true;
    tin[v] = ++T;

//    cout << "in " << v << endl;

    for(auto u : g[v]) {
        if(!used[u])
            dfs1(u);
//        else if(tin[u] < tin[v]) {
//            cout << "Draw" << endl;
//            exit(0);
//        }
    }

//    cout<< "out " << v << endl;

    tout[v] = ++T;
    ts.push_back(v);
}

void dfs2(int v, int cl) {
    col[v] = cl;
    sz[cl]++;

//    cout << v << endl;

    for(auto u : r[v])
        if(col[u] == 0 && used[u])
            dfs2(u, cl);
        else if(v == u) {
            sz[cl]++;
        }
}


int main() {
    int h1, t1, R;
    cin >> h1 >> t1 >> R;

    int n, m;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> b[i].f >> b[i].s;
    }

    for(int h = 0; h < N; h++) {
        for(int t = 0; t < N; t++) {
            if(h + t > R)
                continue;

            for(int i = 0; i < n && i < h; i++) {
                int x = h - i - 1 + a[i].f, y = t + a[i].s;
//                if(i + 1 == h && t == 0)
//                    x = y = 0;

                if(x >= N && y >= N)
                    continue;

                if(x + y > R)
                    continue;

//                cout << get(h, t) << ' ' << get(x, y) << endl;

                g[get(h, t)].push_back(get(x, y));
                r[get(x, y)].push_back(get(h, t));
            }

            for(int i = 0; i < m && i < t; i++) {
                int x = h + b[i].f, y = t - i - 1 + b[i].s;
//                if(i + 1 == t && h == 0)
//                    x = y = 0;

                if(x >= N && y >= N)
                    continue;

                if(x + y > R)
                    continue;

//                cout << get(h, t) << ' ' << get(x, y) << endl;


                g[get(h, t)].push_back(get(x, y));
                r[get(x, y)].push_back(get(h, t));
            }
        }
    }

    {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                d[get(i, j)] = INF;

        d[get(h1, t1)] = 0;

        queue<int> q;
        q.push(get(h1, t1));

        while(!q.empty()) {
            int v = q.front();
            q.pop();

            for(auto u : g[v]) {
                if(d[v] + 1 < d[u]) {
                    d[u] = d[v] + 1;
                    q.push(u);
                }
            }
        }

        if(d[0] < INF) {
            cout << "Ivan" << endl << d[0] << endl;
            return 0;
        }
    }

    for(int i = 0; i < N * N; i++)
        tout[i] = INF;

    dfs1(get(h1, t1));


    reverse(ts.begin(), ts.end());
//    cout << ts.size() << endl;
//    for(auto x : ts)
//        cout << x << ' ';
//    cout << endl;

    int cl = 1;
    for(auto v : ts) {
//            cout << v << endl;
        if(col[v] == 0)
            dfs2(v, cl);

        if(sz[cl++] > 1) {
            cout << "Draw" << endl;
            return 0;
        }
    }



    for(int i = 0; i < N * N; i++)
        d[i] = 0;

    int ans = 0;
    for(int i = 1; i < ts.size(); i++) {
        int v = ts[i];
        for(auto u : r[v]) {
            d[v] = max(d[v], d[u] + 1);
//            if(tout[u] <= tout[v]) {
//                cout << "Draw" << endl;
//                return 0;
//            }
        }


//        cout << v << ' ' << d[v] << endl;

        ans = max(ans, d[v]);
    }

    cout << "Zmey" << endl << ans + 1 << endl;
//    for(auto ind : ts) {
//        pii p = get(ind);
//        int h = p.f, t = p.s;
//
//        if(h + t >= R) {
//            dp[ind] = -1;
//            continue;
//        }
//
//
//    }
}