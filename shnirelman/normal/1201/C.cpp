#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    sort(a.begin(), a.end());
    
    int m = n / 2;
    int i;
    for(i = m; i < n - 1 && k > 0; i++) {
        int d = min(k * 1ll, (i - m + 1) * 1ll * (a[i + 1] - a[i]));
        k -= d;
        a[m] += d / (i - m + 1);
        //cout << d << ' ' << k << ' ' << a[m] << endl;
    }
    
    if(k > 0)
        a[m] += k / (i - m + 1);
        
    cout << a[m];

}