#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 52
using namespace std;
int N, M;
char grid[MAXN][MAXN];
int a[4];
int s1, s2, e1, e2;
string s;
int ans;
int cur, x, y;
bool test()
{
    x = s1; y = s2;
    for(int i=0; i<s.length(); i++)
    {
        cur = s[i] - '0';
        if(a[cur]==0)
        {
            ++x;
        }
        if(a[cur]==1)
        {
            --x;
        }
        if(a[cur]==2)
        {
            ++y;
        }
        if(a[cur]==3)
        {
            --y;
        }
        if(x<0||y<0||x>=N||y>=M)
        {
            return false;
        }
        if(grid[x][y]=='#')
        {
            return false;
        }
          if(x==e1&&y==e2)
        {
            return true;
        }
    }
        return false;
}
int main()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='S')
            {
                s1 = i; s2 = j;
            }
            if(grid[i][j]=='E')
            {
                e1 = i; e2 = j;
            }
        }
    }
    cin>>s;
    for(int i=0; i<4; i++)
    {
        a[i] = i;
    }
    do
    {
        if(test())
        {
            ans++;
        }
    } while(next_permutation(a, a+4));
    cout<<ans<<endl;
}