#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool fuck = false;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) fuck = true;
        }
        if (!fuck) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}