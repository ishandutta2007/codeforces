#include <bits/stdc++.h>

struct E {
    int a, b;
    E(int aa, int bb) : a(aa), b(bb) { }
};

int N, M;
std::vector<E> e[100005];
int p[100005];
std::vector<int> w[100005];
bool seen[100005];
int Q;
int qa[100005];
int qb[100005];
std::vector<int> q[100005];
std::vector<int> ans[100005];

int find(int a) {
    if (p[a] == a) return a;
    else return p[a] = find(p[a]);
}

void join(int a, int b) {
    p[find(a)] = find(b);
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c); a--; b--; c--;
        e[c].push_back(E(a, b));
    }

    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d%d", &qa[i], &qb[i]); qa[i]--; qb[i]--;
        q[qa[i]].push_back(qb[i]);
        //q[qb[i]].push_back(qa[i]);
    }

    for (int i = 0; i < N; i++) {
        std::sort(q[i].begin(), q[i].end());
        std::vector<int> v;
        if (!q[i].empty()) v.push_back(q[i][0]);
        for (int k = 1; k < (int)q[i].size(); k++)
            if (q[i][k] != q[i][k-1])
                v.push_back(q[i][k]);
        q[i].clear();
        for (int j = 0; j < (int)v.size(); j++) {
            q[i].push_back(v[j]);
            ans[i].push_back(0);
        }
    }

    for (int c = 0; c < M; c++) {
        for (int i = 0; i < N; i++)
            p[i] = i;
        int K = (int)e[c].size();
        for (int i = 0; i < K; i++)
            join(e[c][i].a, e[c][i].b);

        if (K < 100) {
            std::vector<int> v;
            for (int i = 0; i < K; i++) {
                if (!seen[e[c][i].a]) {
                    seen[e[c][i].a] = true;
                    w[find(e[c][i].a)].push_back(e[c][i].a);
                }
                if (p[e[c][i].b] == e[c][i].b)
                    v.push_back(e[c][i].b);
                if (!seen[e[c][i].b]) {
                    seen[e[c][i].b] = true;
                    w[find(e[c][i].b)].push_back(e[c][i].b);
                }
            }

            std::sort(v.begin(), v.end());
            for (int i = 0; i < (int)v.size(); i++) {
                if (i > 0 && v[i] == v[i-1]) continue;
                for (int j = 0; j < (int)w[v[i]].size(); j++) {
                    for (int k = j+1; k < (int)w[v[i]].size(); k++) {
                        int a = w[v[i]][j];
                        int b = w[v[i]][k];
                        int l = std::lower_bound(q[a].begin(), q[a].end(), b) - q[a].begin();
                        if (l != (int)q[a].size() && q[a][l] == b) ans[a][l]++;
                        l = std::lower_bound(q[b].begin(), q[b].end(), a) - q[b].begin();
                        if (l != (int)q[b].size() && q[b][l] == a) ans[b][l]++;
                    }
                }
            }

            for (int i = 0; i < K; i++) {
                seen[e[c][i].a] = seen[e[c][i].b] = false;
                w[e[c][i].a].clear();
                w[e[c][i].b].clear();
            }
        }
        else {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < (int)ans[i].size(); j++) {
                    if (find(i) == find(q[i][j]))
                        ans[i][j]++;
                }
            }
        }
    }
    
    for (int i = 0; i < Q; i++) {
        int l = std::lower_bound(q[qa[i]].begin(), q[qa[i]].end(), qb[i]) - q[qa[i]].begin();
        printf("%d\n", ans[qa[i]][l]);
    }
}