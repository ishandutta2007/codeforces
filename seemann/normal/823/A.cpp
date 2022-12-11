#include <bits/stdc++.h>

#define clr(a) memset(a, 0, sizeof(a))

using namespace std;

typedef long long ll;
typedef long double ldb;

const ldb EPS = 1e-8;
const int MAXN = 1e5+100;

int main() {
#ifdef LOCAL
        //freopen("", "r", stdin);
        //freopen("", "w", stdout);
#endif
        int n, k;
        cin >> n >> k;
        int m = n-1;
        m -= k;
        int d = (m + k - 1) / k + 1;
        int l = (m - 1) % k + 1;  
        cout << d*2 - int(l == 1)  << '\n';
        int v = 2;
        for(int i = 0; i < k; i++) {
            cout << 1 << ' ' << v << '\n';
            v++;
                for(int j = 1; j < d - int(i >= l); j++) {
                cout << v - 1 << ' ' << v << '\n';
                v++; 
            }
        }
        return 0;
}