#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector <int> p(3);
    cin >> n >> p[0] >> p[1] >> p[2];
    vector <long long> a(n), b(n, 0);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int T = 0; T < 3; T ++) {
        for(int i = 0; i < n; i ++) b[i] += a[i] * p[T];
        for(int i = 1; i < n; i ++) b[i] = max(b[i], b[i-1]);
    }
    cout << b[n-1] << endl;
}