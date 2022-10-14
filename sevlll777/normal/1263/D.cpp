#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define pii  pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmp unordered_map
#define unst unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 998244353;
map<int, int> parent;
vector<int> sizes(1e6+100);

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    sizes[v] = -1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizes[a] < sizes[b]) swap(a, b);
        parent[b] = a;
        sizes[b] += sizes[a];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<char, set<int>> ind;
    for (int i = 0; i < n; i++) {
        str s; cin >> s;
        for (auto c : s) {
            ind[c].insert(i);
        }
    }
    for (auto p : ind) {
        set<int> S = p.second;
        int par = *S.begin();
        make_set(par);
        for (auto q : S) {
            if (parent.find(q) == parent.end()) {
                parent[q] = par;
            } else {
                union_sets(q, par);
            }
        }
    }
    set<int> heh;
    for (int i = 0; i < n; i++) {
        heh.insert(find_set(i));
    }
    cout << heh.size();
}