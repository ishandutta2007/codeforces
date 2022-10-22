#include <iostream> 
typedef long long ll;

using namespace std;

int main()
{
    ll n;
    int k;
    cin >> n >> k;
    --k;
    --n;
    if (1LL * k * (k + 1) / 2 < n)
    {
        cout << -1;
        return 0;
    } 
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    int L = 0, R = k;
    while (R - L > 1)
    {
        int M = (R + L) / 2;
        if (1LL * (k + k - M + 1) * M / 2 - n >= 0)
            R = M;
        else
            L = M;
    }
    cout << R;
}