#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 200050, INF = (int)1e9;

bool p[M];
int mu[M], pm[M], pms;

void get_mobius_and_sieve(){
    mu[1] = 1;
    fill(p, p + M, true);
    pms = 0;
    for(int i = 2; i < M; i++){
        if(p[i]){
            pm[pms++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < pms && i * pm[j] < M; j++){
            p[i * pm[j]] = false;
            if(i % pm[j] == 0){
                mu[i * pm[j]] = 0;
                break;
            }
            mu[i * pm[j]] = -mu[i];
        }
    }
}

struct Flow {
    const static int N = 105, INF = (int)1e9;

    struct edge{
        int to, cap, rev;
        edge(int _to, int _cap, int _rev){
            to = _to, cap = _cap, rev = _rev;
        }
    };

    vector<edge> G[N];
    bool used[N];

    Flow() {
        for(int i = 0; i < N; i++) G[i].clear();
    }

    void add_edge(int from, int to, int cap){
        G[from].push_back(edge(to, cap, G[to].size()));
        G[to].push_back(edge(from, 0, G[from].size() - 1));
    }

    int dfs(int v, int t, int f){
        if(v == t) return f;
        used[v] = true;

        for(int i = 0; i < G[v].size(); i++){
            edge &e = G[v][i];
            if(!used[e.to] && e.cap > 0){
                int d = dfs(e.to, t, min(e.cap, f));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t){
        int f = 0;
        for(;;){
            fill(used, used + N, false);
            int d = dfs(s, t, INF);
            if(d == 0) return f;
            f += d;
        }
    }
};

int n, k;
int pw[N], num[N], lev[N];

bool check(int lev_now) {
    int sum = 0;
    int mx1 = -1;
    vector<int> ls[2];
    for(int i = 0; i < n; i++) {
        if(lev[i] > lev_now) continue;
        if(num[i] == 1) {
            if(mx1 == -1 || pw[i] > pw[mx1]) mx1 = i;
        }
        else {
            ls[num[i] % 2].push_back(i);
            sum += pw[i];
        }
    }
    if(mx1 != -1) ls[1].push_back(mx1), sum += pw[mx1];

    int s = n, t = s + 1;
    Flow flow;
    for(int i : ls[0]) flow.add_edge(s, i, pw[i]);
    for(int i : ls[0]) {
        for(int j : ls[1]) {
            if(p[num[i] + num[j]]) flow.add_edge(i, j, INF);
        }
    }
    for(int j : ls[1]) flow.add_edge(j, t, pw[j]);

    return sum - flow.max_flow(s, t) >= k;

}

int main() {
    get_mobius_and_sieve();
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> pw[i] >> num[i] >> lev[i];
    }
    int l = 0, r = n + 1, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << (r == n + 1 ? -1 : r) << endl;
}