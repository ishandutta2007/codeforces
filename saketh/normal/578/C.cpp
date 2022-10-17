#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 100;

int N;
int val[MAXN];
double pre[MAXN];

double biggest(double x) {
    double ans = 0;
    double sma = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, pre[i] - sma);
        sma = min(sma, pre[i]);
    }
    return ans;
}

double smallest(double x) {
    double ans = 0;
    double big = 0;
    for (int i = 1; i <= N; i++) {
        ans = min(ans, pre[i] - big);
        big = max(big, pre[i]);
    }
    return ans;
}

double check(double x) {
    for (int i = 1; i <= N; i++) {
        pre[i] = pre[i-1] + val[i] - x;
    }

    return max(fabs(biggest(x)), fabs(smallest(x)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 1; i <= N; i++) 
        cin >> val[i];

    double ans = 1e15;
    double lo = -2e5, hi = 2e5;

    for (int i = 0; i < 100; i++) {
        double p1 = (2 * lo + hi) / 3;
        double p2 = (lo + 2 * hi) / 3; 

        double v1 = check(p1);
        double v2 = check(p2);

        ans = min(ans, v1);
        ans = min(ans, v2);

        if(v1 > v2) {
            lo = p1;
        }
        else hi = p2;
    }

    cout << ans << endl;
}