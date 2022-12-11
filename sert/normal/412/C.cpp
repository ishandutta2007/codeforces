#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 34;

string s[N];
char ans[N];
int n, m;
char ch;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    m = s[0].length();
    for (int j = 0; j < m; j++) {
        ch = '@';
        for (int i = 0; i < n; i++) {
            if (s[i][j] != '?' && ch == '@')
                ch = s[i][j];
            else if (s[i][j] != '?' && s[i][j] != ch)
                ch = '!';
        }
        if (ch == '!')
            printf("?");
        else
            printf("%c", (ch == '@' ? 's' : ch));
    }
    return 0;
}