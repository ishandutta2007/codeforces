#include <bits/stdc++.h>
using namespace std;

int n, a[200000];

double f(double x) {
    double mn = 0, mx = 0, mnSum = 0, mxSum = 0;
    for (int i=0; i<n; i++) {
        double b = a[i] - x;
        mnSum = min(mnSum, 0.0) + b;
        mxSum = max(mxSum, 0.0) + b;
        mn = min(mn, mnSum);
        mx = max(mx, mxSum);
    }
    return max(-mn, mx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    double l = -10000, r = 10000;
    for (int i=0; i<200; i++) {
        double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (f(m1) > f(m2))
            l = m1;
        else
            r = m2;
    }

    cout << fixed << setprecision(10) << f(l) << "\n";

    return 0;
}