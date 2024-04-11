#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e3 + 34;
const ll md = 1e9 + 7;

string s[N];
bool a[N][N];
string q = "abcdefghijklmnopqrstuvwxyz";
int p, n;

bool cmp(char x, char y) {
    return a[x - 'a'][y - 'a'];
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int j = 0; j < n; j++)
        for (int i = j + 1; i < n; i++) {
            p = 0;
            while (true) {
                if (p == s[j].length()) break;
                if (p == s[i].length()) {
                    cout << "Impossible\n";
                    return 0;
                }
                if (s[j][p] != s[i][p]) {
                    a[s[j][p] - 'a'][s[i][p] - 'a'] = true;
                    break;
                }
                p++;
            }
        }

    for (int k = 0; k < 26; k++)
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++) {
                if (a[i][k] && a[k][j]) 
                    a[i][j] = true;
            }

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            if (a[i][j] && a[j][i]) {
                cout << "Impossible";
                return 0;
            }

    bool u[26], fnd;
    for (int i = 0; i < 26; i++) u[i] = false;

    for (int i = 0; i < 26; i++) {
        fnd = false;
        for (int j = 0; !fnd && j < 26; j++) {
            if (u[j])
                continue;
            fnd = true;
            for (int k = 0; k < 26; k++)
                if (!u[k] && a[k][j])
                    fnd = false;
            if (fnd) {
                cout << char('a' + j);
                u[j] = true;
            }
        }
    }

    //return 0;
}