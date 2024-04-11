#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
double p[N];

int main() {
    cin >> n;
    for(int i = 0; i <= n; i++) cin >> p[i];

    double res = 0;
    for(int i = 0; i <= n / 2; i++) {
        for(int j = n - n / 2; j <= n; j++) {
            if(i == j) {
                res = max(res, p[i]);
            }
            double x = j - (double) n / 2, y = (double) n / 2 - i;
            res = max(res, (p[i] * x + p[j] * y) / (x + y));
        }
    }
    cout << fixed << setprecision(10) << res << endl;
}