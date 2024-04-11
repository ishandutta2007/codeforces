#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 300001;
char s[N];
int a[N], p[N], r[N], h, tt[N], cc[N][2], ph[N];
vector<int> li[N], g[N];

int getp(int v) {
    h = 0;
    while (p[v] != v) {
        h ^= ph[v];
        v = p[v];
    }
    return v;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k, c, v, mc = 0, u, hu;
    cin >> n >> k >> s;
    rep(i, n)
        a[i] = s[i] - '0';
    rep(i, k) {
        p[i] = i;
        tt[i] = -1;
        cc[i][0] = 1;
        cin >> c;
        rep(j, c) {
            cin >> v;
            li[v - 1].push_back(i);
        }
    }
    rep(i, n) {
        if (li[i].size() == 1) {
            u = getp(li[i][0]);
            if (tt[u] == -1) {
                mc -= min(cc[u][0], cc[u][1]);
                h ^= a[i];
                tt[u] = h;
                mc += cc[u][h];
            }
        }
        else if (li[i].size() == 2) {
            u = getp(li[i][0]);
            hu = h;
            v = getp(li[i][1]);
            h ^= hu ^ a[i] ^ 1;
            if (u != v) {
                if (r[u] < r[v])
                    swap(u, v);
                if (tt[u] == -1)
                    mc -= min(cc[u][0], cc[u][1]);
                else
                    mc -= cc[u][tt[u]];
                if (tt[v] == -1)
                    mc -= min(cc[v][0], cc[v][1]);
                else {
                    tt[u] = tt[v] ^ h;
                    mc -= cc[v][tt[v]];
                }
                ph[v] = h;            
                p[v] = u;
                if (r[u] == r[v])
                    r[u]++;
                cc[u][0] += cc[v][h];
                cc[u][1] += cc[v][h ^ 1];
                if (tt[u] == -1)
                    mc += min(cc[u][0], cc[u][1]);
                else
                    mc += cc[u][tt[u]];
            }
        }
        cout << mc << '\n';
    }
}