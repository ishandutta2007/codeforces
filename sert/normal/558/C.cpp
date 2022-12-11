#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

int n, a[N], len[N], ans, am[N];
string s[N];

void go(int v) {
    int x = a[v];
    while (x > 0) {
        s[v] += char('0' + x % 2);
        x /= 2;
    }
    reverse(s[v].begin(), s[v].end());
    //while (s[v].length() < 18) s[v] += "_";
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        go(i);
        //cerr << s[i] << "\n";
    }
    int k1, leng = 1e9;

    for (int i = 0; i < 19; i++) {
        k1 = 0;
        for (int j = 0; j < n; j++)
            if (s[j].length() > i)
                if (s[j][i] == '1')
                    k1++;
        if (k1 > 0 && k1 < n) {
            leng = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) leng = min(leng, (int)s[i].length());

    //cout << leng << "\n";
    int cur = 0;
    for (int i = 0; i < n; i++) {
        len[i] = leng;
        s[i] += "1";
        while (s[i][len[i]] == '0') len[i]++;
        ans += (int)s[i].length() - len[i] - 1;
        //cerr << i + 1 << ": " << len[i] << "\n";
        am[len[i]]++;
        cur += len[i];
    }
    //cerr << ans << "\n";
    int add = 1e9;
    int lft = 0;
    //cerr << cur << "\n";
    for (int i = 0; i < 20; i++) {
        add = min(add, cur);
        lft += am[i];
        cur += lft;
        cur -= (n - lft);
    }

    cout << ans + add;


    return 0;
}