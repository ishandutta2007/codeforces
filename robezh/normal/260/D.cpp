#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;
typedef pair<int, int> P;

struct edge {
    int u, v, cost;
};

int n;
int c[N], s[N];
vector<int> L, R;
vector<edge> res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c[i] >> s[i];
        (c[i] ? L : R).push_back(i);
    }
    int l = 0, r = 0;
    while(l < L.size() - 1 || r < R.size() - 1) {
        int sub = min(s[L[l]], s[R[r]]);
        res.push_back({L[l], R[r], sub});
        s[L[l]] -= sub, s[R[r]] -= sub;
        if(s[L[l]] == 0 && l < L.size() -1 ) l++;
        else if(s[R[r]] == 0 && r < R.size() - 1) r++;
    }
    res.push_back({L[l], R[r], s[L[l]]});
    for(const auto &e : res) cout << e.u + 1 << " " << e.v + 1 << " " << e.cost << endl;

}