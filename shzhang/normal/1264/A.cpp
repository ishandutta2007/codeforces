#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define ll long long

int seq[400005];

int main()
{
    int t;
    scanf("%d", &t);
    int n;
    for (int data = 1; data <= t; data++) {
        scanf("%d", &n);
        int last = 0;
        int prev = -1;
        int silver_cnt = 0; int bronze_cnt = 0;
        int c;
        for (int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            if (a != prev) {
                last++;
            }
            seq[last]++; prev = a;
        }
        if (last < 3) goto fail;
        for (c = 2; c <= last; c++) {
            silver_cnt += seq[c]; if (silver_cnt > seq[1]) break;
        }
        c++;
        if (silver_cnt <= seq[1]) goto fail;
        for (; c <= last; c++) {
            if ((seq[1] + silver_cnt + bronze_cnt + seq[c]) * 2 > n) break;
            bronze_cnt += seq[c];
        }
        if (bronze_cnt <= seq[1]) goto fail;
        printf("%d %d %d\n", seq[1], silver_cnt, bronze_cnt); goto succeed;
    fail:
        printf("0 0 0\n");
    succeed:
        for (int i = 1; i <= last; i++) seq[i] = 0;
    }
    return 0;
}