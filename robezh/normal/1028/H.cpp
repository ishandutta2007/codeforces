#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50, K = 8, Q = 1050000;
typedef pair<int, int> P;


int n, q;
int a[N];
vector<P> qs[N];

const int M = 5032107 + 50;

int p[M];
int mu[M], pm[M], pms;

void get_mobius_and_sieve(){
    mu[1] = 1;
    for(int i = 0; i < M; i++) p[i] = i;
    pms = 0;
    for(int i = 2; i < M; i++){
        if(p[i] == i){
            pm[pms++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < pms && i * pm[j] < M; j++){
            p[i * pm[j]] = pm[j];
            if(i % pm[j] == 0){
                mu[i * pm[j]] = 0;
                break;
            }
            mu[i * pm[j]] = -mu[i];
        }
    }
}

vector<P> get_divs(int x) {
    vector<int> d;
    vector<P> res;
    while(x > 1) d.push_back(p[x]), x /= p[x];
    int b = d.size();
    for(int i = 0; i < (1 << b); i++) {
        int cur = 1, cnt = b;
        for(int j = 0; j < b; j++) if(i & (1 << j)) cur *= d[j], cnt--;
        res.push_back({cur, cnt});
    }
    return res;
}


int to[M];
int rt[M][K];
int best[K * 2];
int res[Q];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    get_mobius_and_sieve();
    for(int i = 0; i < M; i++) to[i] = i;
    for(int i = 1; i * i < M; i++) {
        for(int j = 1; j * i * i < M; j++) {
            to[j * i * i] = min(to[j * i * i], j);
        }
    }

    memset(rt, -1, sizeof(rt));
    memset(best, -1, sizeof(best));
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i], a[i] = to[a[i]];
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--, r--;
        qs[r].push_back({l, i});
    }
    for(int i = 0; i < n; i++) {
        auto dv = get_divs(a[i]);

        for(auto p : dv) {
            for(int j = 0; j < K; j++) best[p.second + j] = max(best[p.second + j], rt[p.first][j]);
        }
        for(auto p : dv) rt[p.first][p.second] = i;
        for(auto qry : qs[i]) {
            for(int j = 0; j < 2 * K; j++) {
                if(best[j] >= qry.first) {
                    res[qry.second] = j;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < q; i++) cout << res[i] << "\n";

}