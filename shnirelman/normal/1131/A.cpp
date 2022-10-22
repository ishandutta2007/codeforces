#include <bits/stdc++.h>

using namespace std;

int main() {
    long long w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    
    long long ans = w1 * 2 + h1 * 2 + 4;
    ans += w2 + h2 * 2;
    ans -= w2;
    
    cout << ans;
    
}