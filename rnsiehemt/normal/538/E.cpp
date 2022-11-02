#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))

const int inf = 1000*1000*1000+1;
const int Max = 0, Min = 1;

int N, M;
std::vector<int> e[200005];
int p[200005];
int type[200005];
int sz[200005]; // # leaves in subtree

void root(int at, int from, int t) {
    //printf("%d %d %d\n", at, from, t);
    p[at] = from; type[at] = t;
    if (sz(e[at]) == 0 || (sz(e[at]) == 1 && e[at][0] == from)) { sz[at] = 1; M++; }
    for (int i = 0; i < sz(e[at]); i++)
        if (e[at][i] != from) { root(e[at][i], at, 1-t); sz[at] += sz[e[at][i]]; }
}

int f(int at) {
    if (sz(e[at]) == 0 || (sz(e[at]) == 1 && e[at][0] == p[at])) return 1;
    else if (type[at] == Max) {
        int ans = inf;
        for (int i = 0; i < sz(e[at]); i++) if (e[at][i] != p[at]) ans = std::min(ans, f(e[at][i]));
        return ans;
    }
    else { assert(type[at] == Min);
        int ans = 0; 
        for (int i = 0; i < sz(e[at]); i++) if (e[at][i] != p[at]) ans += f(e[at][i]);
        return ans;
    }
}

int g(int at) {
    if (sz(e[at]) == 0 || (sz(e[at]) == 1 && e[at][0] == p[at])) return 1;
    else if (type[at] == Min) {
        int ans = inf;
        for (int i = 0; i < sz(e[at]); i++) if (e[at][i] != p[at]) ans = std::min(ans, g(e[at][i]));
        return ans;
    }
    else { 
        int ans = 0; 
        for (int i = 0; i < sz(e[at]); i++) if (e[at][i] != p[at]) ans += g(e[at][i]);
        return ans;
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N-1; i++) {
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        e[a].push_back(b); e[b].push_back(a);
    }
    root(0, -1, Max);

    { // max
        /*int lo = 1, hi = M+1;
        while (hi-lo > 1) {
            int mid = (lo+hi)/2;
            if (f(0, mid, 1) > (M-mid+1)) hi = mid;
            else lo = mid;
        }
        printf("%d ", lo);*/
        printf("%d ", M-f(0)+1);
    }
    { // min
        printf("%d\n", g(0));
    }
}