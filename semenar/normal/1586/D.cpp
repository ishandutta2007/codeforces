#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)x.size())
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()

typedef long long ll;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> perm(n);
    perm[n - 1] = 1;

    for (int i = 0; i < n - 1; i++) {
        cout << "?";
        for (int j = 0; j < n; j++) {
            if (j != n - 1) cout << " " << n - i;
            else cout << " 1";
        }
        cout << "\n";
        cout.flush();
        int x;
        cin >> x;
        if (x > 0) {
            perm[n - 1] = n - i;
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (perm[n - 1] == i) continue;
        cout << "?";
        for (int j = 0; j < n; j++) {
            if (j != n - 1) cout << " " << perm[n - 1];
            else cout << " " << i;
        }
        cout << "\n";
        cout.flush();
        int x;
        cin >> x;
        perm[x - 1] = i;
    }

    cout << "!";
    for (int i = 0; i < n; i++) cout << " " << perm[i];
    cout << "\n";
    cout.flush();

    return 0;
}