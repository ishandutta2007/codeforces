#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef pair<P, int> Pi;
const int N = 55;

int n,m;
int x[N], y[N];
int mp[N][N];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
vector<Pi> cubs;
vector<pair<P, P>> res[2];

void push(int id, int d, int t) {
    int nx = x[id] + dx[d], ny = y[id] + dy[d];
    if(mp[nx][ny] != -1) {
        push(mp[nx][ny], d, t);
    }
    res[t].push_back({{x[id], y[id]}, {nx, ny}});
    mp[nx][ny] = id;
    mp[x[id]][y[id]] = -1;
    x[id] = nx, y[id] = ny;
}

void solve(int t) {
    memset(mp, -1, sizeof(mp));
    for(int i = 1; i <= m; i++) cin >> x[i] >> y[i], mp[x[i]][y[i]] = i;
    cubs.clear();
    for(int i = 1; i <= m; i++) cubs.push_back({{x[i], y[i]}, i});
    sort(cubs.begin(), cubs.end());
    for(int k = 0; k < m; k++) {
        int id = cubs[k].second;
        while(x[id] != k + 1) {
            int d = x[id] > k + 1 ? 1 : 0;
            push(id, d, t);
        }
    }
    for(int k = 1; k <= m; k++) {
        while(y[k] != k) {
            int d = (y[k] > k ? 2 : 3);
            push(k, d, t);
        }
    }
    for(int k = 1; k <= m; k++) {
        while(x[k] != k) {
            int d = (x[k] > k ? 1 : 0);
            push(k, d, t);
        }
    }
}

int main() {
    cin >> n >> m;
    solve(0);
    solve(1);
    cout << res[0].size() + res[1].size() << endl;
    for(auto p : res[0]) {
        cout << p.first.first << " " << p.first.second << " ";
        cout << p.second.first << " " << p.second.second << "\n";
    }
    reverse(res[1].begin(), res[1].end());
    for(auto p : res[1]) {
        cout << p.second.first << " " << p.second.second << " ";
        cout << p.first.first << " " << p.first.second << "\n";
    }
}