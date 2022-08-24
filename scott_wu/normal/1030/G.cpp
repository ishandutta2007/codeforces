#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const int MAXP = 2000100;
const ll MOD = 1e9 + 7;

int N;
int pprime[MAXP];
int arr[MAXN];
int pord[MAXN];

map <int, int> pv;
map <int, int> nd;
int nvp[MAXP];
int nf[MAXP];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N;
    for (int i = 2; i < MAXP; i++)
    {
        if (!pprime[i])
        {
            pprime[i] = i;
            for (int j = i; j < MAXP; j += i)
                pprime[j] = i;
        }
    }

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr, arr + N);
    reverse (arr, arr + N);

    int r = 0;
    for (int i = 0; i < N; i++)
    {
        int cp = arr[i];
        bool gadd = false;
        if (pv.find(cp) != pv.end())
        {
            cp--;
            while (cp > 1)
            {
                int np = pprime[cp], nc = 0;
                while (cp % np == 0)
                {
                    cp /= np;
                    nc++;
                }
                pv[np];
                if (pv[np] < nc)
                {
                    pv[np] = nc;
                    nd[np] = 1;
                    gadd = true;
                }
                else if (pv[np] == nc)
                    nd[np]++;
            }
            pord[i] = arr[i] - 1;
        }
        else
        {
            pv[cp] = 1;
            nd[cp] = 1;
            gadd = true;
            pord[i] = arr[i];
        }
        if (!gadd)
            r = 1;
    }
    for (pair <int, int> ppair : pv)
    {
        nvp[ppair.first] = ppair.second;
    }

    for (int i = 0; i < N; i++)
    {
        int cp = pord[i];

        bool gadd = false;
        while (cp > 1)
        {
            int np = pprime[cp], nc = 0;
            while (cp % np == 0)
            {
                cp /= np;
                nc++;
            }
            if (pv[np] == nc && nd[np] == 1) gadd = true;
        }
        if (!gadd) r = 1;
    }

    ll res = 1;
    for (pair <int, int> ppair : pv)
    {
        for (int i = 0; i < ppair.second; i++)
            res = (res * ppair.first) % MOD;
    }
    cout << (res + r) % MOD << "\n";
}