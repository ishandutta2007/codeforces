#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int NICO = 1002;
int n, m;
int mp[NICO][NICO];
int up[NICO][NICO], left_[NICO][NICO], right_[NICO][NICO], down[NICO][NICO];
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d", &mp[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            up[i][j] = up[i-1][j] + mp[i][j];
            left_[i][j] = left_[i][j-1] + mp[i][j];
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            down[i][j] = down[i+1][j] + mp[i][j];
            right_[i][j] = right_[i][j+1] + mp[i][j]; 
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]) continue;
            if(up[i][j]) res++;
            if(down[i][j])res++;
            if(left_[i][j])res++;
            if(right_[i][j])res++;
        }
    }
    cout << res << endl;
}