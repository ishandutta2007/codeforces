#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> P;

const int N = (int)1e5 + 50, M = (int)(1 << 17) + 5;

struct edge {
    int to, id;
};

int n, m;
vector<edge> G[N];
int low[N], pre[N];
int cost[N];
int ccnt = 0;
vector<int> bcc[N];
int cut[N];
stack<int> S;
int cnt = 0;

void init(int n) {
    for(int i = 0; i < n; i++) G[i].clear();
    for(int i = 0; i < n; i++) bcc[i].clear();
    ccnt = cnt = 0;
    fill(cut, cut + n, 0);
    fill(pre, pre + n, 0);
    fill(low, low + n, 0);
    while(!S.empty()) S.pop();
}

void dfs(int v, int par) {
    low[v] = pre[v] = ++cnt;

    int childcnt = 0;
    for(int j = 0; j < G[v].size(); j++) {
        edge e = G[v][j];
        if(e.to == par) continue;
        if(!pre[e.to]) {
            S.push(e.id);
            childcnt++;
            dfs(e.to, v);
            low[v] = min(low[v], low[e.to]);
            if(low[e.to] >= pre[v]) {
                cut[v] = true;
                int cur;
                do {
                    cur = S.top();
                    S.pop();
                    bcc[ccnt].push_back(cur);
                } while(cur != e.id);
                ccnt++;
            }
        }
        else if(pre[e.to] < pre[v]){
            S.push(e.id);
            low[v] = min(low[v], pre[e.to]);
        }
    }

    if(childcnt < 2 && par == -1) cut[v] = false;

}


struct FWT {
    const static int mod = (int)1e9 + 7, inv2 = (int)5e8 + 4;

    int add(int a, int b) {
        a = (a + b) % mod;
        if(a < 0) a += mod;
        return a;
    }

    int mul(int a, int b) {
        return (int)(1LL * a * b % mod);
    }

    // Please set N!!!
    int N;
    void FWTor(int *a, int opt) {
        for(int mid = 1; mid < N; mid <<= 1)
            for(int R = mid << 1, j = 0; j < N; j += R)
                for(int k = 0; k < mid; k++)
                    if(opt == 1) a[j + k + mid] = add(a[j + k], a[j + k + mid]);
                    else a[j + k + mid] = add(a[j + k + mid], -a[j + k]);
    }
    void FWTand(int *a, int opt) {
        for(int mid = 1; mid < N; mid <<= 1)
            for(int R = mid << 1, j = 0; j < N; j += R)
                for(int k = 0; k < mid; k++)
                    if(opt == 1) a[j + k] = add(a[j + k], a[j + k + mid]);
                    else a[j + k] = add(a[j + k], -a[j + k + mid]);
    }
    void FWTxor(int *a, int opt) {
        for(int mid = 1; mid < N; mid <<= 1)
            for(int R = mid << 1, j = 0; j < N; j += R)
                for(int k = 0; k < mid; k++) {
                    int x = a[j + k], y = a[j + k + mid];
                    if(opt == 1) a[j + k] = add(x, y), a[j + k + mid] = add(x, -y);
                    else a[j + k] = mul(add(x, y), inv2), a[j + k + mid] = mul(add(x, -y), inv2);
                }

    }

    void FWTxor(double *a, int opt) {
        for(int mid = 1; mid < N; mid <<= 1)
            for(int R = mid << 1, j = 0; j < N; j += R)
                for(int k = 0; k < mid; k++) {
                    double x = a[j + k], y = a[j + k + mid];
                    if(opt == 1) a[j + k] = (x + y), a[j + k + mid] = x - y;
                    else a[j + k] = (x + y) / 2, a[j + k + mid] = (x - y) / 2;
                }

    }
} fwt;

int freq[M], tmp[M];
double fd[M], td[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    init(n);
    int sum = 0;
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        cost[i] = c;
        sum ^= c;
//        p[i].first = a, p[i].second = b;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }
    for(int i = 0; i < n; i++) {
        if(!pre[i]) {
            dfs(i, -1);
        }
    }
    freq[sum]++;
    fd[sum] = 1;
    fwt.N = (1 << 17);
    fwt.FWTxor(freq, 1);
    fwt.FWTxor(fd, 1);
    for(int i = 0; i < ccnt; i++) {
        if(bcc[i].size() > 1) {
            memset(tmp, 0, sizeof(tmp));
            fill(td, td + M, 0);
//            cout << bcc[i].size() << ": ";
            for(int x : bcc[i]) {
                tmp[cost[x]]++;
                td[cost[x]] += 1;
//                cout << cost[x] << " ";
            }
//            cout << endl;
            fwt.FWTxor(tmp, 1);
            fwt.FWTxor(td, 1);
            for(int j = 0; j < fwt.N; j++) {
                freq[j] = fwt.mul(freq[j], tmp[j]);
                fd[j] = fd[j] * td[j];
            }
        }
    }
    fwt.FWTxor(freq, -1);
    fwt.FWTxor(fd, -1);
//    for(int i = 0; i < 10; i++) cout << freq[i] << " ";
//    cout << endl;
//    for(int i = 0; i < 10; i++) cout << fd[i] << " ";
//    cout << endl;
    for(int i = 0; i < fwt.N; i++) {
        if(fd[i] > (double)0.00001) {
            cout << i << " " << freq[i] << endl;
            return 0;
        }
    }
}