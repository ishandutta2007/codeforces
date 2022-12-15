#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector <int> ch(26 * 26, -1);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            ch[(s[i] - 'a') * 26 + (t[i] - 'a')] = i;
            total += 1;
        }
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (ch[i * 26 + j] != -1 && ch[j * 26 + i] != -1) {
                cout << total - 2 << '\n' << ch[i * 26 + j] + 1 << ' ' << ch[j * 26 + i] + 1 << '\n';
                exit(0);
            }
        }
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (ch[i * 26 + j] != -1) {
                for (int k = 0; k < 26; ++k) {
                    if (ch[k * 26 + i] != -1) {
                        cout << total - 1 << '\n' << ch[i * 26 + j] + 1 << ' ' << ch[k * 26 + i] + 1 << '\n';
                        exit(0);
                    }
                }
                for (int k = 0; k < 26; ++k) {
                    if (ch[j * 26 + k] != -1) {
                        cout << total - 1 << '\n' << ch[i * 26 + j] + 1 << ' ' << ch[j * 26 + k] + 1 << '\n';
                        exit(0);
                    }
                }
            }
        }
    }
    cout << total << '\n' << -1 << ' ' << -1 << '\n';
    return 0;
}