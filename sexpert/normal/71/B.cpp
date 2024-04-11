#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, t;
    cin >> n >> k >> t;
    vector<int> a(n);
    int re = (n * k * t)/100;
    for(int i = 0; i < n; i++) {
        a[i] = min(re, k);
        re -= a[i];
    }
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}