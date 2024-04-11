#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

const int N = 1013;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < (n + 1) / 2; i++)
        cin >> a[i];
        
    int x;
    cin >> x;
    
    for(int i = (n + 1) / 2; i < n; i++)
        a[i] = x;
        
    li sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i];
        
    if(x > 0) {
        cout << (sum > 0 ? n : -1) << endl;
    } else {
        vector<li> p(n + 1, 0);
        for(int i = 0; i < n; i++) {
            p[i + 1] = p[i] + a[i];
        }
        
        li mn = sum;
        for(int k = n; k > n / 2; k--) {
            //cout << k << ' ' << mn << ' ' << p[n] - p[n - k] << endl;
            if(mn > 0) {
                cout << k << endl;
                return 0;
            }
            
            mn -= x;
            mn = min(mn, p[n] - p[n - k + 1]);
        }
        
        cout << -1 << endl;
    }
}