#include <iostream>
#include <algorithm>
using namespace std;
const int NICO = 100000+10;
typedef long long LL;
int n, r, avg;
int a[NICO], b[NICO];

struct Test
{
    int a, b;
} test[NICO];

bool cmp(Test x, Test y) {
    return x.b < y.b;
}

LL sum = 0, need;
int main() {

    scanf("%d %d %d", &n, &r, &avg);
    for(int i=1;i<=n;i++) {
        scanf("%d %d", &test[i].a, &test[i].b); sum += test[i].a;
    }
    need = ((LL)n * avg) - sum;
    if(need <= 0) return 0*printf("0\n");
    LL ans = 0;
    
    sort(test+1, test+1+n, cmp);
    for(int i=1;i<=n;i++) {
        int lim = r - test[i].a;
        int cnt = lim<need?lim:need;
        need -= cnt; ans += (LL)cnt * test[i].b;
        if(need <= 0) break;
    }
    cout << ans << endl;


}