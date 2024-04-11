#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define ll long long
#define ld long double

char inv(char c) {
    return c == '0' ? '1' : '0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        vector<int> p;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] != b[i]) {
                if (a[0] == b[i]) {
                    p.pb(1);
                    a[0] = inv(a[0]);
                }
                p.pb(i + 1);
                for (int j = 0; j <= i; ++j) a[j] = inv(a[j]);
                reverse(a.begin(), a.begin() + i + 1);
            }
        }
        cout << p.size();
        for (auto e : p) cout << " " << e;
        cout << '\n';
    }
    return 0;
}