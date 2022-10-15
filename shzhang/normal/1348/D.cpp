#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define ll long long

int ans[50];
int cnt[50];

int main()
{
    int t;
    scanf("%d", &t); cnt[0] = 1;
    for (int data = 1; data <= t; data++) {
        int n; scanf("%d", &n);
        if (n == 2) {
            printf("1\n0\n"); continue;
        }
        for (int nights = 1; ; nights++) {
            if ((1 << (nights + 1)) - 1 < n) continue;
            printf("%d\n", nights);
            int red = (1 << (nights + 1)) - 1 - n;
            //printf("red = %d\n", red);
            for (int i = 1; i <= nights; i++) ans[i] = (1 << (i - 1)), cnt[i] = cnt[i-1] + ans[i];
            for (int i = 1; i <= nights; i++) {
                int rval = (1 << (nights - i + 1)) - 1;
                //printf("%d ", rval);
                while (ans[i] && rval <= red) {
                    red -= rval;
                    ans[i]--; cnt[i]--;
                }
                for (int j = i + 1; j <= nights; j++) cnt[j] = cnt[j-1] * 2, ans[j] = cnt[j] - cnt[j-1];
            }
            //printf("newred = %d\n", red);
            for (int i = 1; i <= nights; i++) printf("%d ", ans[i]);
            printf("\n");
            break;
        }
    }
    return 0;
}