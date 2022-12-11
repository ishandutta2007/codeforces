#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int get_num(char ch) {
    if (ch == 'A') return 0;
    if (ch == 'C') return 1;
    if (ch == 'G') return 2;
    if (ch == 'T') return 3;
}

bitset <200000> a[4], ans, cur;
string s, t;
int n, m, k, num;
int b[600002][4];
int cnt[4], gans;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m >> k;
    cin >> s >> t;

    for (int i = 0; i < s.length(); i++) {
        b[max(0, i - k)][get_num(s[i])]++;
        b[i + k + 1][get_num(s[i])]--;
    }

    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < 4; j++)
            cnt[j] += b[i][j];
        for (int j = 0; j < 4; j++)
            a[j][i] = !!cnt[j];
        ans[i] = 1;
    }

    /*for (int i = 0; i < 4; i++) bsout(a[i]);
    bsout(ans);

    cerr << "\n";*/

    for (int i = 0; i < t.length(); i++) {
        num = get_num(t[i]);
        ans &= (a[num] >> i);
    }

    for (int i = 0; i < 200000; i++)
        gans += ans[i];

    cout << gans;

    return 0;
}