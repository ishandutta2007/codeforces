#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <int> leafs;
vector <vector <int> > gr;
vector <int> cnt;

void dfs(int v) {
    leafs[v] = 0;
    for (int u : gr[v]) {
        dfs(u);
        leafs[v] += leafs[u];
    }
    if (!gr[v].size()) {
        leafs[v] = 1;
    }
    cnt[leafs[v]]++;
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
    int n;
    cin >> n;
    gr.resize(n);
    leafs.resize(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        gr[p].push_back(i);
    }
    cnt.resize(n + 1, 0);
    dfs(0);
    int id = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        while (sum < i) {
            id++;
            sum += cnt[id];
        }
        cout << id << " ";
    }
}