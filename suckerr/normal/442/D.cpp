#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

const int MAXN = 1000005;

int n, tot, f[MAXN], father[MAXN], m1[MAXN], m2[MAXN], s1[MAXN], s2[MAXN];

int main()
{
    scanf("%d", &n);
    f[1] = 0;
    tot = 1;
    for (int i = 1; i <= n; i++)
    {
        int x, now;
        scanf("%d", &x);
        father[++tot] = x;
        m1[tot] = m2[tot] = 0;
        f[tot] = 1;
        now = tot;
        while (1)
        {
            int fnow = father[now], temp = f[fnow];
            temp = f[fnow];
            if (now == s1[fnow])
                m1[fnow] = f[now];
            else if (now == s2[fnow])
            {
                m2[fnow] = f[now];
                if (m2[fnow] > m1[fnow])
                    swap(m2[fnow], m1[fnow]), swap(s1[fnow], s2[fnow]);
            }
            
            else
            {
                if (f[now] > m2[fnow])
                    m2[fnow] = f[now], s2[fnow] = now;
                if (m2[fnow] > m1[fnow])
                    swap(m2[fnow], m1[fnow]), swap(s1[fnow], s2[fnow]);
            }
            
            if (fnow == 1)
            {
                f[1] = m1[fnow];
                break;
            }
            
            f[fnow] = max(m1[fnow], m2[fnow] + 1);
            if (f[fnow] == temp)
                break;
            else
                now = fnow;
        }
        
        if (i == n)
            printf("%d\n", f[1]);
        else
            printf("%d ", f[1]);
    }
    
    return 0;
}