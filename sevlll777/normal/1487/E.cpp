#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), x.end()
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    vector<int> A(n1), B(n2), C(n3), D(n4);
    for (int i = 0; i < n1; i++) cin >> A[i];
    for (int i = 0; i < n2; i++) cin >> B[i];
    for (int i = 0; i < n3; i++) cin >> C[i];
    for (int i = 0; i < n4; i++) cin >> D[i];
    int m1, m2, m3;
    vector<pair<int, int>> AB, BC, CD;
    cin >> m1;
    AB.resize(m1);
    for (int i = 0; i < m1; i++) cin >> AB[i].first >> AB[i].second;
    cin >> m2;
    BC.resize(m2);
    for (int i = 0; i < m2; i++) cin >> BC[i].first >> BC[i].second;
    cin >> m3;
    CD.resize(m3);
    for (int i = 0; i < m3; i++) cin >> CD[i].first >> CD[i].second;
    vector<set<int>> BA(n2), CB(n3), DC(n4);
    for (auto p : AB) {
        BA[p.second - 1].insert(p.first - 1);
    }
    for (auto p : BC) {
        CB[p.second - 1].insert(p.first - 1);
    }
    for (auto p : CD) {
        DC[p.second - 1].insert(p.first - 1);
    }

    int ans = (int) 1e9;

    vector<pair<int, int>> lala;
    for (int i = 0; i < n1; i++) {
        lala.pb({A[i], i});
    }
    sort(all(lala));
    for (int i = 0; i < n2; i++) {
        bool ws = false;
        for (int j = 0; j < n1; j++) {
            if (BA[i].find(lala[j].second) == BA[i].end()) {
                B[i] += lala[j].first;
                ws = true;
                break;
            }
        }
        if (!ws) {
            B[i] += (int) 1e9;
        }
    }

    vector<pair<int, int>> lalb;
    for (int i = 0; i < n2; i++) {
        lalb.pb({B[i], i});
    }
    sort(all(lalb));
    for (int i = 0; i < n3; i++) {
        bool ws = false;
        for (int j = 0; j < n2; j++) {
            if (CB[i].find(lalb[j].second) == CB[i].end()) {
                C[i] += lalb[j].first;
                ws = true;
                break;
            }
        }
        if (!ws) {
            C[i] += (int) 1e9;
        }
    }

    vector<pair<int, int>> lalc;
    for (int i = 0; i < n3; i++) {
        lalc.pb({C[i], i});
    }
    sort(all(lalc));
    for (int i = 0; i < n4; i++) {
        bool ws = false;
        for (int j = 0; j < n3; j++) {
            if (DC[i].find(lalc[j].second) == DC[i].end()) {
                D[i] += lalc[j].first;
                ws = true;
                break;
            }
        }
        if (!ws) {
            D[i] += (int) 1e9;
        }
        ans = min(ans, D[i]);
    }
    if (ans == 1e9) ans = -1;
    cout << ans << '\n';
}