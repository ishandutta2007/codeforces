#include<bits/stdc++.h>
using namespace std;

#define int long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    if (s < n * 2) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n - 1; i++) cout << "2 ";
    cout << s - 2 * (n - 1) << "\n1\n";
    return 0;
}