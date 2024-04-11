#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int n, m, a, b;
vi lef, rig;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> a >> b;
    lef.resize(n);
    rig.resize(m);
    for(auto &x : lef)
        cin >> x;
    for(auto &x : rig)
        cin >> x;
    double ans = 1e18;
    int bi = -1, bj = -1;
    for(int i = 0; i < m; i++) {
        int v;
        cin >> v;
        ll u = rig[i];
        double y = ((double)(u * a)/(double)b);
        int lo = 0, hi = n - 1;
        if((double)lef[0] < y) {
            while(lo < hi) {
                int mi = (lo + hi + 1)/2;
                if((double)lef[mi] < y)
                    lo = mi;
                else
                    hi = mi - 1;
            }
        }
        for(int j = max(0, lo - 5); j <= min(n - 1, lo + 5); j++) {
            if(hypot(a, lef[j]) + hypot(b - a, rig[i] - lef[j]) + (double)v < ans) {
                ans = hypot(a, lef[j]) + hypot(b - a, rig[i] - lef[j])+ (double)v;
                bi = j;
                bj = i;
            }
        }
    }
    cout << bi + 1 << " " << bj + 1 << endl;
}