// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = (int) 1e5 + 5, mod = 0;
vector<int> adj[N];
int sz[N];
double res[N];
void init(int v) {
    sz[v] = 1;
    for (int u : adj[v])
        init(u), sz[v] += sz[u];
}

void get_res(int v, double cur = 1) {
    res[v] = cur;
    int sum = 0;
    for (int u : adj[v])
        sum += sz[u];
    for (int u : adj[v])
        get_res(u, cur + ((double) sum - sz[u]) / 2 + 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p; --p;
        adj[p].push_back(i);
    }
    init(0);
    get_res(0);
    for (int i = 0; i < n; ++i)
        cout << setprecision(8) << fixed << res[i] << ' ';

}