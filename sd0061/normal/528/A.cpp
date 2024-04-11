#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
const int M = 200005;

int n , m , Q;
char str[10];
set<int> V , H;
multiset<int> v , h;
void work () {
    
    scanf("%d%d%d",&n,&m,&Q);
    V.insert(0) , V.insert(n) , v.insert(n);
    H.insert(0) , H.insert(m) , h.insert(m);
    
    while (Q --) {
        int x;
        scanf("%s%d" , str , &x);
        if (*str == 'V') {
            auto r = V.lower_bound(x);
            auto l = r; -- l;
            v.erase(v.find(*r - *l));
            v.insert(*r - x);
            v.insert(x - *l);
            V.insert(x);
        } else {
            auto r = H.lower_bound(x);
            auto l = r; -- l;
            h.erase(h.find(*r - *l));
            h.insert(*r - x);
            h.insert(x - *l);
            H.insert(x);
        }
        printf("%lld\n" , (LL) *v.rbegin() * *h.rbegin());
    }
    
    
}

int main () {
    work();
    return 0;
}