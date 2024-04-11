#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a[N];
ll n, m, k;
string s = "CODEFORCES";
string t;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> t;
    for (int i = 0; i < t.length(); i++)
        if (t[i] == s[i]) {
            n++;
            if (n == s.length())
                break;
        }
        else
            break;
    for (int i = 0; i < t.length(); i++)
        if (t[t.length() - i - 1] == s[s.length() - i - 1]) {
            n++;
            if (n == s.length())
                break;
        }
        else
            break;

    if (n >= s.length())
        cout << "YES\n";
    else
        cout << "NO\n";



    return 0;
}