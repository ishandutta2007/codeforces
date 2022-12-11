#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;

ll n, m, k;
string s;
ll a[N];
vector <int> ans;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;

    for (int i = 1; i <= 100; i++) {
        if (n % 2 == 1)
            ans.push_back(i);
        n /= 2;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}