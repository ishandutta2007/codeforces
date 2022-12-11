#include <bits/stdc++.h>

using namespace std;

int n, ans, a[30], b;
string s, t;

int main() {
    cin >> n >> s;
    for (int i = 0; i < s.length(); i++) {
        if ('a' <= s[i] && s[i] <= 'z')
            a[s[i] - 'a']++;
        else {
            if (a[s[i] - 'A'] > 0)
                a[s[i] - 'A']--;
            else
                b++;
        }
    }
    cout << b;
    return 0;
}