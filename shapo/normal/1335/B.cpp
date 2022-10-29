#include <bits/stdc++.h>

using namespace std;

int
main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n, a, b;
        cin >> n >> a >> b;
        // Contruct answer
        string s(n, 'a'); // create string with n letters 'a'
        // Construct first substring
        for (int i = 0; i < b; ++i) {
            // s[0] = 'a' (= 'a' + 0)
            // s[1] = 'b' (= 'a' + 1)
            // s[2] = 'c' (= 'a' + 2)
            // and so on
            s[i] = 'a' + i;
        }
        // Repeat first substring
        for (int i = a; i < n; ++i) {
            s[i] = s[i - a];
            // s[a] = s[0]
            // s[a + 1] = s[1]
            // ...
            // s[a * 2] = s[a] (= s[0])
            // s[a * 2 + 1] = s[a + 1] (= s[1])
            // ...

            // Another way
            // s[i] = s[i % a];
        }
        cout << s << '\n';
    }
    return 0;
}