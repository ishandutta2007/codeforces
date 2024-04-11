#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
#define lowbit(x) ((x)&(-(x)))

int n;

bool arr[300005];
int lst;

int main()
{
    scanf("%d", &n); lst = n;
    printf("1 ");
    for (int i = 1; i <= n; i++) {
        int p;
        scanf("%d", &p);
        arr[p] = true;
        while (arr[lst]) lst--;
        if (arr[n]) {
            printf("%d ", i - n + lst + 1);
        } else {
            printf("%d ", i + 1);
        }
    }
    return 0;
}