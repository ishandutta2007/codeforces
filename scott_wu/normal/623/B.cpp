#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N, A, B;
int arr[MAXN];
int tval[MAXN];
set <int> pfac;

void run (int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            pfac.insert(i);
        while (x % i == 0)
            x /= i;
    }
    if (x > 1)
        pfac.insert(x);
}

ll solve (int x)
{
    int mlo = N, mhi = -1;
    for (int i = 0; i < N; i++)
    {
        int k = (arr[i] + 1) % x;
        if (k == 1) tval[i] = 0;
        else if (k == 0 || k == 2) tval[i] = 1;
        else
        {
            mlo = min (mlo, i);
            mhi = max (mhi, i);
        }
    }
    
    ll tot = 0;
    for (int i = 0; i < N; i++)
    {
        if (i >= mlo && i <= mhi)
            tot += A;
        else tot += B * tval[i];
    }
    
    if (mlo < N)
    {
        ll bhi = 0, btot = 0;
        for (int i = mhi + 1; i < N; i++)
        {
            btot += A - tval[i] * B;
            bhi = min (bhi, btot);
        }
        ll blo = 0;
        btot = 0;
        for (int i = mlo - 1; i >= 0; i--)
        {
            btot += A - tval[i] * B;
            blo = min (blo, btot);
        }
        
        return tot + blo + bhi;
    }
    else
    {
        ll bans = 0, bhi = 0, btot = 0;
        for (int i = 0; i < N; i++)
        {
            btot += A - tval[i] * B;
            bans = min (bans, btot - bhi);
            bhi = max (bhi, btot);
        }
        return tot + bans;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> A >> B;
    
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    pfac.clear();
    for (int i = -1; i <= 1; i++)
    {
        run (arr[0] + i);
        run (arr[N-1] + i);
    }
    
    ll ans = 1e17;
    for (set<int>::iterator it = pfac.begin(); it != pfac.end(); it++)
        ans = min (ans, solve (*it));
    
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}