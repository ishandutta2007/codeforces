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
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORD(x, y, z) for(int x = y; x >= (z); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
using namespace std;

int n;

int main()
{
    cin >> n;

    for(int i = 1; i < n; ++i)
    {
        if(i%2)
        {
            cout << "I hate that ";
        }
        else
        {
            cout << "I love that ";
        }
    }

    if(n%2==1)
    {
        cout << "I hate it";
    }
    else
    {
        cout << "I love it";
    }
}