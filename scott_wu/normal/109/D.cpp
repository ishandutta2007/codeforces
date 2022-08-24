#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll MAXN = 100100;
const ll AA = 1000000;

ll n;
ll num[MAXN];
ll snum[MAXN];
ll nused[MAXN];
ll loc[MAXN]; // given snum gives num
ll l[2 * MAXN], r[2 * MAXN];

bool lucky (ll x)
{
    while (x > 0)
    {
        if ((x % 10 != 4) && (x % 10 != 7))
            return false;
        x /= 10;
    }
    return true;
}

ll findloc (ll x)
{
    ll lo = 0, hi = n - 1;
    while (lo < hi)
    {
        ll mid = (lo + hi) / 2;
        if (x > snum[mid])
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

int main()
{
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> num[i];
        num[i] *= AA;
        snum[i] = num[i];
    }
    sort (snum, snum + n);
    /*for (ll i = 0; i < n; i++)
        cout << snum[i] << "\n";*/
    for (ll i = 0; i < MAXN; i++)
        nused[i] = 0;
    for (ll i = 0; i < n; i++)
    {
        ll lo = findloc (num[i]);
        //cout << num[i] << " " << lo << "\n";
        loc[lo+nused[lo]] = i;
        num[i] += nused[lo];
        nused[lo]++;
    }
    for (int i = 0; i < MAXN; i++)
    {
        if (nused[i])
        {
            for (int j = i + 1; j < i + nused[i]; j++)
                snum[j] += j - i;
            i += nused[i] - 1;
        }
    }
    ll lnum = -1; // pivot val
    for (ll i = 0; i < n; i++)
        if (lucky (num[loc[i]] / AA) && (nused[i] > 0))
        {
            lnum = i;
            break;
        }
    if (lnum == -1)
    {
        bool check = true;
        for (ll i = 0; i < n - 1; i++)
            if (num[i] > num[i+1])
                check = false;
        if (check)
        {
            cout << "0\n";
            return 0;
        }
        else
        {
            cout << "-1\n";
            return 0;
        }
    }
    /*for (ll i = 0; i < 7; i++)
        cout << num[i] << " " << snum[i] << "\n";*/
    ll k = 0;
    ll cur = 0;
    /*for (ll i = 0; i < n; i++)
        cout << loc[i] << " ";
    cout << "\n";*/
    while (cur < n)
    {
        //cout << lnum << "    " << loc[lnum] << "\n";
        if (cur == lnum)
        {
            cur++;
            continue;
        }
        if (loc[lnum] != cur)
        {
            l[k] = loc[lnum];
            r[k] = cur;
            k++;
            /*for (ll i = 0; i < n; i++)
                cout << num[i] / AA << " ";
            cout << "\n";
            cout << (num[loc[lnum]] / AA) << " " << (num[cur] / AA) << "\n";*/
            swap (num[loc[lnum]], num[cur]);
            swap (loc[lnum], loc[findloc(num[loc[lnum]])]);
        }
        if (loc[cur] != cur)
        {
            l[k] = loc[cur]; r[k] = cur; // loc[lnum] = cur, loc[cur]
            k++;
            /*for (ll i = 0; i < n; i++)
                cout << num[i] / AA << " ";
            cout << "\n";
            cout << num[loc[cur]] / AA << " " << num[cur] / AA << "\n";*/
            swap (num[cur], num[loc[cur]]);
            swap (loc[lnum], loc[cur]);
        }
        cur++;
    }
    /*for (ll i = 0; i < n; i++)
        cout << num[i] << " ";
    cout << "\n";*/
    cout << k << "\n";
    for (ll i = 0; i < k; i++)
        cout << l[i] + 1 << " " << r[i] + 1 << "\n";
    //system ("Pause");
    return 0;
}