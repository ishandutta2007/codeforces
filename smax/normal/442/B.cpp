#include <bits/stdc++.h>
using namespace std;

double p[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> p[i];

    sort(p, p + n, greater<double>());
    double ret = 0;
    for (int i=0; i<n; i++) {
        double sum = 0;
        for (int j=0; j<=i; j++) {
            double part = 1;
            for (int k=0; k<=i; k++)
                part *= (k == j ? p[k] : 1 - p[k]);
            sum += part;
        }
        ret = max(ret, sum);
    }

    cout << fixed << setprecision(10) << ret << "\n";

    return 0;
}