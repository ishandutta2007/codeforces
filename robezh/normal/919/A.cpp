#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    double minC = 1000000;
    double a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        minC = min(minC, a / b);
    }
    cout << fixed << setprecision(10) << minC * (double)m;
}