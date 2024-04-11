#include <iostream>
#include <set>
using namespace std;
typedef long long LL;

int w,h,n;
set<int> st_w, st_h, rw, rh;
multiset<int> lw, lh;
int main() {
    scanf("%d%d%d",&w,&h,&n);

    st_h.insert(0); st_h.insert(h); 
    rh.insert(0); rh.insert(-h); 
    lh.insert(h);
    
    st_w.insert(0); st_w.insert(w); 
    rw.insert(0); rw.insert(-w);
    lw.insert(w);
    
    for(int i=1;i<=n;i++) {
        char op[2]; int pos;
        scanf("%s%d",op,&pos);
        if (op[0] == 'H') {
            int L = - (*rh.lower_bound(-pos));
            int R = *st_h.lower_bound(pos);
            //printf("%d %d\n", L, R);
            lh.erase(lh.lower_bound(R-L));    
            lh.insert(pos-L); lh.insert(R-pos);
            st_h.insert(pos);
            rh.insert(-pos);
        } else {
            int L = - *rw.lower_bound(-pos);
            int R = *st_w.lower_bound(pos);

            lw.erase(lw.lower_bound(R-L));
            lw.insert(pos-L); lw.insert(R-pos);
            st_w.insert(pos);
            rw.insert(-pos);
        }
        LL ans = (LL)*lh.rbegin() * (LL)*lw.rbegin();
        printf("%lld\n", ans);
    }
}