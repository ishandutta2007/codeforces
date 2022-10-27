#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int NICO = 200000 + 10;

int m, a[NICO], res[NICO];

struct Num
{
    int val, id;
} b[NICO];

bool cmp(Num a, Num b) {
    return a.val > b.val;
}

int main() {
    scanf("%d", &m);
    for(int i = 1; i <= m; i ++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= m; i ++) {
        scanf("%d", &b[i].val); b[i].id = i;
    }
    sort(b + 1, b + 1 + m, cmp);

    sort(a + 1, a + 1 + m);

    for(int i = 1; i <= m; i ++) {
        res[b[i].id] = a[i];
    }
    for(int i = 1; i <= m; i ++) {
        printf("%d ", res[i]);
    }
}