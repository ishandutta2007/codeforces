#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define REP(x, y) for(int x = 0; x < (y); ++x)
using namespace std;

int n, m;

char c;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;

    REP(i, n) REP(j, m)
    {
        cin >> c;

        if(c=='C' || c=='M' || c=='Y')
        {
            cout << "#Color";
            return 0;
        }
    }

    cout << "#Black&White";
}