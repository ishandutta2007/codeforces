#include <bits/stdc++.h>

int N, Q;
std::vector<int> e[100005];
int e1[100005];
int e2[100005];
int el[100005];
int sizetmp[100005];
int size[100005];
double ans;

int dfs(int a, int p) {
    sizetmp[a] = 1;
    for (int i = 0; i < (int)e[a].size(); i++)
        if (e[a][i] != p)
            sizetmp[a] += dfs(e[a][i], a);
    return sizetmp[a];
}

double f(int i) {
    double d = double(i);
    return d*(d-1)*(d-2)/6.0;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N-1; i++) {
        int a, b, l; scanf("%d%d%d", &a, &b, &l); a--; b--;
        e1[i] = a; e2[i] = b; el[i] = l;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    
    dfs(0, -1);
    for (int i = 0; i < N-1; i++) {
        size[i] = std::min(sizetmp[e1[i]], sizetmp[e2[i]]);
        ans += 2.0 * (f(N)-f(size[i])-f(N-size[i]))/f(N) * double(el[i]);
    }

    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int r, w; scanf("%d%d", &r, &w); r--;
        ans += 2.0 * (f(N)-f(size[r])-f(N-size[r]))/f(N) * double(w-el[r]);
        el[r] = w;
        printf("%lf\n", ans);
    }
}