#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 250100;

int N;
ll M;
ll fac[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fac[i] = (fac[i-1] * i) % M;

    ll res = 0;
    for (int i = 1; i <= N; i++)
    {
        ll cv = (fac[i] * fac[N-i]) % M;
        cv = (cv * (N - i + 1)) % M;
        cv = (cv * (N - i + 1)) % M;
        res = (res + cv) % M;
    }
    cout << res << "\n";
}