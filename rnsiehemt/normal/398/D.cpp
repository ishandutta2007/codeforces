#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 50*1000+5, bsize = 500;

int n, m, q, o, light[maxn], on[maxn];
std::vector<int> e[maxn], heavy[maxn];
std::map<int, int> eidx[maxn];

void inc(int a) {
    if (sz(e[a]) == bsize) {
        for (const int &b : e[a]) if (b >= 0) {
            light[b] -= on[a];
            heavy[b].push_back(a);
        }
    }
}

void addEdge(int a, int b) {
    if (eidx[a].find(-b - 1) != eidx[a].end()) {
        e[a][eidx[a][b]] = b;
        e[b][eidx[b][a]] = a;

        // deal with light/heavy stuff
        if (sz(e[b]) <= bsize) light[a] -= on[b];
        else {
            //heavy[a].erase(b);
            for (int &c : heavy[a]) {
                if (c == -b - 1) {
                    c = b;
                    break;
                }
            }
        }
        if (sz(e[a]) <= bsize) light[b] -= on[a];
        else {
            //heavy[b].erase(a);
            for (int &c : heavy[b]) {
                if (c == -a - 1) {
                    c = a;
                    break;
                }
            }
        }
    } else {
        inc(a);
        inc(b);
        eidx[a][b] = sz(e[a]);
        eidx[b][a] = sz(e[b]);
        e[a].pb(b);
        e[b].pb(a);
        if (sz(e[b]) <= bsize) light[a] += on[b];
        else heavy[a].pb(b);
        if (sz(e[a]) <= bsize) light[b] += on[a];
        else heavy[b].pb(a);
    }
}

void removeEdge(int a, int b) {
    if (sz(e[b]) <= bsize) light[a] -= on[b];
    else {
        //heavy[a].erase(b);
        for (int &c : heavy[a]) {
            if (c == b) {
                c = -c - 1;
                break;
            }
        }
    }
    if (sz(e[a]) <= bsize) light[b] -= on[a];
    else {
        //heavy[b].erase(a);
        for (int &c : heavy[b]) {
            if (c == a) {
                c = -c - 1;
                break;
            }
        }
    }
    //e[a].erase(b);
    //e[b].erase(a);
    e[a][eidx[a][b]] = -b - 1;
    e[b][eidx[b][a]] = -a - 1;
}

void turnon(int a) {
    on[a] = 1;
    if (sz(e[a]) <= bsize) {
        for (const int &b : e[a]) if (b >= 0) {
            light[b]++;
        }
    }
}

void turnoff(int a) {
    on[a] = 0;
    if (sz(e[a]) <= bsize) {
        for (const int &b : e[a]) if (b >= 0) {
            light[b]--;
        }
    }
}

int count(int a) {
    int c = light[a];
    for (const int &b : heavy[a]) if (b >= 0) {
        c += on[b];
    }
    return c;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    scanf("%d", &o);
    for (int i = 0; i < o; i++) {
        int x; scanf("%d", &x); x--;
        turnon(x);
    }
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        addEdge(a, b);
    }
    for (int i = 0; i < q; i++) {
        char cmd; scanf(" %c", &cmd);
        if (cmd == 'O') {
            int u; scanf("%d", &u); u--;
            turnon(u);
        } else if (cmd == 'F') {
            int u; scanf("%d", &u); u--;
            turnoff(u);
        } else if (cmd == 'A') {
            int u, v; scanf("%d%d", &u, &v); u--; v--;
            addEdge(u, v);
        } else if (cmd == 'D') {
            int u, v; scanf("%d%d", &u, &v); u--; v--;
            removeEdge(u, v);
        } else {
            int u; scanf("%d", &u); u--;
            printf("%d\n", count(u));
        }
    }
}