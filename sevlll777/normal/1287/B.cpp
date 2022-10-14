#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fro for
#define pb push_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<string> A(n);
    set<string> B;
    for (int i = 0; i < n;i++) {
        cin >> A[i];
        B.insert(A[i]);
    }
    int ans=0;
    for (int i = 0 ; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            string lol = "";
            int can = 1;
            for (int y = 0; y < k; y++) {
                if (A[i][y] == A[j][y]) {
                    lol+=A[i][y];
                } else {
                    lol += 'S' + 'E' + 'T' - A[i][y] - A[j][y];
                }
            }
            if (can && B.find(lol) != B.end()) ans++;
        }
    }
    cout<<ans/3;
}