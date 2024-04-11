#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100005];
int newarr[100005];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    sort(arr + 1, arr + n + 1);
    newarr[1] = arr[n-1];
    for (int i = 2; i < n; i++) newarr[i] = arr[i-1];
    newarr[n] = arr[n];
    bool good = true;
    for (int i = 2; i < n; i++)
        if (newarr[i] >= newarr[i-1] + newarr[i+1])
            good = false;
    if (newarr[1] >= newarr[2] + newarr[n]) good = false;
    if (newarr[n] >= newarr[1] + newarr[n-1]) good = false;
    if (!good) {
        printf("NO");
    } else {
        printf("YES\n");
        for (int i = 1; i <= n; i++) printf("%d ", newarr[i]);
    }
    return 0;
}