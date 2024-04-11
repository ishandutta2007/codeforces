#include <cstdio>

using namespace std;

int n;
int s[400005];
int number[400005][18];
int candies[400005][18];
int log2_val[400005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", s + i);
    for (int i = 1; i <= n; i++) number[i][0] = s[i];
    for (int pwr = 1; pwr <= 17; pwr++) {
        for (int i = 1; i <= n; i++) {
            int newnum = number[i][pwr-1] + number[i+(1<<(pwr-1))][pwr-1];
            number[i][pwr] = newnum % 10;
            candies[i][pwr] = candies[i][pwr-1] + candies[i+(1<<(pwr-1))][pwr-1]
                + (newnum >= 10 ? 1 : 0);
        }
    }
    for (int i = 0; i < 17; i++) log2_val[1<<i] = i;
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", candies[l][log2_val[r-l+1]]);
    }
    return 0;
}