#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
const int NICO = 1000 + 10;
ll n, m, k, x, y;
ll mp[1000][1000];
int main()
{
    cin >> n >> m >> k >> x >> y;
    ll a, b, c;
    if(n != 1)
    {
        ll t = 2 * m * n - 2 * m;
        ll d = k / t; 
        ll r = k % t;
        ll cnt = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i==1||i==n) mp[i][j] = d;
                else mp[i][j] = 2*d;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(cnt > r) break;
                cnt++;
                mp[i][j]++;
            }
        }
        for(int i=n-1;i>=1;i--)
        {
            for(int j=1;j<=m;j++)
            {
                if(cnt > r) break;
                cnt++;
                mp[i][j]++;
            }
        }
        ll maxc = 0, minc = 1e18;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(mp[i][j] < minc) minc = mp[i][j];
                if(mp[i][j] > maxc) maxc = mp[i][j];
            }
        }
        a = maxc, b = minc, c = mp[x][y];
    } else {
        a = (k + m - 1) / m;
        b = k / m;
        if(y > (k%m)) c = b;
        else c = a;
    }
    cout << a << " " << b << " " << c << endl;
}