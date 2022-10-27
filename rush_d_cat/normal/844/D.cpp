#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;
int n, start, x;
int val, nxt, new_start;
int mx = 0;
int q[1002];


int main()
{
    scanf("%d %d %d", &n, &start, &x);

    for(int i = 1; i <= 1000; i ++)
    {
        q[i] = i * i % n + 1;
    }
    
    new_start = start;
    
    for (int i = 1; i <= 1000; i ++)
    {
        printf("? %d\n", q[i]);
        fflush(stdout);
        scanf("%d %d", &val, &nxt);
        
        if (val <= x && val > mx)
        {
            mx = val;
            new_start = q[i];
        }
    }

    int now = new_start;
    for (int i = 1; i <= 999; i ++)
    {
        printf("? %d\n", now);
        fflush(stdout);
        scanf("%d %d", &val, &nxt);
        now = nxt;
        if (val >= x)
        {
            printf("! %d\n", val);
            fflush(stdout);
            return 0;
        }
        if(nxt == -1) break;
    }

    printf("! %d\n", -1);
    fflush(stdout);
}