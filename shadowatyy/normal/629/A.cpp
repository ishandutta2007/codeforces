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
using namespace std;

int n, res;

char c;

int x[107];
int y[107];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cin >> c;

            if(c=='C')
            {
                res -= y[i]*(y[i]-1)/2;

                y[i]++;

                res += y[i]*(y[i]-1)/2;

                res -= x[j]*(x[j]-1)/2;

                x[j]++;

                res += x[j]*(x[j]-1)/2;
            }
        }
    }

    cout << res;
}