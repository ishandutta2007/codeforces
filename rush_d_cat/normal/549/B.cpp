#include <iostream>
#include <vector>
using namespace std;

int n;
char s[102][102];
int G[102][102], a[102];
vector<int> res;

int main()
{
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++)
    {
        scanf("%s", s[i] + 1);
    }

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            G[i][j] = s[i][j] == '1' ? 1 : 0;
        }
    }

    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
    }

    while (1)
    {

        int can_break = 1;
        for (int i = 1; i <= n; i ++)
        {
            if (a[i] == 0)
            {
                res.push_back(i); a[i] = -1;
                for (int j = 1; j <= n; j ++)
                {
                    if (G[i][j])
                        a[j] --;
                }

                can_break = 0;
            }
        }


        if (can_break) break;

    }

    printf("%d\n", res.size());

    for (int i = 0; i < res.size(); i ++)
    {
        printf("%d ", res[i]);
    }

}