#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    set<int> prefixes = {0};
    int suuuuuuum = 0;
    int ans = 0;
    bool g= true;
    for (int i = 1; i <= n; i++) {
        suuuuuuum += A[i];
        if (prefixes.find(suuuuuuum) != prefixes.end()) {
            ans++;
            prefixes = {0};
            suuuuuuum = A[i];
        }
        prefixes.insert(suuuuuuum);
    }
    cout << ans << '\n';

}