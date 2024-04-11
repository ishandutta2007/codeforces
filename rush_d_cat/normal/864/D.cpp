#include <iostream>
using namespace std;
#define Nico (200000+10)

int n, a[Nico], cnt[Nico], vis[Nico];

int need[Nico], c = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]); cnt[a[i]] ++;
    }
    for (int i = 1; i <= n; i ++) {
        if (cnt[i] == 0) need[++c] = i;
    }
    
    int cur = 1, ans = 0;

    for (int i = 1; i <= n; i ++) 
    {
        if (cnt[ a[i] ] > 1) 
        {
            if ( need[cur] < a[i] || vis[ a[i] ]) 
            {
                cnt[ a[i] ] --;
                a[i] = need[cur]; 
                ans ++; cur ++; 
            } else {
                vis[ a[i] ] = 1;
            } 

        }
    }

    printf("%d\n", ans);
    for (int i = 1; i <= n; i ++) {
        printf("%d ", a[i]);
    }
}