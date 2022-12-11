#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e5 + 34;
string s, k, t1, t2;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> s >> k;
    if (s[0] != 'X') t1 += s[0];
    if (s[1] != 'X') t1 += s[1];
    if (k[1] != 'X') t1 += k[1];
    if (k[0] != 'X') t1 += k[0];

    cin >> s >> k;
    if (s[0] != 'X') t2 += s[0];
    if (s[1] != 'X') t2 += s[1];
    if (k[1] != 'X') t2 += k[1];
    if (k[0] != 'X') t2 += k[0];


    int p = 0;
    while (t1[p] != t2[0]) p++;

    for (int i = 0; i < 3; i++)
    if (t2[i] != t1[(i + p) % 3]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    return 0;
}