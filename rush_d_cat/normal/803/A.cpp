#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n, k;
int a[102][102];
int main()
{
    cin >> n >> k;
    int ok = 1;
    for(int i=1;i<=n;i++)
    {
        if(k == 0) break;
        for(int j=1;j<=n;j++)
        {
            if(a[i][j] == 1) continue;
            if(k == 0) break;
            if(i == j)
            {
                k -= 1;
                a[i][j] = a[j][i] = 1;
            } else {
                if(k >= 2) 
                {
                    k -= 2; a[i][j] = a[j][i] = 1;
                }
            }
            if(k == 0) break;
            
        }
        if(k == 0) break;
        
    }
    if(k != 0) ok = 0;
    if(ok == 0)
    {
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d", a[i][1]);
        for(int j=2;j<=n;j++)
        {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }
}