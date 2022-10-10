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

    int ret = 0;
    for (int i=0; i<n; i+=2)
        if (s[i] == s[i+1]) {
            ret++;
            if (s[i] == 'a')
                s[i] = 'b';
            else
                s[i] = 'a';
        }

    cout << ret << "\n" << s << "\n";

    return 0;
}