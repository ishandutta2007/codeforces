#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
const int N=200000 + 10;
int t,n; LL s;
struct Item {
    int l, r;
    bool operator<(const Item &o)const{
        return l < o.l;
    }
} it[N];   
bool chk(int mid) {
    int cnt = 0; LL need=0;
    for(int i=n;i>=1;i--){
        if(it[i].l>=mid) need += it[i].l, cnt ++;
        else {
            if (cnt >= (n+1)/2) {
                need += it[i].l;
            } else {
                if (it[i].r < mid) {
                    need += it[i].l;
                } else {
                    cnt ++;
                    need += mid;
                }
            }
        }
    }
    return (need <= s) && (cnt >= (n+1) / 2);
}
int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d%lld",&n,&s);
        for (int i=1;i<=n;i++){
            scanf("%d%d",&it[i].l,&it[i].r);
        }
        sort(it+1,it+1+n);
        //chk(12); return 0;
        LL lef=1,rig=1e9+1;
        while(rig-lef>1){
            LL mid=(lef+rig)>>1;
            if(chk(mid)) lef=mid; else rig=mid;
        }
        printf("%lld\n", lef);
    }
}