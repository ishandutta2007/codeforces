#include <cstdio>
#include <algorithm>

using namespace std;

int a[100005];

int n;

int exists(int value, int l, int r)
{
    if (l > r) return 0;
    int origr = r;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] >= value) r = mid;
        else l = mid + 1;
    }
    if (a[l] != value) return 0;
    return 1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    if (n == 1) {
        if (a[1] % 2 == 1) {
            printf("sjfnb"); return 0;
        }
        printf("cslnb"); return 0;
    }
    sort(a + 1, a + n + 1);
    if (a[1] == 0 && a[2] == 0) {
        printf("cslnb"); return 0;
    }
    int samepairs = 0;
    int sameid = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i+1]) {
            samepairs++; sameid = i;
        }
    }
    if (samepairs >= 2) {printf("cslnb"); return 0;}
    long long extrasum = 0;
    if (samepairs == 1) {
        if (sameid > 1 && a[sameid - 1] == a[sameid] - 1) {printf("cslnb"); return 0;}
        a[sameid]--; extrasum++;
    }
    sort(a + 1, a + n + 1);
    long long sum = 0;
    for (int i = 1; i <= n; i++) sum += (long long)(a[i] - i + 1);
    sum += extrasum;
    if (sum % 2 == 1) {
        printf("sjfnb"); return 0;
    }
    printf("cslnb"); return 0;
}