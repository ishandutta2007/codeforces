#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)1e5 + 50;
//typedef pair<int, int> P;

struct P {
    int u, v;
    ll cost;
};

int n, m;
ll in[N], out[N];
vector<int> pos, neg;
vector<P> res;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        in[a] += c;
        in[b] -= c;
    }
    for(int i = 0; i < n; i++) {
        if(in[i] > 0) pos.push_back(i);
        if(in[i] < 0) neg.push_back(i);
    }
    for(int id : pos) {
        while(in[id] > 0) {
            int bk = neg.back();
            ll tk = min(-in[bk], in[id]);
            in[id] -= tk;
            in[bk] += tk;
            res.push_back({id, bk, tk});
            if(in[bk] == 0) neg.pop_back();
        }
    }
    cout << res.size() << endl;
    for(auto p : res) cout << p.u + 1 << " " << p.v + 1 << " " << p.cost << '\n';
}