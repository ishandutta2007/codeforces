#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long ll;

int lucky[2100];
int ps, pe, vs, ve, k;
int nlucky = 0;

int amt (int x, int start, int end)
{
    return max (min (end, lucky[x+1] - 1) - max (start, lucky[x] + 1) + 1, 0);
}

int main()
{
    cin >> ps >> pe >> vs >> ve >> k;
    for (int i = 1; i <= 9; i++)
    {
        int pow2 = 1;
        for (int j = 0; j < i; j++)
            pow2 *= 2;
        int bin[15];
        for (int j = 0; j < pow2; j++)
        {
            int temp = j;
            for (int k = i - 1; k >= 0; k--)
            {
                bin[k] = temp % 2;
                temp /= 2;
            }
            int res = 0;
            for (int k = 0; k < i; k++)
                res = 10 * res + ((bin[k]) ? 7 : 4);
            lucky[nlucky] = res;
            nlucky++;
        }
    }
    lucky[nlucky] = 0;
    nlucky++;
    lucky[nlucky] = 1000000100; nlucky++;
    sort (lucky, lucky + nlucky);
    ll ans = 0;
    for (int i = 0; i < nlucky - k - 1; i++)
    {
        ans += (((ll) amt (i, ps, pe) + (((ps <= lucky[i+1]) && (pe >= lucky[i+1])) ? 1 : 0))
            * ((ll) amt (i+k, vs, ve) + (((vs <= lucky[i+k]) && (ve >= lucky[i+k])) ? 1 : 0)));
        ans += (((ll) amt (i, vs, ve) + (((vs <= lucky[i+1]) && (ve >= lucky[i+1])) ? 1 : 0))
            * ((ll) amt (i+k, ps, pe) + (((ps <= lucky[i+k]) && (pe >= lucky[i+k])) ? 1 : 0)));
        //cout << ans << "\n";
    }
    if (k == 1)
    {
        int c = 0;
        for (int i = 0; i < nlucky; i++)
            if ((ps <= lucky[i]) && (lucky[i] <= pe) && (vs <= lucky[i]) && (lucky[i] <= ve))
                c++;
        ans -= c;
    }
    cout << fixed << setprecision (9);
    cout << ((double) ans / (double) (pe - ps + 1) / (double) (ve - vs + 1)) << "\n";
    //system ("Pause");
    return 0;
}