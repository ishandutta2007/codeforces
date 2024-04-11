#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<bool> pr(n + 2, 1);
    for (int i = 2; i < n + 2; i++) {
        if (pr[i]) for (int j = i + i; j < n + 2; j += i) pr[j] = 0;
    }
    int ans = 1;
    vector<int> cl(n + 2, 1);
    for (int i = 2; i < n + 2; i++) if (!pr[i]) {
        cl[i] = 2;
        ans = 2;
    }
    cout << ans << '\n';
    for (int i = 2; i < n + 2; i++) cout << cl[i] << " ";
    return 0;
}