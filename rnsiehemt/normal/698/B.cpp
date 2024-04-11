#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 200*1000+5;

int n, a[maxn], p[maxn];
bool seen[maxn], done[maxn];

int find(int i) {
    if (i == p[i]) return i;
    else return p[i] = find(p[i]);
}

void join(int i, int j) {
    p[find(i)] = find(j);
}

void go(int i) {
    seen[i] = true;
    if (done[a[i]]) {
        join(i, a[i]);
    } else if (seen[a[i]]) {
    } else {
        go(a[i]);
        join(i, a[i]);
    }
    done[i] = true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        a[i]--;
    }
    for (int i = 0; i < n; i++) if (!done[i]) go(i);
    int self = -1;
    std::vector<int> v;
    for (int i = 0; i < n; i++) {
        if (find(i) == i) {
            v.pb(i);
            if (a[i] == i) self = i;
        }
    }
    int ans;
    if (self == -1) {
        ans = sz(v);
        for (int i : v) a[i] = v[0];
    } else {
        ans = sz(v)-1;
        for (int i : v) a[i] = self;
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) printf("%d%c", a[i]+1, " \n"[i == n-1]);
}