#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int NICO = 102;
char mp[NICO][NICO];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> mp[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j] == '-') 
                printf("-");
            else
                printf("%c",(i+j)%2?'B':'W');
            printf("%s",j==m?"\n":"");
        }
    }
}