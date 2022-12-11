#include <bits/stdc++.h>

#define ff first
#define ss second
#define sl (l1 + l2 + l3)
#define sr (r1 + r2 + r3)

using namespace std;

typedef long long ll;

string s, k;
int cur;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> s >> k;
    cur = 0;
    for (int i = 0; i < s.length() && cur < k.length(); i++)
        if (s[i] == k[cur])
            cur++;

    if (cur == k.length()) {
        cout << "automaton\n";
        return 0;
    }

    sort(s.begin(), s.end());
    sort(k.begin(), k.end());
    if (s == k) {
        cout << "array\n";
        return 0;
    }

    cur = 0;
    for (int i = 0; i < s.length() && cur < k.length(); i++)
        if (s[i] == k[cur])
            cur++;

    if (cur == k.length()) {
        cout << "both\n";
        return 0;
    }

    cout << "need tree\n";

    return 0;
}