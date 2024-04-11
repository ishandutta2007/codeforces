#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 100;

int N;
double pmax[MAXN], pmin[MAXN];
double maxg[MAXN], ming[MAXN];

double x[MAXN], y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> pmax[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> pmin[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        maxg[i] = maxg[i + 1] + pmax[i];
        ming[i] = ming[i + 1] + pmin[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        double v1 = ming[i];
        double v2 = maxg[i];

        double a = -1;
        double b = v1 + v2;
        double c = -v1;

        x[i] = (-b - sqrt(max(0., b * b - 4 * a * c))) / (2 * a);
        y[i] = b - x[i];
    }

    for (int i = 0; i < N; i++) {
        cout << x[i] - x[i+1] << " ";
    }
    cout << "\n";

    for (int i = 0; i < N; i++) {
        cout << y[i] - y[i+1] << " ";
    }
    cout << "\n";

    return 0;
}