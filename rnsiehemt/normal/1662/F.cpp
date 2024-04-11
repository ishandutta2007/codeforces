#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e8;

template<class Comp>
struct RT {
    int SZ;
    Comp comp;
    int DEFAULT;
    vector<int> v;
    vector<int> tree;

    RT(Comp comp, int N, int DEFAULT) : comp(comp), DEFAULT(DEFAULT) {
        SZ = 1;
        while (SZ < N) {
            SZ *= 2;
        }
        v = vector<int>(SZ, DEFAULT);
        tree = vector<int>(2 * SZ);
        iota(tree.begin() + SZ, tree.begin() + 2*SZ, 0);
        for (int i = SZ - 1; i >= 1; i--) {
            tree[i] = tree[2*i];
        }
    }

    int query(int ql, int qr, int n = 1, int nl = 0, int nr = -1) {
        if (nr == -1) {
            nr = SZ;
        }

        if (ql <= nl && nr <= qr) {
            return tree[n];
        } else {
            int m = (nl + nr) / 2;
            int res = -1;
            if (ql < m) {
                int lres = query(ql, qr, n*2, nl, m);
                res = (res == -1 || comp(v[lres], v[res])) ? lres : res;
            }
            if (m < qr) {
                int rres = query(ql, qr, n*2+1, m, nr);
                res = (res == -1 || comp(v[rres], v[res])) ? rres : res;
            }
            return res;
        }
    }

    void set(int qi, int qv) {
        v[qi] = qv;
        int n = SZ + qi;
        n /= 2;
        while (n >= 1) {
            tree[n] = comp(v[tree[n*2]], v[tree[n*2+1]]) ? tree[n*2] : tree[n*2+1];
            n /= 2;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, A, B;
        cin >> N >> A >> B;
        A--;
        B--;
        vector<int> P(N);
        for (int &p : P) {
            cin >> p;
        }

        RT min_rt([](int a, int b) {
            return a < b;
        }, N, INF);
        RT max_rt([](int a, int b) {
            return a > b;
        }, N, -INF);
        for (int i = 0; i < N; i++) {
            min_rt.set(i, i - P[i]);
            max_rt.set(i, i + P[i]);
        }

        vector<int> D(N, INF);
        queue<int> q;
        D[A] = 0;
        q.push(A);
        min_rt.set(A, INF);
        max_rt.set(A, -INF);
        while (!q.empty()) {
            int i = q.front();
            q.pop();

            //cout << "bfs at " << i << " dist " << D[i] << endl;
            
            while (true) {
                int j = min_rt.query(i, i+P[i]+1);
                if (min_rt.v[j] > i) {
                    break;
                }
                D[j] = D[i] + 1;
                q.push(j);
                min_rt.set(j, INF);
                max_rt.set(j, -INF);
            }
            while (true) {
                int j = max_rt.query(i-P[i], i+1);
                if (max_rt.v[j] < i) {
                    break;
                }
                D[j] = D[i] + 1;
                q.push(j);
                min_rt.set(j, INF);
                max_rt.set(j, -INF);
            }

            if (D[B] < INF) {
                break;
            }
        }

        cout << D[B] << "\n";
    }
}