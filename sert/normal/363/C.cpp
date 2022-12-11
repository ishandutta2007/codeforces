#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 4e6 + 34;

string s, k;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> s;
    if (s.length() < 3) {
        cout << s;
        return 0;
    }
    k += s[0];
    k += s[1];
    for (int i = 2; i < s.length(); i++) 
        if (s[i] != s[i - 1] || s[i] != s[i - 2])
            k += s[i];
    s.clear();
    if (k.length() < 4) {
        cout << k;
        return 0;
    }
    s += k[0];
    s += k[1];
    s += k[2];
    for (int i = 3; i < k.length(); i++) {
        if (k[i] != k[i - 1] || s[s.length() - 2] != s[s.length() - 3])
            s += k[i];
    }
    cout << s;

    //return 0;
}