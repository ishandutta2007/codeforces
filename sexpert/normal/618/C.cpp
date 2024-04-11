#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;

ll area(pt A, pt B, pt C) {
    pt X = {A.first - B.first, A.second - B.second}, Y = {A.first - C.first, A.second - C.second};
    return abs(X.first * Y.second - X.second * Y.first);
}

ll dis(pt A, pt B) {
    ll dx = A.first - B.first, dy = A.second - B.second;
    return dx*dx + dy*dy;
}

const ll INF = LLONG_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pt> V;
    for(int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        V.push_back({u, v});
    }
    int fi, snd;
    ll mD = INF;
    for(int i = 1; i < n; i++) {
        ll D = dis(V[0], V[i]);
        if(D < mD) {
            mD = D;
            fi = i;
        }
    }
    ll mA = INF;
    for(int i = 1; i < n; i++) {
        ll A = area(V[0], V[fi], V[i]);
        if(A != 0 && A < mA) {
            mA = A;
            snd = i;
        }
    }
    cout << 1 << " " << fi + 1 << " " << snd + 1 << '\n';
}