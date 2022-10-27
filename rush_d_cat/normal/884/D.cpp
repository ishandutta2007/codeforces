#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
const int N = 200000+10;
typedef long long LL;
int n, a[N];
multiset<LL> st;
void naive() {
    if (n == 1) printf("0\n");
    if (n == 2) printf("%d\n", a[1]+a[2]);
    if (n == 3) printf("%d\n", a[1]+a[2]+a[3]);
}

LL solve() {
    LL res = 0, m1,m2,m3;
    //printf("%d\n", st.size());
    while (st.size() > 1) {
        m1 = *st.begin(); st.erase(st.lower_bound(m1));
        m2 = *st.begin(); st.erase(st.lower_bound(m2));
        if (st.size() >= 1) {
            m3 = *st.begin(); st.erase(st.lower_bound(m3));
            res += m1+m2+m3; st.insert(m1+m2+m3);
        } else {
            res += m1+m2; st.insert(m1+m2);
        }
    }
    return res;
}  

int main() {
    scanf("%d", &n);
    for (int i=1;i<=n;i++) 
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    
    if (n <= 3) {
        naive(); return 0;
    }
    
    st.insert(a[1]+a[2]);
    for (int i=3;i<=n;i++) st.insert(a[i]);
    LL ans = a[1]+a[2]+solve(); //printf("%lld\n", ans);
    st.clear(); st.insert(a[1]+a[2]+a[3]);
    for (int i=4;i<=n;i++) st.insert(a[i]);
    ans = min(ans, a[1]+a[2]+a[3]+solve());
    printf("%lld\n", ans);
}