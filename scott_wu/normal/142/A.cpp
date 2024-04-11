#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n;
vector <ll> divisors;

int main()
{
    cin >> n;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back (i);
            if (i * i != n)
                divisors.push_back (n / i);
        }
    }
    sort (divisors.begin(), divisors.end());
    int mid = (divisors.size() + 1) / 2;
    ll lo = 1e12, hi = 0;
    for (int i = 0; i < mid; i++)
        for (int j = i; j < mid; j++)
            for (int k = j; k < mid; k++)
            {
                ll a = divisors[i];
                ll b = divisors[j];
                ll c = divisors[k];
                if (a * b * c != n)
                    continue;
                if ((a+1) * (b+2) * (c+2) < lo)
                    lo = (a+1) * (b+2) * (c+2);
                if ((a+2) * (b+2) * (c+1) > hi)
                    hi = (a+2) * (b+2) * (c+1);
            }
    for (int i = 0; i < mid; i++)
        for (int j = i; j < mid; j++)
            for (int k = mid; k < divisors.size(); k++)
            {
                ll a = divisors[i];
                ll b = divisors[j];
                ll c = divisors[k];
                if (a * b * c != n)
                    continue;
                if ((a+1) * (b+2) * (c+2) < lo)
                    lo = (a+1) * (b+2) * (c+2);
                if ((a+2) * (b+2) * (c+1) > hi)
                    hi = (a+2) * (b+2) * (c+1);
            }
    cout << lo - n << " " << hi - n << "\n";
    //system ("Pause");
    return 0;
}