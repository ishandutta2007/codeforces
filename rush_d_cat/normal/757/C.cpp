#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int NICO = 1000000 + 10;
const int MOD = 1e9 + 7;
int n, m, g, x;
vector<int> a[NICO];
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &g);
        for(int j=1;j<=g;j++)
        {
            scanf("%d", &x);
            a[x].push_back(i);
        }   
    }
    sort(a+1, a+1+m);
    int res = 2;long long ans = 1;
    for(int i=2;i<=m;i++)
    {
        if(a[i] == a[i-1]) ans = ans * res % MOD, ++res;
        else res = 2;
    }
    cout << ans << endl;
}