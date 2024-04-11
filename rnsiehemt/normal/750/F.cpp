#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 10000;

std::vector<int> adj[maxn];

std::vector<int> query(int i) {
    printf("? %d\n", i+1);
    fflush(stdout);
    int k;
    std::vector<int> v;
    scanf("%d", &k);
    if (!k) exit(0);
    for (int j = 0; j < k; j++) {
        int a;
        scanf("%d", &a);
        a--;
        v.pb(a);
    }
    adj[i] = v;
    return v;
}

void answer(int i) {
    printf("! %d\n", i+1);
    fflush(stdout);
}

void go(int at, int from, std::vector<int> &v) {
    query(at);
    v.push_back(at);
    if (sz(adj[at]) <= 2) return;
    int k = 0;
    if (adj[at][k] == from) k = 1;
    go(adj[at][k], at, v);
}

bool search1(int at, int from, bool first) {
    query(at);
    if (sz(adj[at]) == 2) {
        answer(at);
        return true;
    }
    int a = 0;
    if (adj[at][a] == from) a++;
    int b = 0;
    while (b == a || adj[at][b] == from) b++;
    a = adj[at][a];
    b = adj[at][b];
    if (first) {
        query(a);
        if (sz(adj[a]) == 2) {
            answer(a);
            return true;
        }
        query(b);
        if (sz(adj[b]) == 2) {
            answer(b);
            return true;
        }
        return false;
    } else {
        query(a);
        if (sz(adj[a]) == 2) {
            answer(a);
            return true;
        }
        answer(b);
        return true;
    }
}

void solve(int at, int from, int height, std::vector<int> v) {
    query(at);
    if (sz(adj[at]) == 2) {
        answer(at);
        return;
    }
    if (height <= 3) {
        v.push_back(at);
        int k = 0;
        if (adj[at][k] == from) k = 1;
        go(adj[at][k], at, v);
        if (sz(adj[v.back()]) == 2) {
            answer(v.back());
            return;
        }

        int foo = sz(v) / 2;
        int a = v[foo-1], b = v[foo], c = v[foo+1];
        for (int k = 0; k < 3; k++) {
            if (adj[b][k] != a && adj[b][k] != c) {
                while (sz(v) > foo+1) v.pop_back();
                solve(adj[b][k], b, foo+1, v);
                break;
            }
        }
    } else if (height == 5) {
        int a = 0;
        if (adj[at][a] == from) a++;
        int b = 0;
        while (b == a || adj[at][b] == from) b++;
        a = adj[at][a];
        b = adj[at][b];
        query(a);
        if (sz(adj[a]) == 2) {
            answer(a);
            return;
        } else {
            answer(b);
            return;
        }
    } else {
        int a = 0;
        if (adj[at][a] == from) a++;
        int b = 0;
        while (b == a || adj[at][b] == from) b++;

        if (search1(adj[at][a], at, true)) {
            return;
        }
        search1(adj[at][b], at, false);
    }
}

int t, h;

int main() {
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &h);
        if (!h) exit(0);
        query(0);
        if (sz(adj[0]) == 2) {
            answer(0);
        } else if (sz(adj[0]) == 1) {
            std::vector<int> v;
            v.push_back(0);
            solve(adj[0][0], 0, 1, v);
        } else {
            std::vector<int> v;
            v.pb(0);
            go(adj[0][0], 0, v);
            if (sz(adj[v.back()]) == 2) {
                answer(v.back());
            } else {
                std::reverse(v.begin(), v.end());
                go(adj[0][1], 0, v);
                if (sz(adj[v.back()]) == 2) {
                    answer(v.back());
                } else {
                    int foo = sz(v) / 2;
                    int a = v[foo-1], b = v[foo], c = v[foo+1];
                    for (int k = 0; k < 3; k++) {
                        if (adj[b][k] != a && adj[b][k] != c) {
                            while (sz(v) > foo+1) v.pop_back();
                            solve(adj[b][k], b, foo+1, v);
                            break;
                        }
                    }
                }
            }
        }
    }
}