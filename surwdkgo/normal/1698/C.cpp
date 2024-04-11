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
int test[MAXN];

int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        int n;
        scanf("%d", &n);
        for (int i =0 ; i<n; i++)
        {
            scanf("%d", &inp[i]);
        }
        int pos=0, neg=0;

        for (int i =0; i<n;i++)
        {
            if (inp[i] > 0)pos++;
            if(inp[i] < 0)neg++;
        }

        if(pos >=3 || neg >=3)
        {
            printf("NO\n");
            continue;
        }

        int zero=0,testN=0;

        for (int i =0; i<n;i++)
        {
            if (inp[i] ==0)
            {
                if (zero >=3)continue;
                zero++;
                test[testN++]=inp[i];
            }
            else
            {
                test[testN++]=inp[i];
            }
        }

        bool ans = true;
        for (int i = 0; i <testN;i++)
        {
            for(int j =i+1; j<testN; j++)
            {
                for (int k=j+1; k<testN; k++)
                {
                    bool found = false;
                    for (int l=0; l<testN; l++)
                    {
                        if (test[i]+test[j]+test[k]==test[l])
                        {found=true;
                            break;
                        }
                    }
                    if(!found)
                    {
                        ans=false;
                        goto out;
                    }
                }
            }
        }
out:
        printf("%s\n", ans ? "YES" : "NO");

    }

    return 0;
}