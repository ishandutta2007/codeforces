#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> Pi;
const int N = (int)1e6 + 50;

int u[N];
int n, m;
P p[N];
vector<vector<int> > tab;
int res[N];
int mx_row[N], mx_col[N];
map<int, P> las;

int find(int x) {
    return u[x] == x ? x : u[x] = find(u[x]);
}

void unite(int x, int y) {
    u[find(x)] = find(y);
}

int id(int i, int j) {
    return i * m + j;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n * m; i++) u[i] = i;
    tab.resize(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        cin >> tab[i][j];
        int idx = id(i, j);
        p[idx].first = tab[i][j];
        p[idx].second = idx;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            auto it = las.find(tab[i][j]);
            if(it != las.end() && it->second.first == i)
                unite(id(i, j), id(it->second.first, it->second.second));
            las[tab[i][j]] = {i, j};
        }
    }
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            auto it = las.find(tab[i][j]);
            if(it != las.end() && it->second.second == j)
                unite(id(i, j), id(it->second.first, it->second.second));
            las[tab[i][j]] = {i, j};
        }
    }
    sort(p, p + n * m, [](const P &p1, const P &p2){
        return p1.first != p2.first ? p1.first < p2.first :
                find(p1.second) < find(p2.second);
    });
    int r = 0;
//    for(int i = 0; i < n * m; i++) cout << p[i].first << " ";
//    cout << endl;
    for(int i = 0; i < n * m;) {
        int mn = 0;
        while(r < n * m && find(p[r].second) == find(p[i].second)) {
            mn = max(mn, max(mx_col[p[r].second % m], mx_row[p[r].second / m]));
            r++;
        }
        mn = mn + 1;
        for(int j = i; j < r; j++) {
            res[p[j].second] = mn;
            mx_row[p[j].second / m] = mx_col[p[j].second % m] = mn;
        }
        i = r;
    }
    for(int i = 0; i < n * m; i++) {
        cout << res[i] << " ";
        if((i + 1) % m == 0) cout << "\n";
    }


}