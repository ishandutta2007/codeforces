#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , m;
struct opt {
    int id , l , r ,  k;
    bool operator < (const opt& R) const {
        if (r != R.r)
            return r > R.r;
        return l < R.l;
    }
}a[N] , b[N];
int res[N];

multiset<opt> hash;

void work() {
    int i , j;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d",&a[i].l , &a[i].r);
        a[i].id = i;
    }
    sort(a , a + n);
    scanf("%d",&m);
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d%d" , &b[i].l,&b[i].r,&b[i].k);
        b[i].id = i + 1;
    }
    sort(b , b + m);

    for (i = 0 , j = 0 ; i < n ; ++ i) {
        while (j < m && b[j].r >= a[i].r) {
            b[j].r = 0;
            hash.insert(b[j]);
            j ++;
        }
        set<opt>::iterator it = hash.upper_bound((opt){0 , a[i].l , 0 , 0});
        if (it == hash.begin()) {
            puts("NO");
            return;
        }
        -- it;
        res[a[i].id] = it -> id;
        opt tmp = *it;
        hash.erase(it);
        if (-- tmp.k)
            hash.insert(tmp);
    }
    puts("YES");
    for (i = 0 ; i < n ; ++ i)
        printf("%d%c" , res[i] , " \n"[i + 1 == n]);

}

int main() {
    work();
    return 0;
}