#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, p, d, w;
    cin >> n >> p >> w >> d;
    
    long long p1 = p;
    long long x = p / w;
    p %= w;
    
    int cnt = 0;
    while(p <= p1 && p % d > 0 && cnt < 5e7) {
        x--;
        p += w;
        cnt++;
    }
    
    if(p > p1 || p % d > 0 || (n - x - p / d < 0)) {
        cout << -1;
    } else {
        cout << x << ' ' << p / d << ' ' << n - x - p / d;
    }
}