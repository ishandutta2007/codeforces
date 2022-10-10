#include <bits/stdc++.h>
using namespace std;

string p;
int m, lps[100000], cnt[100001] = {};
bool len[100000] = {};

void preprocess() {
    lps[0] = -1;
    int j = 0;
    for (int i=1; i<m; i++) {
        while (j != 0 && p[i] != p[j])
            j = lps[j-1];
        lps[i] = (j += (p[i] == p[j]));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> p;
    m = p.length();

    preprocess();

    int j = m - 1, ret = 0;
    while (j >= 0) {
        len[j+1] = true;
        ret++;
        j = lps[j] - 1;
    }

    for (int i=m-1; i>0; i--)
        cnt[lps[i]]++;
    for (int i=m-1; i>0; i--)
        cnt[lps[i]] += cnt[i+1];

    cout << ret << "\n";
    for (int i=1; i<=m; i++)
        if (len[i])
            cout << i << " " << cnt[i] + 1 << "\n";

    return 0;
}