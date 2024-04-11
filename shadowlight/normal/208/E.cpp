#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int up[N][21];
const int l = 20;
int n;
int v_h[N];

vector < vector < int > > gr(N);
vector < vector < int > > high(N);
int in[N];
int out[N];
int c = 0;

void dfs (int v, int p, int h) {
    in[v] = c;
    c++;
    v_h[v] = h;
    high[h].push_back(v);
    up[v][0] = p;
    for (int i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (auto u : gr[v]) {
        if (u != p)
            dfs(u, v, h + 1);
    }
    out[v] = c;
    c++;
    return;
}

int main() {

#ifdef MY
    freopen("input.txt", "r", stdin);
#endif // MY
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int r;
        cin >> r;
        gr[r].push_back(i + 1);
    }
    dfs(0, 0, 0);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int v, p;
        cin >> v >> p;
        int j = 0;
        int x = l;
        while (j < p) {
            while (j + (1 << x) > p) x--;
            v = up[v][x];
            j += (1 << x);
        }
        p += v_h[v];
        if (!v) {
            cout << 0 << " ";
            continue;
        }
        int l = -1, r = high[p].size() - 1;
        int il, ir;
        while (l + 1 != r) {
            int m = (l + r) / 2;
            if (in[high[p][m]] < in[v])
                l = m;
            else
                r = m;
        }
        il = r;
        l = 0, r = high[p].size();
        while (l + 1 != r) {
            int m = (l + r) / 2;
            if (in[high[p][m]] > out[v])
                r = m;
            else
                l = m;
        }
        ir = l;
        //assert(ir - il);
        cout << ir - il << ' ';
    }
    return 0;
}