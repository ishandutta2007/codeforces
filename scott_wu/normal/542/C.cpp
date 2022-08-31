#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 210;

int N;
int arr[MAXN];
ll mdist, mult;
bool bad[MAXN];

ll gcd (ll a, ll b)
{
    if (b == 0) return a;
    return gcd (b, a % b);
}

ll lcd (ll a, ll b)
{
    ll g = gcd (a, b);
    return a / g * b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr[i]--;
    }
    
    mdist = 0, mult = 1;
    
    for (int i = 0; i < N; i++)
        bad[i] = false;
    
    for (int i = 0; i < N; i++)
    {
        int tot = 1, cloc = i;
        for (int j = 0; j < N; j++)
            cloc = arr[cloc];
        
        if (bad[cloc]) continue;
        
        int lval = cloc;
        bad[cloc] = true;
        cloc = arr[cloc];
        while (lval != cloc)
        {
            //cout << cloc << " 1\n";
            bad[cloc] = true;
            tot++;
            cloc = arr[cloc];
        }
        
        //cout << i << " " << tot << "\n";
        if (tot > 0)
            mult = lcd (mult, (ll) tot);
    }
    
    for (int i = 0; i < N; i++)
    {
        int tot = 0, cloc = i;
        while (!bad[cloc])
        {
            //cout << cloc << " 2\n";
            tot++;
            cloc = arr[cloc];
        }
        
        mdist = max (mdist, (ll) tot);
    }
    
    //cout << mdist << " " << mult << endl;
    
    ll res = (mdist / mult + 1) * mult;
    while (res >= mdist + mult)
        res -= mult;
    while (res < mult)
        res += mult;
    
    cout << res << "\n";
    return 0;
}