#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 2e5 + 5;
 
int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1), pref(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        if(i % 2)
            v[i] *= -1;
        pref[i] = pref[i - 1] + v[i];
    }
    int sum = accumulate(v.begin(), v.end(), 0);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(pref[i - 1] == (sum - pref[i - 1] - v[i]))
            ans++;
    }
    cout << ans << endl;
}