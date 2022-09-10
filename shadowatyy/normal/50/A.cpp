#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;

    res += (n/2)*m;

    if(n%2)
    {
        res += m/2;
    }

    cout << res;
}