#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

int n;
double mx[N], mn[N], pmxsum[N], pmnsum[N];
double pa[N], pb[N];
typedef pair<double, double> pd;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> mx[i], pmxsum[i] += pmxsum[i-1] + mx[i];
    for(int i = 1; i <= n; i++) cin >> mn[i], pmnsum[i] += pmnsum[i-1] + mn[i];
    for(int i = 1; i <= n - 1; i++) {
        double a = pmxsum[i], b = pmnsum[n] - pmnsum[i];
        double c = 1 + a - b, d = a;
        double sqr = sqrt(max(0.0, c * c - 4 * d));
        pa[i] = (c - sqr) / 2, pb[i] = (c + sqr) / 2;
    }
    pa[n] = pb[n] = 1;
    for(int i = n; i >= 1; i--) pa[i] -= pa[i-1], pb[i] -= pb[i-1];
    for(int i = 1; i <= n; i++) cout << fixed << setprecision(10) << pa[i] << " ";
    cout << endl;
    for(int i = 1; i <= n; i++) cout << fixed << setprecision(10) << pb[i] << " ";
    cout << endl;

}