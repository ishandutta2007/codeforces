#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        string p;
        for (int i=0; i<k; i++)
            p += "()";
        while (p.length() < s.length())
            p = p.substr(0, p.length()-1) + "())";
        cout << n << "\n";
        for (int i=0; i<n; i++)
            for (int j=i; j<n; j++)
                if (s[j] == p[i]) {
                    cout << i+1 << " " << j+1 << "\n";
                    reverse(s.begin() + i, s.begin() + j + 1);
                    break;
                }
    }

    return 0;
}