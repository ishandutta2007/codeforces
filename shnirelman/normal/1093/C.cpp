#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> b(n / 2);
    for(int i = 0; i < n / 2; i++) {
        cin >> b[i];
    }
    
    vector<long long> a(n);
    a[0] = 0;
    a[n - 1] = b[0];
    for(int i = 1; i < n / 2; i++) {
        a[i] = max(a[i - 1], b[i] - a[n - i]);
        a[n - i - 1] = b[i] - a[i];
    }
    
    for(auto a1 : a)
        cout << a1 << ' ';
}