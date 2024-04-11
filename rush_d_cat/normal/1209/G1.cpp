#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200000 + 10;
int n,q,a[N];
int c[N], l[N], r[N];
struct Item {
    int l,r,val;
    bool operator<(const Item&o)const{
        return l < o.l;
    }
} it[N]; int tot=0;

int main() {
    for(int i=0;i<N;i++) {
        l[i] = N, r[i] = 0;
    }
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        c[a[i]] ++;
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    for(int i=1;i<=200000;i++) {
        if(c[i]) {
            it[++tot] = (Item){l[i],r[i],c[i]};
        }
    }
    sort(it+1,it+1+tot);
    it[++tot] = (Item){N-1,0,0};
    int R=0,mx=0,ans=0;
    for(int i=1;i<=tot;i++) {
        //printf("[%d, %d] %d\n",it[i].l,it[i].r,it[i].val);
        if(it[i].l > R) {
            ans += mx;
            R = it[i].r;
            mx = it[i].val;
        } else {
            R = max(it[i].r, R);
            mx = max(mx, it[i].val);
        }
    }
    printf("%d\n", n - ans);
}