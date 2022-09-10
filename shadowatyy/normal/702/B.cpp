#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000000
#define INF 1000000000000000000LL
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PIC pair<int, char>
#define VI vector<int>
#define VLL vector<ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_backA
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORD(x, y, z) for(int x = y; x >= (z); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
using namespace std;

int n, l;

ll res;

map<int, int> M;

unsigned int pows[32];

int main()
{
    pows[0] = 1;

    for(int i = 1; i < 32; ++i)
    {
        pows[i] = pows[i-1]*2;
    }

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    while(n--)
    {
        cin >> l;

        for(int i = 0; i < 32; ++i)
        {
            res += M[pows[i]-l];
        }

        ++M[l];
    }

    cout << res;
}