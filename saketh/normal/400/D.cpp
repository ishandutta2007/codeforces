#include <bits/stdc++.h>
using namespace std;

struct union_find{
    vector<int> P, R, S;
    
    union_find(int N){
        P.resize(N), R.resize(N), S.resize(N);
        for(int i=0; i<N; i++){
            P[i] = i;
            R[i] = 0;
            S[i] = 1;
        }
    }
    
    int rep(int i){
        if(P[i] != i) P[i] = rep(P[i]);
        return P[i];
    }

    bool unio(int a, int b){
        a = rep(a), b = rep(b);
        if(a == b) return false;
        if(R[a] < R[b]) swap(a, b);
        P[b] = a;
        S[a] += S[b];
        if(R[a] == R[b]) R[a]++;
        return true;
    }
};

typedef long long ll;

const ll INF = 1e10;
const int MAXN = 1e5 + 100;
const int MAXK = 512;

int N, M, K;
int type[MAXN];
ll dist[MAXK][MAXK];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M >> K;

    int t = 0;
    for (int i = 0; i < K; i++) {
        int q; 
        cin >> q;

        for (int j = 0; j < q; j++) {
            type[t++] = i;
        }
    }

    union_find uf(N);

    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            dist[i][j] = (i == j) ? 0 : INF;

    for (int i = 0; i < M; i++) {
        int u, v;
        ll x;

        cin >> u >> v >> x;        
        u--, v--;

        if (x == 0) uf.unio(u, v);

        int t1 = type[u], t2 = type[v];
        dist[t1][t2] = min(dist[t1][t2], x);
        dist[t2][t1] = min(dist[t2][t1], x);
    }

    for (int i = 1; i < N; i++) {
        if (type[i] == type[i-1] && uf.rep(i) != uf.rep(i-1)) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int k = 0; k < K; k++)
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    cout << "Yes\n";
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++)
            cout << ((dist[i][j] == INF) ? -1 : dist[i][j]) << " ";
        cout << "\n";
    }
}