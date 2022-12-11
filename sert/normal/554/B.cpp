#include <bits/stdc++.h>

#define ff first
#define ss second
#define sl (l1 + l2 + l3)
#define sr (r1 + r2 + r3)

using namespace std;

typedef long long ll;

string s;
map <string, int> m;
int ans, n;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        m[s]++;
    }
    for (auto it : m)
        ans = max(ans, it.second);
    cout << ans;
    return 0;
}