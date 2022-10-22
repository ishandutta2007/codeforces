#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <int> p, r, lft, rght;

int get(int v) {
    if (p[v] == -1 || p[v] == v) {
        return p[v];
    }
    return p[v] = get(p[v]);
}

void unite(int v, int u) {
    if (p[v] == -1 || p[u] == -1) return;
    v = get(v);
    u = get(u);
    if (v == u) return;
    if (r[v] == r[u]) r[u]++;
    if (r[v] > r[u]) {
        swap(v, u);
    }
    p[v] = u;
    lft[u] = min(lft[u], lft[v]);
    rght[u] = max(rght[u], rght[v]);
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, m, ps;
    cin >> n >> m >> ps;
    string s;
    cin >> s;
    vector <int> pos(n + 2);
    vector <int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push_back(i);
        } else {
            pos[i + 1] = st.back() + 1;
            pos[st.back() + 1] = i + 1;
            st.pop_back();
        }
    }
    lft.resize(n + 2);
    rght.resize(n + 2);
    p.resize(n + 2, -1);
    r.resize(n + 2, 0);
    for (int i = 0; i < n + 2; i++) {
        lft[i] = i;
        rght[i] = i;
    }
    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        if (c == 'L') {
            if (get(ps - 1) == -1) {
                ps--;
            } else {
                //cout << get(ps - 1) << " " << lft[get(ps - 1)] << "\n";
                ps = lft[get(ps - 1)];
            }
        } else if (c == 'R') {
            if (get(ps + 1) == -1) {
                ps++;
            } else {
                ps = rght[get(ps + 1)];
            }
        } else {
            int now = ps;
            if (pos[ps] < ps) {
                while (now >= pos[ps]) {
                    p[now] = now;
                    lft[now] = (get(now - 1) == -1 ? now - 1 : lft[get(now - 1)]);
                    rght[now] = (get(now + 1) == -1 ? now + 1 : rght[get(now + 1)]);
                    unite(now, now - 1);
                    unite(now, now + 1);
                    now = lft[get(now)];
                }
            } else {
                while (now <= pos[ps]) {
                    p[now] = now;
                    lft[now] = (get(now - 1) == -1 ? now - 1 : lft[get(now - 1)]);
                    rght[now] = (get(now + 1) == -1 ? now + 1 : rght[get(now + 1)]);
                    unite(now, now - 1);
                    unite(now, now + 1);
                    now = rght[get(now)];
                }
            }
            if (rght[get(ps)] == n + 1) {
                ps = lft[get(ps)];
            } else {
                ps = rght[get(ps)];
            }
        }
        //cout << ps << "\n";
    }
    string t = "";
    for (int i = 1; i <= n; i++) {
        if (get(i) == -1) {
            t += s[i - 1];
        }
    }
    cout << t;
}