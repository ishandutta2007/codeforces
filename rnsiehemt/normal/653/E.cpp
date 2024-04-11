#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 300*1000+5;

void rip() {
    printf("impossible\n");
    exit(0);
}

int N, M, K, groups, entries;
std::vector<int> f[MaxN];
bool seen[MaxN], entry;
std::set<int> s;

bool can(int i, int j) {
    auto k = std::lower_bound(all(f[i]), j);
    return k == f[i].end() || *k != j;
}
void go() {
    groups++;
    entry = false;
    std::queue<int> q;
    q.push(*s.begin());
    s.erase(s.begin());
    while (!q.empty()) {
        int i = q.front(); q.pop();
        seen[i] = true;
        if (can(0, i)) {
            entry = true;
            entries++;
        }
        for (auto j = s.begin(); j != s.end(); ) {
            if (can(i, *j)) {
                q.push(*j);
                j = s.erase(j);
            } else j++;
        }
    }
    if (!entry) rip();
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        f[a].pb(b); f[b].pb(a);
    }
    for (int i = 0; i < N; i++) std::sort(all(f[i]));
    for (int i = 1; i < N; i++) s.insert(i);
    while (!s.empty()) {
        go();
    }
    //printf("%d %d\n", groups, entries);
    if (groups > K || entries < K) rip();
    printf("possible\n");
}