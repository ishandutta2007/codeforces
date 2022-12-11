#include <bits/stdc++.h>

#define ff first
#define ss second
#define sl (l1 + l2 + l3)
#define sr (r1 + r2 + r3)

using namespace std;

typedef long long ll;

string s, k;
int ss[30], sb[30], ks[30], kb[30];
int ura, opa, k1, k2;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> s >> k;
    for (char ch : s) {
        if ('a' <= ch && ch <= 'z')
            ss[ch - 'a']++;
        else
            sb[ch - 'A']++;
    }

    for (char ch : k) {
        if ('a' <= ch && ch <= 'z')
            ks[ch - 'a']++;
        else
            kb[ch - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        k1 = min(ss[i], ks[i]);
        k2 = min(sb[i], kb[i]);
        ss[i] -= k1;
        ks[i] -= k1;
        sb[i] -= k2;
        kb[i] -= k2;
        ura += k1 + k2;
        opa += min(ss[i] + sb[i], ks[i] + kb[i]);
    }

    cout << ura << " " << opa << "\n";

    return 0;
}