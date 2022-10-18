#include <cstdio>

int main()
{
    int inp[1010];
    int can;
    int use[1010];
    int ans[1010];
    int n;

    scanf("%d", &can);
    for (int cas = 0; cas < can; cas++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &inp[i]);
            inp[i]--;
            use[i] = 0;
        }

        if (n == 1)
        {
            printf("-1\n");
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            int found = -1;
            for (int j = 0; j < n; j++)
            {
                if (!use[j] && j != inp[i])
                {
                    found = j;
                    break;
                }
            }

            if (found != -1)
            {
                ans[i] = found;
                use[found] = 1;
            }
            else
            {
                ans[i] = ans[i-1];
                ans[i-1] = inp[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d%c", ans[i]+1, i == n-1 ? '\n' : ' ');
        }
    }
    return 0;
}