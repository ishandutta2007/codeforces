#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const int MOD = (int) 1e9 + 7;

int N, K;
int dig[MAXN];

int nlast = -1, klast = -1;
int rlast;

int add (int a, int b)
{
    return (a + b) % MOD;
}

int mult (int a, int b)
{
    return (a * (long long) b) % MOD;
}

int pow (int a, int b)
{
    int res = 1;
    int pow = 0, cpow = a;
    while (b)
    {
        if (b & (1 << pow))
        {
            res = mult (res, cpow);
            b -= (1 << pow);
        }
        pow++;
        cpow = mult (cpow, cpow);
    }
    return res;
}

int inv (int x)
{
    return pow (x, MOD - 2);
}

int divi (int a, int b)
{
    return mult (a, inv (b));
}

int chooseInternal (int n, int k)
{
    if (n < k || k < 0)
        return 0;
        
    if (k == klast)
    {
        if (nlast == n + 1)
        {
            //cout << n << " " << k << " " << nlast << " " << mult (divi (rlast, n + 1), n - k + 1) << "\n";
            return mult (divi (rlast, n + 1), n - k + 1);
        }
        else if (nlast == n - 1)
        {
            //cout << n << " " << k << " " << nlast << " " << mult (divi (rlast, n - k), n) << "\n";
            return mult (divi (rlast, n - k), n);
        }
    }
    
    int res = 1;
    for (int i = n; i > n - k; i--)
        res = mult (res, i);
    for (int i = 1; i <= k; i++)
        res = divi (res, i);
    
    //cout << n << " " << k << " " << res << "\n";
    return res;
}

int choose (int n, int k)
{
    int res = chooseInternal (n, k);
    if (res == 0)
        return res;
    
    nlast = n, klast = k;
    return rlast = res;
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        char ch;
        cin >> ch;
        dig[i] = (int) ch - '0';
    }
    
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        //cout << dig[i] << " " << choose (i, K) << endl;
        res = add (res, mult (dig[i], mult (pow (10, N - 1 - i), choose (i, K))));
        //cout << res << endl;
    }
    
    int tsum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        tsum += dig[i];
        res = add (res, mult (tsum, mult(pow (10, N - 2 - i), choose (i, K - 1))));
        
        //cout << res << endl;
        //cout << tsum << " " << mult(pow (10, N - 2 - i), choose (i, K - 1)) << endl;
    }
    cout << res << "\n";
    //system ("Pause");
    return 0;
}