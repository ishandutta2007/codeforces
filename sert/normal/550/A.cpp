#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

string s;
int ab1 = -1, ba1 = -1, ab2, ba2;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> s;
    for (int i = 1; i < s.length(); i++)
    if (s[i - 1] == 'B' && s[i] == 'A') {
        if (ba1 == -1) ba1 = i;
        ba2 = i;
    } else if (s[i - 1] == 'A' && s[i] == 'B') {
        if (ab1 == -1) ab1 = i;
        ab2 = i;
    }

    if (ab1 != -1 && ba1 != -1 && (ba1 < ab2 - 1 || ab1 < ba2 - 1))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}