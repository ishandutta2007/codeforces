#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll CPOW = 1007;

int N, M;
int a[MAXN], b[MAXN];

ll chash[26][MAXN], hash2[26][MAXN];
ll ohash[26], ohash2[26];
ll mpow[MAXN], mpow2[MAXN];

vector <pair <ll, ll> > cleft, cright;

ll mmod (ll x, ll y)
{
    return ((x % y) + y) % y;
}

vector <int> res;

bool works (int loc)
{
    ll x[26], y[26];
    for (int i = 0; i < 26; i++)
    {
        x[i] = chash[i][loc] * MOD2 + hash2[i][loc];
        y[i] = ohash[i] * MOD2 + ohash2[i];
        
        //cout << loc << " " << x[i] << " " << y[i] << "\n";
    }
    
    sort (x, x + 26);
    sort (y, y + 26);
    for (int i = 0; i < 26; i++)
        if (x[i] != y[i])
            return false;
    
    for (int i = 0; i < 26; i++)
    {
        x[i] = chash[i][loc] * MOD2 + hash2[i][loc];
        y[i] = ohash[i] * MOD2 + ohash2[i];
    }
    for (int i = 0; i < 26; i++)
    {
        if (x[i] == 0) continue;
        for (int j = 0; j < 26; j++)
            if (x[i] == y[j] && y[i] != x[j])
            {
                //cout << i << " " << j << "\n";
                return false;
            }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        char ch;
        cin >> ch;
        a[i] = (ch - 'a');
    }
    
    for (int i = 0; i < M; i++)
    {
        char ch;
        cin >> ch;
        b[i] = (ch - 'a');
    }
    
    mpow[0] = mpow2[0] = 1;
    for (int i = 0; i < N + 100; i++)
    {
        mpow[i+1] = (mpow[i] * CPOW) % MOD;
        mpow2[i+1] = (mpow2[i] * CPOW) % MOD2;
    }
    
    for (int i = 0; i < 26; i++)
    {
        ohash[i] = ohash2[i] = 0;
        for (int j = 0; j < M; j++)
        {
            int x = ((b[j] == i) ? 1 : 0);
            ohash[i] = ((ohash[i] * CPOW) + x) % MOD;
            ohash2[i] = ((ohash2[i] * CPOW) + x) % MOD2;
        }
        
        chash[i][0] = hash2[i][0] = 0;
        for (int j = 0; j < M; j++)
        {
            int x = ((a[j] == i) ? 1 : 0);
            chash[i][0] = ((chash[i][0] * CPOW) + x) % MOD;
            hash2[i][0] = ((hash2[i][0] * CPOW) + x) % MOD2;
        }
        
        for (int j = 1; j <= N - M; j++)
        {
            int x = ((a[j+M-1] == i) ? 1 : 0);
            ll nhash = (chash[i][j-1] * CPOW + x) % MOD;
            if (a[j-1] == i)
                nhash = mmod (nhash - mpow[M], MOD);
            chash[i][j] = nhash;
            
            nhash = (hash2[i][j-1] * CPOW + x) % MOD2;
            if (a[j-1] == i)
                nhash = mmod (nhash - mpow2[M], MOD2);
            hash2[i][j] = nhash;
        }
    }
    
    for (int i = 0; i <= N - M; i++)
        if (works (i))
            res.push_back (i + 1);
    
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << res[i];
    }
    cout << "\n";
    
    return 0;
}