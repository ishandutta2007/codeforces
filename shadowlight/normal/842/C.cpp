#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1 << 18;
const int MAXN2 = 2e5 + 7;
const double EPS = 1e-8;
const int LOGN = 20;

vector <int> root;

void add(int p, int x, int L = 0, int R = MAXN, int v = 1) {
    if (L > p || R <= p) return;
    if (R - L == 1) {
        root[L + MAXN] += x;
        return;
    }
    int M = (L + R) / 2;
    add(p, x, L, M, 2 * v);
    add(p, x, M, R, 2 * v + 1);
    root[v] = max(root[2 * v], root[2 * v + 1]);
}

int findv(int val, int L = 0, int R = MAXN, int v = 1) {
    if (R - L == 1) {
        return L;
    }
    int M = (R + L) / 2;
    if (root[2 * v + 1] >= val) {
        return findv(val, M, R, 2 * v + 1);
    }
    return findv(val, L, M, 2 * v);
}

vector <vector <int> > gr;
vector <int> data;
vector <int> ans;
vector <int> d;
vector <int> used;

const int MX = 7;

int gcd(int a, int b) {
    if (!a) {
        return b;
    }
    return gcd(b % a, a);
}

int now = 0;

void dfs(int v, int p, int nod) {
    nod = gcd(nod, data[v]);
    for (int i = 0; i < (int) d.size(); i++) {
        if (data[v] % d[i]) {
            used[i]++;
        }
    }
    for (int i = d.size() - 1; i >= 0; i--) {
        if (used[i] <= 1) {
            ans[v] = max(nod, d[i]);
            break;
        }
    }
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs(u, v, nod);
    }
    for (int i = 0; i < (int) d.size(); i++) {
        if (data[v] % d[i]) {
            used[i]--;
        }
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    data.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    gr.resize(n);
    root.resize(2 * MAXN, 0);
    for (int i = 1; i < n; i++){
        int l, r;
        cin >> l >> r;
        l--, r--;
        gr[l].push_back(r);
        gr[r].push_back(l);
    }
    int x = data[0];
    for (int i = 1; i < sqrt(x); i++) {
        if (x % i == 0) {
            d.push_back(i);
            d.push_back(x / i);
        }
    }
    int k = sqrt(x);
    if (k * k == x) {
        d.push_back(k);
    }
    sort(d.begin(), d.end());
    used.resize(d.size(), 0);
    ans.resize(n);
    ans[0] = data[0];
    for (int u : gr[0]) {
        dfs(u, 0, 0);
    }
    for (int x : ans) {
        cout << x << " ";
    }
}