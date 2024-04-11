#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;
typedef long long ll;

struct query {
    int r, id;
};

int n, q;
int p[N], l[N];
vector<query> qry[N];
ll res[N];

struct BIT {
    ll bit[N];

    void add(int x, ll val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    ll get(int x) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }
} bit;

stack<int> S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i] >> l[i];
    cin >> q;
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b; a--, b--;
        qry[a].push_back({b, i});
    }

    for(int i = n - 1; i >= 0; i--) {
        while(!S.empty() && p[i] + l[i] >= p[S.top()] + l[S.top()]) {
            int v = S.top(); S.pop();
            if(!S.empty() && p[v] + l[v] < p[S.top()]) {
                bit.add(S.top(), -(p[S.top()] - p[v] - l[v]));
            }
        }
        if(!S.empty() && p[i] + l[i] < p[S.top()]) {
            bit.add(S.top(), p[S.top()] - p[i] - l[i]);
        }
        S.push(i);
        for(const auto &qr : qry[i]) {
            res[qr.id] = bit.get(qr.r);
        }
    }
    for(int i = 0; i < q; i++) {
        cout << res[i] << "\n";
    }
}