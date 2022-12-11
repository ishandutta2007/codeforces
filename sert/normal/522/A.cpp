#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>

using namespace std;

string name1, tmp, name2;
int n, ans = 1;
map <string, int> m;

void ToLower(string &s) {
    for (int i = 0; i < s.length(); i++)
        if ('A' <= s[i] && s[i] <= 'Z')
            s[i] += 'a' - 'A';
}

int main() {
    ///freopen("a.in", "r", stdin);
    cin >> n;
    m["polycarp"] = 1;
    for (int i = 0; i < n; i++) {
        cin >> name1 >> tmp >> name2;
        ToLower(name1);
        ToLower(name2);
        m[name1] = m[name2] + 1;
        ans = max(ans, m[name1]);
    }
    cout << ans;
    return 0;
}