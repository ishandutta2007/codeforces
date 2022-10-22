#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, m;
    cin >> n >> k >> m;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    
    sort(a.begin(), a.end());
    
    long long sum = 0;
    for(int i = 0; i < n; i++)sum += a[i];
    
    long double ans = (sum + min(k * 1ll * n, m * 1ll)) * (long double)(1) / n;
    for(int i = 0; i < min(n - 1, m); i++){
        sum -= a[i];
        //cout << k * (n - i - 1)<< ' ' <<  m - i - 1 << endl;
        //cout << ans << ' ' << (sum + min(k * (n - i - 1), m - i - 1)) * (long double)(1) / (n - i - 1)<< endl;
        ans = max(ans, (sum + min(k * 1ll * (n - i - 1), 1ll * m - i - 1)) * (long double)(1) / (n - i - 1));
    }
    
    cout << setprecision(8) << fixed << ans;
}