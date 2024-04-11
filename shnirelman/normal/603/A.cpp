#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 1;
    for(int i = 1; i < n; i++)
        ans += (s[i] != s[i - 1]);

    int a = 0;
    int cnt = 0;
    for(int i = 0; i < n - 1; i++) {
//        if(s[i] == s[i + 1] && s[i] != s[i + 2] && s[i + 2] == s[i + 3])
//            a = max(a, 2);
//
//        if(s[i] == s[i + 1] && s[i] == s[i + 2])
//            a = max(a, 2);

        if(s[i] == s[i + 1]) {
            //a = max(a, 1);
            cnt++;
        }

    }

    if(cnt > 1)
        a = 2;
    else if(cnt == 1)
        a = 1;
    else
        a = 0;

    cout << a + ans;
}