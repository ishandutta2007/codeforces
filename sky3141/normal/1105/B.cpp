#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 200000 + 9;

int n, k;
int ans;
char str[MAXN];

int main()
{
    int cur, curans;
    scanf("%d%d", &n, &k);
    scanf("%s", str);
    for(char c = 'a'; c<='z'; ++c)
    {
        cur = 0;
        curans = 0;
        for(int i=0; i<n; ++i)
        {
            if(str[i] == c) ++cur;
            else cur = 0;
            if(cur == k)
            {
                cur = 0;
                ++curans;
            }
        }
        if(curans > ans) ans = curans;
    }
    printf("%d\n", ans);

    return 0;
}