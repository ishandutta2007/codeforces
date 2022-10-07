#pragma GCC optimize "-Ofast"
#include<bits/stdc++.h>
using namespace std;
vector<long long> p[2],P[2];
long long MAX = 2e18;
void dfs(int x, long long L, int i)
{
    if( x == p[i].size() )
    {
        P[i].push_back(L);
        return;
    }
    while (true)
    {
        if ( L > MAX ) break;
        dfs( x+1, L , i);
        if ( L > MAX / p[i][x]) break;
        L *= p[i][x];
    }
}
long long M (long long x, long long y)
{
    if(x > MAX/y) return MAX;
    return x*y;
}
long long cnt (long long x)
{
    int j = P[1]. size()-1;
    long long ans = 0;
    for (int i = 0; i < P[0] . size(); i++)
    {
        while( j >= 0 && M(P[1][j], P[0][i]) > x ) j--;
        ans += j + 1;
    }
    return ans;
}
main()
{
    int n;
    long long k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i < 5)
        p[0].push_back(x);
        else
        p[1].push_back(x);
    }
    cin >> k;

    dfs(0, 1, 0);
    dfs(0, 1, 1);
    sort (P[0].begin(), P[0].end());
    sort (P[1].begin(), P[1].end());
    long long l=0, r = MAX;
    while(l < r)
    {
        long long  mid = (l + r)/2;
        if (cnt(mid) >= k) r = mid;
        else l = mid + 1;

    }
    cout << l << endl;
}