#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;
string s;
char a[N];
int len, ans;
int main()  {
    //freopen("a.in", "r", stdin);
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '<' || s[i] == '{')
            a[len++] = s[i];
        else {
            if (len == 0) {
                cout << "Impossible\n";
                return 0;
            }
            len--;
            ans++;
            if (a[len] == '(' && s[i] == ')') ans--;
            if (a[len] == '<' && s[i] == '>') ans--;
            if (a[len] == '[' && s[i] == ']') ans--;
            if (a[len] == '{' && s[i] == '}') ans--;
        }
    }
    if (len)
        cout << "Impossible\n";
    else
        cout << ans;

    return 0;
}