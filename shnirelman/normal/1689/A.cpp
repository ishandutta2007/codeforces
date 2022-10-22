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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    string a, b;
    cin >> a >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    string c = "";
    int cura = 0, curb = 0;
    for(int ia = 0, ib = 0; ia < a.size() && ib < b.size(); ) {
//        cout << c << ' ' << ia << ' ' << ib << ' ' << cura << ' ' << curb << ' ' << a[ia] << ' ' << b[ib] << endl;
        if(cura < k && (a[ia] < b[ib] || curb == k)) {
//                        && (b.size() - ib + k - 1) / k - 1 <= a.size() - ia) ||
//                        (a[ia] > b[ia] && (a.size() - ia + k - 1) / k > b.size() - ib))) {
                c += a[ia];
                cura++;
                curb = 0;
                ia++;
           } else {
                c += b[ib];
                curb++;
                cura = 0;
                ib++;
           }
    }

    cout << c << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}