#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define min(x, y) (x<y?x:y)
const int NICO = 100000+10;
LL n, A, cf, cm, m;
LL a[NICO], suf[NICO], pre[NICO];
LL ans[NICO];

bool chk(LL x, LL r, LL money) {
    int pos = upper_bound(a + 1, a + 1 + n, x) - a - 1;
    pos = min(pos, r);
    LL need = x * pos - pre[pos];

    return need <= money;
}

struct Skill {
    LL val;
    int id;
} skill[NICO];

bool cmp(Skill sk1, Skill sk2) {
    return sk1.val < sk2.val;
}

int main() {

    scanf("%lld %lld %lld %lld %lld", &n, &A, &cf, &cm, &m);
    
    LL sum = 0;
    for(int i = 1; i <= n; i ++) {
        scanf("%lld", &a[i]);
        sum += A - a[i];
        skill[i].id = i;
        skill[i].val = a[i];
    }

    if(sum <= m) {
        printf("%lld\n", n * cf + A * cm);  
        for(int i = 1; i <= n; i ++) {
            printf("%lld ", A);
        }
        printf("\n");
        return 0;
    }

    sort(a + 1, a + 1 + n);
    sort(skill + 1, skill + 1 + n, cmp);

    for(int i = n; i >= 1; i --) {
        suf[i] = suf[i+1] + a[i];
    }
    for(int i = 1; i <= n; i ++) {
        pre[i] = pre[i-1] + a[i];
    }


    LL res = -1;
    LL best_max, best_min, best_max_cnt;

    // change [i+1, n] to A 

    for(int i = n; i >= 0; i --) {
        LL mx_cnt = n - i;
        LL mx_cost = mx_cnt * A - suf[i + 1];
        if(m < mx_cost) continue;
        LL tmp_mark = mx_cnt * cf;

        LL L = 0, R = A + 1;

        while(R - L > 1) {
            LL mid = (L + R) >> 1;
            if(chk(mid, i, m - mx_cost)) {
                L = mid;
            } else {
                R = mid;
            }
        }
        //printf("%lld %lld\n", n-i, L);
        tmp_mark += L * cm;

        if(tmp_mark > res) {
            res = tmp_mark;
            best_max_cnt = mx_cnt;
            best_max = i == n ? 1e9+7 : a[i+1];
            best_min = L;
        }
    }

    for(int i = 0; i < best_max_cnt; i ++)
    {
        ans[ skill[n - i].id ] = A;
    }

    for(int i = 1; i <= n; i ++) {
        if(ans[ skill[i].id ] == A) continue;
        if(skill[i].val <= best_min) {
            ans[ skill[i].id ] = best_min;
        } else {
            ans[ skill[i].id ] = skill[i].val;
        }
    }

    printf("%lld\n", res);
    for(int i = 1; i <= n; i ++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");


}