#include <bits/stdc++.h>

using namespace std;
constexpr int FMAX = 28;

vector<vector<pair<int, int>>> tree;
vector<pair<int, int>> elist;
vector<bool> alive;

int FIBONACCI[FMAX];
map<int, int> placeInFib;

vector<int> subtreeSize, parentHere, etp;
void populateSTS(int v, int p, vector<int> &vis) {
    subtreeSize[v] = 1;
    parentHere[v] = p;
    vis.push_back(v);
    for (auto [x, eid] : tree[v]) {
        if (!alive[eid] || x == p) continue;
        populateSTS(x, v, vis);
        etp[x] = eid;
        subtreeSize[v] += subtreeSize[x];
    }
}

bool checkComponentFib(int v, int p, int layer) {
    if (layer < 2) return true;
    vector<int> inHere;
    populateSTS(v, p, inHere);
    int m1head = -1, m2head = -1;
    for (int x : inHere) {
        if (subtreeSize[x] == FIBONACCI[layer-1]) {
            m1head = x; m2head = parentHere[x];
            alive[etp[x]] = false;
            break;
        }
        if (subtreeSize[x] == FIBONACCI[layer-2]) {
            m1head = parentHere[x]; m2head = x;
            alive[etp[x]] = false;
            break;
        }
    }
    if (m1head == -1) return false;
    return checkComponentFib(m1head, m2head, layer-1)
        && checkComponentFib(m2head, m1head, layer-2);
}

int main() {
    FIBONACCI[0] = FIBONACCI[1] = 1;
    for (int i = 2; i < FMAX; ++i) FIBONACCI[i] = FIBONACCI[i-1] + FIBONACCI[i-2];
    for (int i = 0; i < FMAX; ++i) placeInFib[FIBONACCI[i]] = i;

    int n; scanf("%d", &n);
    tree.assign(n, vector<pair<int, int>>());
    alive.assign(n - 1, true);
    subtreeSize.assign(n, -1);
    parentHere.assign(n, -1);
    etp.assign(n, -1);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        --x; --y;
        tree[x].emplace_back(y, i);
        tree[y].emplace_back(x, i);
        elist.emplace_back(x, y);
    }
    // special cases
    if (n <= 3) {
        printf("yes\n");
        return 0;
    } else if (placeInFib.count(n) == 0) {
        printf("no\n");
        return 0;
    }
    printf("%s\n", checkComponentFib(0, -1, placeInFib[n]) ? "YES" : "NO");
    return 0;
}