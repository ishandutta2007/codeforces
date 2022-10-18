#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cinttypes>

using namespace std;

#define MAXN 1000010
#define F first
#define S second

int inp[MAXN];
int pos[MAXN];
int neg[MAXN];
int sum[MAXN];
set<int> mSum;

void update(int p)
{
    int oldV = sum[p];
    int newV = pos[p] - neg[p];
    if (oldV == 0 && newV != 0)
    {
        mSum.insert(p);
    }
    else if (oldV != 0 && newV == 0)
    {
        mSum.erase(p);
    }

    sum[p] = newV;
}

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);

    int maxV = 0;
    for (int i =0; i < n; i++)
    {
        int v;
        scanf("%d", &v);
        inp[i] = v;
        pos[v]++;
        maxV = max(maxV, v);
    }

    for (int i = 0; i < maxV+50; i++)
    {
        pos[i+1] += pos[i]/2;
        pos[i] = pos[i] % 2;

        update(i);
    }

    for (int i = 0; i < q; i++)
    {
        int p, v2;
        scanf("%d%d", &p, &v2);
        p--;
        int v1 = inp[p];

        neg[v1]++;
        update(v1);
        int x = v1;
        while (neg[x] > 1)
        {
            neg[x+1] +=neg[x]/2;
            neg[x] = neg[x]%2;
            update(x+1);
            update(x);
            x++;
        }

        pos[v2]++;
        update(v2);
        x = v2;
        while (pos[x] > 1)
        {
            pos[x+1]+=pos[x]/2;
            pos[x]= pos[x]%2;
            update(x+1);
            update(x);
            x++;
        }

        inp[p] = v2;

        while (true)
        {
            x = *--mSum.end();
            if (sum[x-1] == -1)
            {
                pos[x]--;
                pos[x-1]++;
                neg[x-1]--;
                update(x);
                update(x-1);
            }
            else
            {
                break;
            }
        }

        //for(int i = 0; i < 10; i++) printf("%d ", sum[i]);
        //printf("\n");

        auto it = --mSum.end();
        int ans = *it;
        if (it != mSum.begin())
        {
            --it;
            if (sum[*it] < 0)
            {
                ans--;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}