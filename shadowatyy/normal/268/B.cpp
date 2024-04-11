#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, res = 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    for(int i = 2; i <= n; i++)
    {
        res += (n-i+1)*(i-1)+1;
    }

    cout << res;
}