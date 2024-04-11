#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector <int> ps(n + 1, 0), pt(m + 1, 0);
    vector <int> psa(n + 1, 0), pta(m + 1, 0);
    for (int i = 0; i < n; i++) {
        ps[i + 1] = ps[i];
        psa[i + 1] = psa[i];
        if (s[i] != 'A') {
            psa[i + 1] = 0;
            ps[i + 1]++;
        } else {
            psa[i + 1]++;
        }
    }
    for (int i = 0; i < m; i++) {
        pt[i + 1] = pt[i];
        pta[i + 1] = pta[i];
        if (t[i] != 'A') {
            pt[i + 1]++;
            pta[i + 1] = 0;
        } else {
            pta[i + 1]++;
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int sum1 = ps[r1] - ps[l1 - 1];
        int sum2 = pt[r2] - pt[l2 - 1];
        if (sum1 > sum2) {
            cout << 0;
            continue;
        }
        if ((sum2 - sum1) % 2) {
            cout << 0;
            continue;
        }
        int cnta1 = min(psa[r1], r1 - l1 + 1);
        int cnta2 = min(pta[r2], r2 - l2 + 1);
        if (cnta2 > cnta1) {
            cout << 0;
            continue;
        }
        if (sum1 == sum2 && (cnta1 - cnta2) % 3) {
            cout << 0;
            continue;
        }
        if (cnta1 == cnta2 && cnta1 == r1 - l1 + 1 && sum2 > sum1) {
            cout << 0;
            continue;
        }
        cout << 1;
    }
}