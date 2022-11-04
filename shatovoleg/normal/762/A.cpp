#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    int k;
    cin >> n >> k;
    --k;
    ll i;
    vector<ll> res;
    for (i = 1; i * i < n; ++i)
        if (n % i == 0)
        {
            res.push_back(i);
            res.push_back(n / i);
        }
    if (i * i == n)
        res.push_back(i);
    sort(res.begin(), res.end());
    if (k >= res.size())
        cout << -1 << endl;
    else
        cout << res[k] << endl;
}