#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define endl "\n"
const int inf = 1e18;

string red(string T) {
    int n = T.size();
    string U;
    for (int i = 0, j = 0; i < n;) {
        while (j + 1 < n and T[j+1] == T[j]) {
            j++;
        }
        int par = (j - i + 1) % 2;
        if (par == 1) {
            U += T[i];
        }
        j++, i = j;
    }
    // cout << "T: " << T << ", U: " << U << "\n";
    return U;
}

pair<string, int> reduce(string S) {
    int n = S.size();
    int num_b = 0;
    for (int i = 0; i < n; i++) {
        num_b += (S[i] == 'B');
    }
    string T;
    for (int i = 0; i < n; i++) {
        if (S[i] != 'B') {
            T += S[i];
        }
    }
    num_b %= 2;
    string U;
    while (true) {
        U = red(T);
        if (U == T) break;
        T = U;
    }

    // cout << "T: " << T << "\n";
    // cout << "U: " << U << "\n";
    return make_pair(U, num_b);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        bool yay = (reduce(S) == reduce(T));
        if (yay) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}