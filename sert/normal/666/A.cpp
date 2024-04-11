#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;
typedef long double ld;

bool d2[N], d3[N];
set <string> ans;
string s;
string tmp;
void add(int st, int len) {
    tmp.clear();
    for (int i = st; i < st + len; i++)
        tmp += s[i];
    ans.insert(tmp);
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> s;
    int n = s.length();
    d2[n - 2] = d3[n - 3] = true;

    for (int i = n - 1; i >= 5; i--) {
        if (d2[i]) {
            add(i, 2);
            d3[i - 3] = true;
            if (s[i] != s[i - 2] || s[i + 1] != s[i - 1])
                d2[i - 2] = true;
        }

        if (d3[i]) {
            add(i, 3);
            d2[i - 2] = true;
            if (s[i] != s[i - 3] || s[i + 1] != s[i - 2] || s[i + 2] != s[i - 1])
                d3[i - 3] = true;
        }
    }

    cout << ans.size() << "\n";
    for (string t: ans)
        cout << t << "\n";
    return 0;
}