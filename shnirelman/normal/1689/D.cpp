#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e6 + 13;
const int K = 17;
const int M = 1e9 + 7;
const int LOGN = 20;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

int n, m;

bool isin(int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < m);
}

pii get(const vector<pii>& b, int d) {
//    cout << "get   d = " << d << endl;
    vector<int> x, y;
    {
        int lf = -INF, rg = INF;
        for(pii p : b) {
            lf = max(lf, p.f - d);
            rg = min(rg, p.f + d);
//            cout << "for " << p.f << ' ' << p.f - d << ' ' << p.f + d << endl;
        }

//        cout << "lf rg " << lf << ' ' << rg << endl;
        if(lf > rg)
            return pii(INF, INF);
        else {
            x.push_back(lf);
            if(lf + 1 <= rg)
                x.push_back(lf + 1);
        }

    }

    {
        int lf = -INF, rg = INF;
        for(pii p : b) {
            lf = max(lf, p.s - d);
            rg = min(rg, p.s + d);
        }

//        cout << "lf rg " << lf << ' ' << rg << endl;
        if(lf > rg)
            return pii(INF, INF);
        else {
            y.push_back(lf);
            if(lf + 1 <= rg)
                y.push_back(lf + 1);
        }
    }

    for(int x1 : x) {
        for(int y1 : y) {
            if((x1 + y1) % 2 == 0)
                return pii((x1 + y1) / 2, (x1 - y1) / 2);
        }
    }

    return pii(INF, INF);
//    return pii((x + y) / 2, (x - y) / 2);
}

void solve() {
    cin >> n >> m;

    vector<string> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<pii> b;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'B') {
                b.emplace_back(i + j, i - j);
            }
        }
    }

//    for(pii b1 : b)
//        cout << b1.f << ' ' << b1.s << endl;
//    cout << endl;

    int l = -1, r = n + m + 1;
    while(r - l > 1) {
        int mid = (l + r) / 2;

        pii res = get(b, mid);
        if(res.f != INF)
            r = mid;
        else
            l = mid;
    }

//    cout << "res = " << r << endl;
    pii ans = get(b, r);
    cout << ans.f + 1 << ' ' << ans.s + 1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}