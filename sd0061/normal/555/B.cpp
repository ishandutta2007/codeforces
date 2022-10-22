#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
const int Q = 1e9 + 7;
int n , m;
LL L[N] , R[N];
pair<LL , int> a[N];

struct island {
    LL l , r , id;
    bool operator < (const island& R) const {
        return make_pair(r , l) < make_pair(R.r , R.l);
    }
}b[N];
int res[N];

void work() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%lld%lld" , &L[i] , &R[i]);
    for (int i = 0 ; i + 1 < n ; ++ i) {
        b[i] = (island) {L[i + 1] - R[i] , R[i + 1] - L[i] , i};
    }
    -- n;
    sort(b , b + n);
    for (int i = 0 ; i < m ; ++ i) {
        scanf("%lld" , &a[i].first);
        a[i].second = i + 1;
    }
    sort(a , a + m);
    set< pair<LL , int> > Hash; 
    for (int i = 0 , j = 0; i < n ; ++ i) {
        while (j < m && a[j].first <= b[i].r) {
            Hash.insert(a[j]);
            ++ j;
        }
        auto it = Hash.lower_bound(make_pair(b[i].l , -1));
        if (it == Hash.end()) {
            puts("No");
            return;
        }
        res[b[i].id] = it -> second;
        Hash.erase(it);
    }
    puts("Yes");
    for (int i = 0 ; i < n ; ++ i)
        printf("%d\n" , res[i]);
}

int main() {
    work();    
    return 0;
}