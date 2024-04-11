#include<bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define N 100005
#define pb push_back
#define F first
#define S second
int a[N], n, k, s[N], tot, now, sum;
int main ()
{
    scanf("%d %d", &n, &k);
    fo (i, 1, n)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum % k)
    {
        printf("No");
        return 0;
    }
    sum /= k;
    int j = 1;
    fo (i, 1, k)
    {
        int now = 0;
        while (j <= n && now + a[j] <= sum)
        {
            now = now + a[j];
            ++j;
        }
        if (now == sum)
        {
            s[i] = j - 1;
        }
        else
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes\n");
    fo (i, 1, k)
        printf("%d ", s[i] - s[i - 1]);
    return 0;
}