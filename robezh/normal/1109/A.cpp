#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50;

int n;
int a[N];
map<int, int> mp[2];
ll res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    mp[0][0] = 1;
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cur ^= a[i];
        res += mp[i % 2][cur];
        mp[i % 2][cur] ++;
    }
    cout << res << endl;
}