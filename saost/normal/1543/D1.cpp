#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n, k;

int main()
{
    ///ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    cout << setprecision(12) << fixed;
    long long W = 1e10;
    while (t--) {
        cin >> n >> k;
        int w = 0, ans, res = 2;
        for(int i=0; i<n; ++i) {
            if (i == 0) w = i; else w = i ^ (i-1);
            cout << w << '\n';
            fflush(stdout);
            cin >> ans;
            if (ans) break;
        }
        fflush(stdout);
    }
}