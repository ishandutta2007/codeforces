#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int res = 0;
    while(b >= 1 && c >= 2) {
        b--;
        c -= 2;
        res += 3;
    }
    
    while(a >= 1 && b >= 2) {
        a--;
        b -= 2;
        res += 3;
    }
    
    cout << res << endl;
}

int pow(int n, int k) {
    if(k == 0)
        return 1;
        
    if(k == 1)
        return n;
        
    int pw = pow(n, k / 2);
    if(k % 2)
        return pw * 1ll * pw % M * n % M;
    else
        return pw * 1ll * pw % M;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int ans = pow(pow(2, m) - 1, n) % M;
    //int ans = (pow(pow(2, n), m) - n * 1ll * pow(pow(2, n - 1), m)) % M;
    if(ans < 0)
        ans += M;
    cout << ans;
}