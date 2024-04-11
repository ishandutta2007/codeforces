#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e6 + 7;

const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0, 0, -1};
string dir = "SEWN";

string s, k;
int n;
int z[N], l, r;
char ss[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &n);
    n--;
    gets(ss);
    gets(ss);
    s = ss;
    gets(ss);
    k = ss;
    reverse(k.begin(), k.end());
    for (int i = 0; i < n; i++) {
        if (k[i] == 'S') k[i] = 'N';
        else if (k[i] == 'N') k[i] = 'S';
        else if (k[i] == 'W') k[i] = 'E';
        else if (k[i] == 'E') k[i] = 'W';
    }

    s = k + "#" + s + "@";
    l = r = 0;
    for (int i = 1; i <= n * 2; i++) {
        z[i] = min(max(0, r - i), z[i - l]);
        while (s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
    /*cerr << s << "\n";
    for (int i = 0; i <= n * 2; i++)
        cerr << z[i] << " ";
    cerr << "\n";*/

    if (r <= n * 2)
        cout << "YES\n";
    else
        cout << "NO\n";


    return 0;
}