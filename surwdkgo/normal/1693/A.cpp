#include <cstdio>

int can;

int main()
{
    scanf("%d", &can);
    for (int cas = 0; cas < can ; cas++)
    {
        int n;
        long long sum = 0;
        bool ans = true;
        bool hadz = false;
        scanf("%d", &n);
        for (int i = 0; i <n ; i++)
        {
            int x;
            scanf("%d", &x);
            sum += x;
            if (sum < 0) ans = false;
            if (sum == 0) hadz = true;
            if (hadz && sum != 0) ans = false;

        }
        if (sum != 0) ans = false;

        printf("%s\n", ans ? "Yes" : "No");
    }

    return 0;
}