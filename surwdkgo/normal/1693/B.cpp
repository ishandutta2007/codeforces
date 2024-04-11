#include <cstdio>
#include <cstdint>
#include <algorithm>

int p[1000010];
int l[1000010];
int r[1000010];
int64_t sub[1000010];

int main()
{
    int can;
    scanf("%d", &can);
    for (int cas = 0 ; cas < can; cas++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n-1; i++)
        {
            scanf("%d", &p[i+1]);
            p[i+1]--;
        }
        p[0] = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &l[i], &r[i]);
            sub[i] = 0;
        }

        int ans = 0;
        for (int i = n-1; i>=0; i--)
        {
            //printf("%ld\n", sub[i]);
            if (sub[i] >= l[i])
            {
                int tos = std::min<int64_t>(sub[i], r[i]);
                sub[p[i]] += tos;
            }
            else
            {
                ans++;
                sub[p[i]] += r[i];
                //printf("%d %ld\n", p[i], sub[p[i]]);
            }

        }

        printf("%d\n", ans);

    }
    return 0;
}