#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

typedef long long li;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int val[200000];
int p[1000];

int main()
{
    
    int n;
    li sum = 0;
    int cnt = 1;
    scanf("%d", &n);
    int m = sqrt(n + 0.0);
    forn (i, n)
    {
        int t;
        scanf("%d", &t);
        if(t == 1)
        {
            int a, x;
            a = min(a, cnt);
            scanf("%d%d", &a, &x);
            int l = 0;
            sum += a * x;
            while(l < a)
            {
                while(l % m == 0 && l + m < a)
                {
                    p[l / m] += x;
                    l += m;
                }
                while(l < a)
                    val[l++] += x;
            }
        }
        if(t == 2)
        {
            int a;
            scanf("%d", &a);
            sum += a;
            val[cnt++] += a;
        }
        if(t == 3)
        {
            cnt--;
            sum -= val[cnt] + p[cnt / m];
            val[cnt] = -p[cnt / m];
        }
        printf("%.10lf\n", 1.0 * sum / cnt);
    }

    return 0;
}