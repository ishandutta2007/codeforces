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

int a[MAXN];
int b[MAXN];

int ans[MAXN][2];
int ns;

void apply(int st, int ed)
{
    //printf("apply %d %d\n", st, ed);
    for (int i = st; i <= (st + ed) / 2; i++)
    {
        swap(a[i], a[st+ed-i]);
    }
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
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
        }

        ns = 0;
        bool ok = true;
        if (a[0] != b[0])
        {
            printf("NO\n");
            continue;
        }

        for (int i = 1; i < n; i++)
        {
#if 0
            printf("%d:", i);
            for (int j = 0; j < n; j++) printf(" %d", a[j]);
            printf("\n");
#endif

            if (a[i] == b[i])
            {
                continue;
            }
            int v1=a[i-1], v2=b[i];
            bool found = false;

            int num_pairs=0;
            map<int,int> before, after;

            before[a[i-1]]++;
            for (int j = i+1; j<n; j++)
            {
                after[a[j]]++;
                if (a[j] == a[i-1])
                {
                    num_pairs++;
                }
            }

            for (int j = i; j < n-1; j++)
            {
                if (a[j] == v2 && a[j+1] == v1)
                {
                    ans[ns][0] = i;
                    ans[ns][1] = j+1;
                    apply(i-1,j+1);
                    ns++;
                    found = true;
                    break;
                }
                //printf("p %d %d\n", j, num_pairs);
                if (a[j] == v1 && a[j+1] == v2)
                {
                    if (num_pairs > 0)
                    {
                        int k1=-1,k2=-1;
                        for (int k = i-1; k < j ; k++)
                        {
                            if (after[a[k]] > 0)
                            {
                                k1 = k;
                                break;
                            }
                        }
                        for (int k = j+1; k < n; k++)
                        {
                            if (a[k1] == a[k])
                            {
                                k2 = k;
                                break;
                            }
                        }

                        ans[ns][0] = k1+1;
                        ans[ns][1] = k2;
                        ns++;
                        apply(k1,k2);

                        ans[ns][0] = i;
                        ans[ns][1] =  k1+k2-j;
                        apply(i-1,k1+k2-j);
                        ns++;
                        found = true;
                        break;
                    }
                }
                if (j < n-1)
                {
                    num_pairs -= before[a[j+1]];
                    after[a[j+1]]--;
                }
                num_pairs += after[a[j]];
                before[a[j]]++;
            }
            if (!found)
            {
                ok = false;
                break;
            }
        }
        if (!ok)
        {printf ("NO\n");}
        else
        {
            printf("YES\n%d\n", ns);
            for (int i = 0; i < ns; i++)
            {
                printf("%d %d\n", ans[i][0], ans[i][1]+1);
            }
        }
    }

    return 0;
}