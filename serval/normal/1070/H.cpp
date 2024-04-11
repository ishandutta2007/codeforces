#include<bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define N 100005
#define pb push_back
#define F first
#define S second
#define ll long long
int sum, len, n, q;
char s[10005][9], s1[9];
ll now;
std::map<ll, ll> mp, f;
int main ()
{
    scanf("%d", &n);
    fo (i, 1, n)
    {
        scanf("%s", s[i] + 1);
        len = strlen(s[i] + 1);
        fo (k, 1, len)
        {
            now = 0;
            fo (j, k, len)
            {
                now = (now << 7) + (ll) s[i][j];
                if (f[now] != i)
                    ++mp[now];
                f[now] = i;
            }
        }
    }
    scanf("%d", &q);
    fo (i, 1, q)
    {
        scanf("%s", s1 + 1);
        len = strlen(s1 + 1);
        now = 0;
        fo (j, 1, len)
            now = (now << 7) + (ll) s1[j];
        sum = mp[now];
        printf("%d ", sum);
        if (sum)
            printf("%s\n", s[f[now]] + 1);
        else
            printf("-\n");
    }
    return 0;
}