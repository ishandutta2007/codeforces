#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    
    int s1 = 0, s2 = 0;
    for(int i = 0; i < l; i++) {
        s1 += (1 << i);
    }
    
    s1 += n - l;
    
    for(int i = 0; i < r; i++) {
        s2 += (1 << i);
    }
    
    s2 += (n - r) * (1 << (r - 1));
    
    cout << s1 << ' ' << s2;
}