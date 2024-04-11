#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;
const ll p = 31;

string s, k;

string getmin(string s) {
    if (s.length() % 2 == 1) return s;
    string s1, s2;
    for (int i = 0; i < s.length() / 2; i++) s1 += s[i];
    for (int i = s.length() / 2; i < s.length(); i++) s2 += s[i];
    s1 = getmin(s1);
    s2 = getmin(s2);
    if (s1 > s2) swap(s1, s2);
    return s1 + s2;
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> s >> k;

    if (getmin(s) == getmin(k))
        cout << "YES\n";
    else
        cout << "NO\n";

    //return 0;
}