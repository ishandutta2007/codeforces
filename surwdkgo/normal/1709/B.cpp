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

int64_t s64() { int64_t res; scanf("%" PRId64, &res); return res; }
void p64(int64_t res) { printf("%" PRId64, res); }

int inp[MAXN];
int64_t sumF[MAXN];
int64_t sumR[MAXN];

int main()
{
    int casN=1;
    for (int cas = 0; cas < casN; cas++)
    {
        int n, q;
        scanf("%d%d",&n,&q);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", & inp[i]);
            sumF[i] = 0;
            sumR[i] = 0;
        }
        sumF[n] = sumR[n] = 0;
        for (int i = 0; i < n-1; i++)
        {
            if (inp[i+1] < inp[i])
            {
                sumF[i+1] = inp[i+1] - inp[i];
            }
            else
            {
                sumR[i] = inp[i] - inp[i+1];
            }
        }

        for (int i = 0; i < n-1; i++)
        {
            sumF[i+1] += sumF[i];
        }
        for (int i = n-1 ; i > 0; i--)
        {
            sumR[i-1] += sumR[i];
        }

        for (int i = 0; i < q; i++)
        {
            int s,t;
            scanf("%d%d", &s,&t);
            s--;
            t--;
            int64_t ans;
            if (s < t)
            {
                ans = sumF[t] - sumF[s];
            }
            else
            {
                ans = sumR[t] - sumR[s];
            }
            p64(-ans);
            printf("\n");

        }


    }

    return 0;
}