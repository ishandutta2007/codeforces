#include <cstdio>
#include <cstring>

using namespace std;

int n;
int freq[200005];
int sum[200005];

int main()
{
    scanf("%d", &n);
    int mval = 0;
    for (int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        if (val > mval) mval = val;
        freq[val]++;
    }

    for (int i = 1; i <= mval; i++) sum[i] = freq[i] + sum[i - 1];

    int i = 1;

    int beststart = 1, bestend = 1, bestcnt = 0;

    while (i <= mval) {
        if (!freq[i]) {i++; continue;}
        int j = i + 1;
        while (freq[j] >= 2) j++;
        if (!freq[j]) j--;

        if (sum[j] - sum[i-1] > bestcnt) {
            bestcnt = sum[j] - sum[i-1];
            beststart = i;
            bestend = j;
        }

        if (j == i) j++;
        i = j;
    }

    printf("%d\n", bestcnt);

    for (int i = beststart; i <= bestend; i++) printf("%d ", i);
    for (int i = bestend; i >= beststart; i--) {
        for (int j = 1; j < freq[i]; j++) printf("%d ", i);
    }
    return 0;
}