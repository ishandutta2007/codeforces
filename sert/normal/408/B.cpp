#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 2014;

ll a[N], b[N];
string s, k;
ll ans;

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> s >> k;
    for (int i = 0; i < s.length(); i++)
        a[s[i] - 'a']++;
    for (int i = 0; i < k.length(); i++)
        b[k[i] - 'a']++;

    for (int i = 0; i < 26; i++) {
        if (a[i] == 0 && b[i] != 0) {
            cout << "-1\n";
            return 0;
        }
        ans += min(a[i], b[i]);
    }

    cout << ans;

    return 0;
}