#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

struct union_find {
    int CC; // track the number of connected components

    int N;
    vector<int> P, R, S, ops;
    bool tracked;
    
    union_find(int _N){
        N = _N;
        CC = N;
        P.resize(N), R.resize(N), S.resize(N);
        for(int i=0; i<N; i++){
            P[i] = -1;
            R[i] = 0;
            S[i] = 1;
        }
        tracked = false;
    }

    void compress(int loc, int until) {
        while (loc != until) {
            int par = P[loc];
            P[loc] = until;
            loc = par;
        }
    }
    
    int rep(int i) {
        while (P[i] != -1)
            i = P[i];
        return i;
    }

    bool unio(int a, int b){
        int ar = rep(a);
        int br = rep(b);

        if (ar == br) {
            if (!tracked) {
                compress(a, ar);
                compress(b, ar);
            }
            return false;
        }
    
        if (S[ar] < S[br]) {
            swap(a, b);
            swap(ar, br);
        }
        
        P[br] = ar;
        S[ar] += S[br];
        CC--;

        if (tracked) {
            ops.push_back(br);
        } else {
            // safe to compress
            compress(a, ar);
            compress(b, ar);
        }

        return true;
    }

    void rewind() {
        while (ops.size()) {
            int detach = ops.back();
            ops.pop_back();

            int parent = P[detach];
            P[detach] = -1;

            S[parent] -= S[detach];
            CC++;
        }

        tracked = false;
    }
};

const int MAXN = 1e5 + 100;
const int MAXQ = 1e5 + 100;

struct query {
    int i, a, b;
};

int N, K, M, Q;
vector<int> bef[MAXN], aft[MAXN];

vector<query> queries;
ll ans[MAXQ];

void go(vector<query> &bucket, int B, int l, int r) {
    //cout << "Solving bucket of queries with a in [" << l + 1 << ", " << r + 1 << "]\n";
    //for (query &q : bucket)
    //    cout << q.a << " " << q.b << " (" << q.i << ")\n";

    vector<pair<int, int>> edges;
    for (int i = l; i < r; i++) {
        for (int j : aft[i])
            edges.emplace_back(i, j);
    }

    // sort in non-increasing order of u
    sort(edges.begin(), edges.end(), [](const pair<int, int> &e1, const pair<int, int> &e2) {
        return e1.first > e2.first;
    });

    int fin = r - 1;
    int lim = bucket.back().b;
    union_find uf(lim - l + 1);

    for (query &q : bucket) {
        // advance the scope end
        while (q.b > fin) {
            fin++;
            for (int i : bef[fin]) 
                if (i >= r) uf.unio(i - l, fin - l);
        }

        // temporarily adjust the scope front
        uf.tracked = true;

        for (pair<int, int> e : edges) {
            if (e.first < q.a) continue;
            if (e.second <= q.b) uf.unio(e.first - l, e.second - l);
        }

        int extra = uf.N - (q.b - q.a + 1);
        ans[q.i] = uf.CC - extra;

        uf.rewind();
    }
}

// mo's algorithm
void solve() {
    for (int i = 0; i < N; i++) {
        sort(bef[i].begin(), bef[i].end());
        sort(aft[i].begin(), aft[i].end());
    }

    sort(queries.begin(), queries.end(), [](const query &q1, const query &q2) {
        if (q1.a != q2.a) return q1.a < q2.a;
        if (q1.b != q2.b) return q1.b < q2.b;
        return q1.i < q2.i;
    });

    int BUCKET_SIZE = sqrt(M);
    if (BUCKET_SIZE == 0) BUCKET_SIZE++;

    for (auto it = queries.begin(); it != queries.end(); ) {
        int FILLED = 0;
        int l = it->a, r = l; // semiopen!!

        while (FILLED < BUCKET_SIZE && r < N) {
            FILLED += aft[r].size();
            r++;
        }

        vector<query> bucket;
        while (it != queries.end() && it->a < r)
            bucket.push_back(*it++);

        int bb = bucket.front().a;
        int ee = bucket.back().a;

        sort(bucket.begin(), bucket.end(), [](const query &q1, const query &q2) {
            return make_pair(q1.b, q1.a) < make_pair(q2.b, q2.a);
        });

        go(bucket, bucket.size(), bb, ee);
    }
}

int main() {
    scanf("%d %d %d", &N, &K, &M);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;

        if (u > v) swap(u, v);
        bef[v].push_back(u);
        aft[u].push_back(v);
    }

    scanf("%d", &Q);
    queries.resize(Q);
    for (int i = 0; i < Q; i++) {
        queries[i].i = i;
        scanf("%d %d", &queries[i].a, &queries[i].b);
        queries[i].a--, queries[i].b--;
    }

    solve();

    for (int i = 0; i < Q; i++) {
        printf("%d\n", ans[i]);
    }
}