#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 55;
ll fib[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fib[0] = fib[1] = 1;
    for(int i = 2; i < MAX; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int n;
    ll k;
    cin >> n >> k;
    k--;
    int ps = 1;
    vector<int> res(n + 1);
    while(ps <= n) {
        if(k < fib[n - ps] || ps == n) {
            res[ps] = ps;
            ps++;
        }
        else {
            k -= fib[n - ps];
            res[ps] = ps + 1;
            res[ps + 1] = ps;
            ps += 2;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << '\n';
}