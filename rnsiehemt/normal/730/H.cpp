#include <iostream>
#include <string>

using namespace std;

int n, m, x, l;
string s[100];
char w[101];
bool d[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < m; ++i) {
        cin >> x;
        --x;
        d[x] = 1;
        if (!l) l = s[x].length();
        else if (s[x].length() != l) goto fail;
    }
    for (int j = 0; j < l; ++j) {
        char c = 0;
        for (int i = 0; i < n; ++i) if (d[i]) {
            if (!c) c = s[i][j];
            else if (c != '?' && c != s[i][j]) c = '?';
        }
        w[j] = c;
    }
    for (int i = 0; i < n; ++i) if (!d[i] && s[i].length() == l) {
        bool z = 1;
        for (int j = 0; j < l; ++j) if (w[j] != '?' && s[i][j] != w[j]) z = 0;
        if (z) goto fail;
    }

    cout << "Yes\n" << w << '\n';
    return 0;
fail:
    cout << "No\n";
    return 0;
}