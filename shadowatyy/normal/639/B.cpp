#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
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
#define eb emplace_back
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORD(x, y, z) for(int x = y; x >= (z); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
using namespace std;

int n, d, h, c = 1;

int main()
{
    cin >> n >> d >> h;

    if(2*h<d)
    {
        cout << -1;
        return 0;
    }

    if(h>d)
    {
        cout << -1;
        return 0;
    }

    if(n>2 && d==1)
    {
        cout << -1;
        return 0;
    }

    if(d!=h)
    {
        for(int i = 1; i <= h; ++i)
        {
            cout << i << " " << c+1 << endl;

            ++c;
        }

        if(d!=h)
        {
            cout << 1 << " " << c+1 << endl;

            ++c;
        }

        for(int i = 2; i <= d-h; ++i)
        {
            cout << c << " " << c+1 << endl;

            ++c;
        }

        for(int i = d+1; i < n; ++i)
        {
            cout << 1 << " " << c+1 << endl;

            ++c;
        }
    }
    else
    {
        for(int i = 1; i <= h; ++i)
        {
            cout << i << " " << c+1 << endl;

            ++c;
        }


        for(int i = d+1; i < n; ++i)
        {
            cout << 2 << " " << c+1 << endl;

            ++c;
        }
    }


}