#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100*1000+5;

int N, M, x[MaxN], y[MaxN], beats[MaxN];
std::vector<int> e[MaxN], v;
bool seen[MaxN];

void go(int i) {
    seen[i] = true;
    for (int j : e[i]) if (!seen[j]) go(j);
    v.pb(i);
}
bool beat(int i, int j) {
    int k = std::lower_bound(all(e[i]), j) - e[i].begin();
    return k < sz(e[i]) && e[i][k] == j;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d", x+i, y+i); x[i]--; y[i]--;
        e[x[i]].pb(y[i]);
    }
    for (int i = 0; i < N; i++) std::sort(all(e[i]));
    for (int i = 0; i < N; i++) if (!seen[i]) go(i);
    for (int i = 0; i+1 < N; i++) if (!beat(v[i+1], v[i])) {
        printf("-1\n");
        return 0;
    }
    beats[v[0]] = -1;
    for (int i = 0; i+1 < N; i++) beats[v[i+1]] = v[i];
    int count = 0;
    for (int i = 0; i < M; i++) {
        if (beats[x[i]] == y[i]) count++;
        if (count == N-1) {
            printf("%d\n", i+1);
            return 0;
        }
    }
}