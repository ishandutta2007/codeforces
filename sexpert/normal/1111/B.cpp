#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long n, k, m;
    cin >> n >> k >> m;
    vector<long long> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.rbegin(), v.rend());
    double ans = 0;
    long long s = 0;
    for(long long i = 1; i <= n; i++) {
        s += v[i - 1];
        if(i < n - m)
            continue;
        ans = max(ans, (double(s + min(i*k, m - (n - i))))/(double(i)));
    }
    cout << fixed << setprecision(20) << ans << endl;
}