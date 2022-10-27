#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int n;
int a[1002][6];
int dis[1002][1002];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= 5; j ++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 1; i <= n; i ++) 
    {
        for (int j = 1; j <= n; j ++)
        {
            for (int k = 1; k <= 5; k ++)
            {
                dis[i][j] += (a[i][k] - a[j][k]) * (a[i][k] - a[j][k]);
            }
        }
    }

    vector<int> ans;

    for (int i = 1; i <= n; i ++)
    {
        int ok = 1;

        for (int j = 1; j <= n; j ++)
        {
            if(i == j) continue;

            for (int k = 1; k <= n; k++)
            {
                if(i == k || j == k) continue;

                if (dis[i][j] + dis[i][k] > dis[j][k])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok == 0)
            {
                break;
            }
        }

        if(ok) 
        {
            ans.push_back(i);
        }
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i ++)
    {
        printf("%d\n", ans[i]);
    }
}