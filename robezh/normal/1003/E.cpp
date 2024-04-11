#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
int n, d, k;

int cur = 0;
vector<P> res;

void dfs(int p, int d_lim, int len_lim) {
    if(d_lim <= 0 || len_lim <= 0 || cur == n) return ;

//    res.push_back({v, p});
    for(int i = 0; i < d_lim; i++) {
        if(cur == n) break;
        int nxt = cur++;
        res.push_back({nxt, p});
        dfs(nxt, k - 1, len_lim - 1);
    }
}

int main() {
    cin >> n >> d >> k;
    if(n <= d) return cout << "NO" << endl, 0;
    if(k == 1) {
        if(n != 2) return cout << "NO" << endl, 0;
        else return cout << "YES\n1 2\n", 0;
    }

    for(int i = 0; i < d; i++) res.push_back({i, i + 1});
    cur = d + 1;
    for(int i = 0; i <= d; i++) dfs(i, k - 2, min(i, d - i));

    if(cur != n) return cout << "NO" << endl, 0;
    cout << "YES" << endl, 0;
    for(const auto &p : res) cout << p.first + 1 << " " << p.second + 1 << endl;



}