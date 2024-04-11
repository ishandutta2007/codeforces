#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

ll N, M, K;

ll gcd (ll a, ll b)
{
    if (b == 0) return a;
    return gcd (b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M >> K;
    if (K == 1 || ((2 * N * M) % K != 0))
    {
        cout << "NO\n";
        return 0;
    }
    ll n = gcd (N, K);
    ll m = gcd (M, K / n);

    n = N / n;
    m = M / m;
    if (n * m != 2 * N * M / K)
    {
        if (n * 2 <= N) n *= 2;
        else m *= 2;
    }
    cout << "YES\n";
    cout << "0 0\n0 " << m << "\n" << n << " 0\n";
}