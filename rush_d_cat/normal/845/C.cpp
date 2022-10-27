#include <iostream>
#include <algorithm>
using namespace std;
#define N (200000+10)
int n;

struct Item {
    int pos, type;
} item[2 * N];

bool cmp(Item A, Item B)
{
    if (A.pos == B.pos) return A.type > B.type;
    return A.pos < B.pos;
}


int main()
{
    scanf("%d", &n);
    int cnt = 1;
    for (int i = 1; i <= n; i ++) {
        scanf("%d %d", &item[cnt].pos, &item[cnt + 1].pos);
        item[cnt].type = 1, item[cnt + 1].type = -1; cnt += 2;
    }
    sort(item + 1, item + cnt, cmp);
    int ans = 0, s = 0;
    for (int i = 1; i < cnt; i ++) {
        s += item[i].type;
        ans = max(ans, s);
    }
    printf("%s\n", ans <= 2?"YES":"NO");
}