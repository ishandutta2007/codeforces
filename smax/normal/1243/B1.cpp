#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k;
    cin >> k;
    while (k--) {
        int n;
        string s, t;
        cin >> n >> s >> t;

        char sc = '$', tc = '$';
        int numDiff = 0;
        bool solExists = true;
        for (int i=0; i<n; i++)
            if (s[i] != t[i]) {
                numDiff++;
                if (sc != '$' && s[i] != sc || tc != '$' && t[i] != tc)
                    solExists = false;
                sc = s[i];
                tc = t[i];
            }

        if (solExists && numDiff == 2)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}