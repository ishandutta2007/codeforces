#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
ll D, S, space;
vector <ll> carry;
vector <ll> ncarry;
ll ans, fuel, ans2, fuel2;
int skip;

int main()
{
    cin >> N >> D >> S;
    space = 1, skip = -1;
    for (int i = 0; i < N; i++)
    {
        ll c, f, l;
        cin >> c >> f >> l;
        if (l < D)
            f = S + 1;
        if (c > 0)
        {
            carry.push_back (f);
            space += c - 1;
        }
        ncarry.push_back (f);
    }
    sort (carry.begin(), carry.end());
    sort (ncarry.begin(), ncarry.end());
    
    if (carry.size() > 0)
    {
        for (int i = 0; i < ncarry.size(); i++)
            if (ncarry[i] == carry[0])
            {
                skip = i;
                break;
            }
    }
    
    ans = fuel = ans2 = fuel2 = 0;
    for (int i = 0; i < ncarry.size(); i++)
    {
        if (fuel + ncarry[i] <= S)
        {
            fuel += ncarry[i];
            ans++;
        }
    }
    
    if (carry.size() > 0 && carry[0] <= S)
    {
        fuel2 = carry[0], ans2 = min (space + carry.size(), (ll) N);
        for (int i = 0; i < ncarry.size(); i++)
        {
            if (ans2 == N) break;
            if (i == skip) continue;
            if (fuel2 + ncarry[i] <= S)
            {
                fuel2 += ncarry[i];
                ans2++;
            }
        }
        /*fuel2 = carry[0]; ans2 = min (space + carry.size(), (ll) N);
        for (int i = 0; i < ncarry.size() - space; i++)
        {
            if (fuel2 + ncarry[i] <= S)
            {
                fuel2 += ncarry[i];
                ans2++;
            }
        }*/
        if (ans < ans2 || ((ans == ans2) && (fuel > fuel2)))
        {
            ans = ans2;
            fuel = fuel2;
        }
    }
    cout << ans << " " << fuel << "\n";
    //system ("Pause");
    return 0;
}