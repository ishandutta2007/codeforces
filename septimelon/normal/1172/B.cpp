#include <bits/stdc++.h>

using namespace std;

long long fact[200001];
int deg[200001];
long long n;

int main()
{
    cin >> n;
    int a, b;
    for (int i = 0; i <= n; i++)
        deg[i] = 0;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    fact[0] = 1;
    for (int i = 1; i < n; i++) {
        fact[i] = (fact[i-1] * i) % 998244353;
    }
    long long ans = 1;
    for (int i = 1; i <= n; i++)
        ans = (ans * fact[deg[i]]) % 998244353;
    ans = (ans * n) % 998244353;
    cout << ans << endl;
    return 0;
}