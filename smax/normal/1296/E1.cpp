#include <bits/stdc++.h>
using namespace std;

struct Pred {
    int c1, c2;
    char color;
};

bool dp[201][26][26] = {};
Pred pred[201][26][26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    dp[0][0][0] = true;
    for (int i=0; i<n; i++)
        for (int c1=0; c1<26; c1++)
            for (int c2=0; c2<26; c2++)
                if (dp[i][c1][c2]) {
                    if (s[i] - 'a' >= c1) {
                        dp[i+1][s[i]-'a'][c2] = true;
                        pred[i+1][s[i]-'a'][c2] = {c1, c2, '0'};
                    }
                    if (s[i] - 'a' >= c2) {
                        dp[i+1][c1][s[i]-'a'] = true;
                        pred[i+1][c1][s[i]-'a'] = {c1, c2, '1'};
                    }
                }

    int i = -1, j = -1;
    for (int c1=0; c1<26; c1++)
        for (int c2=0; c2<26; c2++)
            if (dp[n][c1][c2]) {
                i = c1;
                j = c2;
                break;
            }

    if (i == -1)
        cout << "NO\n";
    else {
        cout << "YES\n";
        string ret;
        while (n > 0) {
            Pred p = pred[n][i][j];
            ret += p.color;
            i = p.c1;
            j = p.c2;
            n--;
        }
        reverse(ret.begin(), ret.end());
        cout << ret << "\n";
    }

    return 0;
}