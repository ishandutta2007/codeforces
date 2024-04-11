#include <bits/stdc++.h>
using namespace std;

bool c[200] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int i=0; i<k; i++) {
        char ch;
        cin >> ch;
        c[ch] = true;
    }

    int i = 0;
    long long ret = 0;
    for (int j=0; j<n; j++) {
        if (!c[s[j]])
            i = j + 1;
        ret += j - i + 1;
    }

    cout << ret << "\n";

    return 0;
}