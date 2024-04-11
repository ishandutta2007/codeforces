#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//typedef pair<int, int> P;

struct P{
    int i, j;
};

struct node {
    int i1, j1, i2, j2;
};

const int N = 2005;
vector<P> snk[26];

int n, m;
string str[N];

int solve() {
    cin >> n >> m;
    for(int i = 0; i < 26; i++) snk[i].clear();
    for(int i = 0; i < n; i++) cin >> str[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) if(str[i][j] != '.') snk[str[i][j] - 'a'].push_back({i, j});
    }
    int not_done = 0;
    vector<node> res;
    for(int c = 0; c < 26; c++) {
        int hor = -1, ver = -1;
        for(P p : snk[c]) {
            if(hor == -1 || hor == p.i) hor = p.i;
            else hor = -2;
            if(ver == -1 || ver == p.j) ver = p.j;
            else ver = -2;
        }
        if(hor == -2 && ver == -2) return cout << "NO\n", 0;
        if(hor == -1 && ver == -1) {
            not_done++;
            continue;
        }
        node cur_res;

        if(hor >= 0) {
            int mxj = -1, mnj = N;
            for(P p : snk[c]) mxj = max(mxj, p.j), mnj = min(mnj, p.j);
            for(int j = mnj; j <= mxj; j++) {
                if(str[hor][j] == '.' || str[hor][j] < (char)(c + 'a')) return cout << "NO\n", 0;
            }
            cur_res = {hor, mnj, hor, mxj};
        }
        else {
            assert(ver >= 0);
            int mxi = -1, mni = N;
            for(P p : snk[c]) mxi = max(mxi, p.i), mni = min(mni, p.i);
            for(int i = mni; i <= mxi; i++) {
                if(str[i][ver] == '.' || str[i][ver] < (char)(c + 'a')) return cout << "NO\n", 0;
            }
            cur_res = {mni, ver, mxi, ver};
        }

//        node nd = cur_res;
//        cout << nd.i1 + 1  << " " << nd.j1 + 1 << " " << nd.i2 + 1 << " " << nd.j2 + 1 << endl;

        for(int i = 0; i < not_done + 1; i++) res.push_back(cur_res);
        not_done = 0;
    }
    cout << "YES\n";
    cout << res.size() << "\n";
    for(node nd: res) cout << nd.i1 + 1 << " " << nd.j1 + 1 << " " << nd.i2 + 1 << " " << nd.j2 + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}