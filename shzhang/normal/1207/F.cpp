#include <cstdio>

using namespace std;

int ans[705][705];
int arr[500005];

int main()
{
    int q;
    scanf("%d", &q);
    for (int op = 1; op <= q; op++) {
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);
        if (type == 1) {
            arr[x] += y;
            for (int i = 1; i <= 700; i++) {
                ans[i][x%i] += y;
            }
        } else {
            if (x <= 700) {
                printf("%d\n", ans[x][y]);
            } else {
                int answ = 0;
                for (int i = y; i <= 500000; i += x) answ += arr[i];
                printf("%d\n", answ);
            }
        }
    }
    return 0;
}