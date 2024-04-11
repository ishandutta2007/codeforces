#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

#define MAXN 1000010
#define F first
#define S second

int inp[MAXN];
int tmp[MAXN];

int calc(int n)
{
#if 0
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", tmp[i], i == n-1 ? '\n' : ' ');
    }
#endif
    map<int, int> tre;
    for (int i = 0; i < n-1; i++)
    {
        tre[tmp[i]] = i;
    }

    bool mx = true;
    int ans = 0;
    int ed = n;

    while (tre.size() > 0)
    {
        ans++;
        auto iter = mx ? --tre.end() : tre.begin();

        int pos = iter->second;
//        printf("p%d\n", pos);
        if (pos == 0) break;
        for (int i = pos; i < ed; i++)
        {
            tre.erase(tmp[i]);
        }
        ed = pos;
        mx = !mx;
    }
    return ans;
}

int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &inp[i]);
        }
        if (n == 1)
        {
            printf("0\n");
            continue;
        }

        int ans = 1;
        bool first = true;
        for (int i = 0; i < n; i++)
        {
            if (inp[i] != 1 && inp[i] != n) continue;

            int tmpN;
            if (first)
            {
                tmpN = i+1;
                bool rev = inp[i] == n;

                for (int i = 0; i <tmpN; i++)
                {
                    tmp[i] = rev ? n - inp[i] : inp[i]-1;
                }
                first = false;
            }
            else
            {
                tmpN = n - i;
                bool rev = inp[i] == n;

                for (int i = 0; i <tmpN; i++)
                {
                    tmp[i] = rev ? n - inp[n - 1 - i] : inp[n-1-i]-1;
                }
            }
            ans += calc(tmpN);
        }

        printf("%d\n", ans);

    }

    return 0;
}