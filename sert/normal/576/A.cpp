#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a[N];
ll n, m, t, k, x;
bool u[N];
vector <int> ans;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (!u[i]) {
            for (int j = i * i; j <= n; j += i)
                u[j] = true;
            x = i;
            while (x <= n) {
                ans.push_back(x);
                x *= i;
            }
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}