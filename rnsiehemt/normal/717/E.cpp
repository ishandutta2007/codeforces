#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 200*1000+5;

int n, c[maxn];
std::vector<int> e[maxn], v;

void f(int i) {
    c[i] = -c[i];
}

void go(int i, int p) {
    v.pb(i);
    for (int j : e[i]) if (j != p) {
        f(j);
        go(j, i);
        v.pb(i);
        f(i);
    }
    if (c[i] == -1) {
        if (i) {
            f(p);
            v.pb(p);
            v.pb(i);
        } else {
            v.pb(e[i][0]);
            v.pb(0);
            v.pb(e[i][0]);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", c+i);
    for (int i = 0; i < n-1; i++) {
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        e[a].pb(b); e[b].pb(a);
    }
    go(0, -1);
    for (int i = 0; i < sz(v); i++) printf("%d%c", v[i]+1, " \n"[i == sz(v)-1]);
}