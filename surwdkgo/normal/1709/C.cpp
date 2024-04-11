#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cinttypes>
#include <cstring>

using namespace std;

#define MAXN 1000010
#define F first
#define S second

int64_t s64() { int64_t res; scanf("%" PRId64, &res); return res; }
void p64(int64_t res) { printf("%" PRId64, res); }

char inp[MAXN];
int sumF[MAXN][2];
int sumR[MAXN][2];

int clamp(int value)
{
    if (value < 0)
    {
        return value+2;
    }
    else return value;
}
int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        scanf("%s", inp);

        int n;
        n = strlen(inp);

        sumF[0][0] = sumF[0][1] = 0;
        for (int i = 0; i < n; i++)
        {
            if (inp[i] == '(')
            {
                sumF[i+1][0] = sumF[i][0] +1;
                sumF[i+1][1] = sumF[i][1] +1;
            }
            else if (inp[i] == ')')
            {
                sumF[i+1][0] = clamp(sumF[i][0]-1);
                sumF[i+1][1] = clamp(sumF[i][1]-1);
            }
            else
            {
                sumF[i+1][0] = sumF[i][0] +1;
                sumF[i+1][1] = clamp(sumF[i][1]-1);
            }
        }
        sumR[n][0] = sumR[n][1] = 0;
        for (int i = n-1; i >=0; i--)
        {
            if (inp[i] == ')')
            {
                sumR[i][0] = sumR[i+1][0] +1;
                sumR[i][1] = sumR[i+1][1] +1;
            }
            else if (inp[i] == '(')
            {
                sumR[i][0] = clamp(sumR[i+1][0]-1);
                sumR[i][1] = clamp(sumR[i+1][1]-1);
            }
            else
            {
                sumR[i][0] = sumR[i+1][0] +1;
                sumR[i][1] = clamp(sumR[i+1][1]-1);
            }
        }

        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            if (inp[i] == '?')
            {
                if (sumF[i+1][0] == sumF[i+1][1] || sumR[i][0] == sumR[i][1] ||
                    (i < n && (sumF[i][0] <= sumR[i+1][1] || sumF[i][1] >= sumR[i+1][0])))
                {
                }
                else
                {
                    ans = false;
                }
            }
        }
        printf("%s\n", ans ? "YES" : "NO");
    }

    return 0;
}