#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    long long ret = (long long) n * (n - 1) / 2;
    int cnt = 1;
    for (int i=1; i<n; i++) {
        if (s[i] == s[i-1])
            cnt++;
        else {
            ret -= cnt;
            cnt = 1;
        }
    }

    reverse(s.begin(), s.end());
    cnt = 1;
    for (int i=1; i<n; i++) {
        if (s[i] == s[i-1])
            cnt++;
        else {
            ret -= cnt - 1; // AB or BA gets counted twice
            cnt = 1;
        }
    }

    cout << ret << "\n";

    return 0;
}