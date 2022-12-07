#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 1;

int t, n, k;
struct node{
    int a, b;
    bool operator<(const node &r) const{
        return a != r.a ? a < r.a : b < r.b;
    }
}nd[N];

int main(){
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &nd[i].a, &nd[i].b);
        sort(nd + 2, nd + 1 + n);
        int p = 0x80000000;
        for (int i = 2; i <= n; i++){
            p = max(p, min(p, nd[i].a) + nd[i].b);
            p = max(p, nd[i].a);
            if(i > 2)
                p = max(p, nd[i - 1].a + nd[i - 1].b);
        }
        if(k <= nd[1].a || k <= min(p, nd[1].a) + nd[1].b)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}