#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n, a[N], f[N];
long long x, y, w;

void Enter() {
}

void Process() {
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        long long sum = 0, w;
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> w, sum = (sum + w) % n;
        cout << sum * (n - sum) << '\n';
    }
}