#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

int p[210000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 2; i <= 200000; i++) if (!p[i]) {
        for (int j = i+i; j <= 200000; j+=i) p[j]=i;
    }


    int ag = a[1];
    for (int i = 2; i < n; i++) ag = __gcd(ag, a[i]);

    long long ans = 1;
    for (int i = 2; i <= 200000; i++) if (!p[i] && (ag % i == 0 || a[0] % i == 0)) {
        vector<int> cts(n, 1);
        for (int j = 0; j < n; j++) while (a[j] % i == 0) {a[j] /= i; cts[j] *= i;}
        sort(cts.begin(),cts.end());
        ans *= cts[1];
    }

    cout << ans << endl;
    return 0;
}