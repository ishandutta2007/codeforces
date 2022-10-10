#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        int n;
        long long k;
        string s;
        cin >> n >> k >> s;

        int i = 0;
        for (int j=0; j<n && k>0; j++)
            if (s[j] == '0') {
                while (i < j && (s[i] != '1' || j - i > k))
                    i++;
                swap(s[i], s[j]);
                k -= j - i;
            }

        cout << s << "\n";
    }

    return 0;
}