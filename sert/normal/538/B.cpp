#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a[N];
int n, m, k;
string s = "CODEFORCES";
string t;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> s;
    for (int i = 0; i < s.length(); i++)
        n = max(n, s[i] - '0');

    cout << n << "\n";

    for (int i = 0; i < n; i++) {
        t.clear();
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '0')
                if (t.length() > 0)
                    t += '0';
            if (s[j] != '0') {
                t += '1';
                s[j]--;
            }
        }
        cout << t << " ";
    }


    return 0;
}