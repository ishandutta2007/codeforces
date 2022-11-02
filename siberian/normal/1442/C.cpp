#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) {
        return a - MOD;
    }
    return a;
}

int mul(int a, int b) {
    return (ll) a * b % MOD;
}

struct Edge{
    int to, type;
};

const int N = 2e5 + 10;
int n, m;
vector<Edge> g[N];

void read() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }
}

int pows[N];

void initPows() {
    pows[0] = 1;
    for (int i = 1; i < N; ++i) {
        pows[i] = mul(pows[i - 1], 2);
    }
    /*cout << "pows = " << endl;
    for (int i = 0; i < 10; ++i) {
        cout << pows[i] << " ";
    }
    cout << endl;*/
}

const ll INF = 1e15;

struct fq{
    int to, type;
    ll cost;
};

bool operator<(const fq& a, const fq& b) {
    return tie(a.cost, a.to, a.type) < tie(b.cost, b.to, b.type);
}

ll dist[N][2];
set<fq> q;

void relaxQ(int v, int type, ll cost) {
    if (dist[v][type] <= cost) return;
    q.erase({v, type, cost});
    dist[v][type] = cost;
    q.insert({v, type, cost});
}

ll getStupid() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            dist[i][j] = INF;
        }
    }
    relaxQ(0, 0, 0);
    while (!q.empty()) {
        int v = q.begin()->to;
        int myType = q.begin()->type;
        ll cost = q.begin()->cost;
        q.erase(q.begin());
        for (auto [to, type] : g[v]) {
            if (type == myType) {
                relaxQ(to, myType, cost + 1);
            } else {
                relaxQ(to, myType ^ 1, cost + N + 1);
            }
        }
    }
    return min(dist[n - 1][0], dist[n - 1][1]);
}

struct Event{
    int v, cnt, cost;
};

bool operator<(const Event& a, const Event& b) {
    return tie(a.cost, a.v, a.cnt) < tie(b.cost, b.v, b.cnt);
}

const int LOG = 19;
int dp[N][LOG];
set<Event> myQ;

void relax(int v, int cnt, int cost) {
    if (cnt >= LOG) return;
    if (dp[v][cnt] <= cost) return;
    myQ.erase({v, cnt, dp[v][cnt]});
    dp[v][cnt] = cost;
    myQ.insert({v, cnt, dp[v][cnt]});
}

int getSmart() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < LOG; ++j) {
            dp[i][j] = 1e9 + 228;
        }
    }
    relax(0, 0, 0);
    while (!myQ.empty()) {
        int v = myQ.begin()->v;
        int cnt = myQ.begin()->cnt;
        int cost = myQ.begin()->cost;
        myQ.erase(myQ.begin());
        for (auto [to, type] : g[v]) {
            if (type == cnt % 2) {
                relax(to, cnt, cost + 1);
            } else {
                relax(to, cnt + 1, cost + 1 + pows[cnt]);
            }
        }
    }
    /*cout << "dp = " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 4; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    int ans = 1e9 + 228;
    for (int i = 0; i < LOG; ++i) {
        chkmin(ans, dp[n - 1][i]);
    }
    return ans;
}

int ans;

void run() {
    ll have = getStupid();
    int cnt = have / N;
    //cout << "have = " << have << " cnt = " << cnt << " dist = " << have % N << endl;
    if (cnt < LOG) {
        ans = getSmart();
    } else {
        ans = have % N;
        for (int i = 1; i <= cnt; ++i) {
            ans = add(ans, pows[i - 1]);
        }
    }
}

void write() {
    cout << ans << endl;
}

signed main() {
    initPows();
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}