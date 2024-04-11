#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int MAXN = 1000100;
 
int N;
int arr[MAXN];
 
ll gogo (ll x)
{
    ll cv = 0;
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        cv = (cv + arr[i]) % x;
        ans += min (cv, x - cv);
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    scanf ("%d", &N);
    ll csum = 0;
    for (int i = 0; i < N; i++)
    {
        scanf ("%d", arr + i);
        csum += arr[i];
    }
 
    vector <ll> v;
    for (ll i = 2; i * i <= csum; i++)
    {
        if (csum % i == 0)
        {
            v.push_back(i);
            while (csum % i == 0)
                csum /= i;
        }
    }
    if (csum > 1)
        v.push_back(csum);
 
 
    ll ans = 3e18;
    for (ll f : v)
        ans = min (ans, gogo(f));
    if (ans > 2e18)
        ans = -1;
    printf ("%I64d\n", ans);
}