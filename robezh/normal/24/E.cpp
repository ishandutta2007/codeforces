#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e5 + 50;
const double INF = 1e19;

int n;
int x[N], v[N];
double mx, tx;

bool check(double t) {
    mx = -INF;
    for(int i = 0; i < n; i++) {
        tx = v[i] * t + x[i];
        if(v[i] > 0) {
            mx = max(mx, tx);
        }
        else {
            if(mx > tx) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i] >> v[i];
    double l = 0, r = 2e9, mid;
    for(int ite = 0; ite < 100; ite++) {
        mid = (r + l) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    if(r == 2e9) cout << -1 << endl;
    else cout << fixed << setprecision(18) << r << endl;

    cin.get(); cin.get();
    return 0;
}