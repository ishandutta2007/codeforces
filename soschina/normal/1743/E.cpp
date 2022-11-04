#include <cstdio>
#include <iostream>
using namespace std;
const int N = 5001;

int p1, p2, h, s;
long long t1, t2;
long long tim[N];

int main(){
    scanf("%d%lld%d%lld%d%d", &p1, &t1, &p2, &t2, &h, &s);
    if(t1 > t2){
        swap(p1, p2);
        swap(t1, t2);
    }
    long long ans = 0x7fffffffffffffff;
    for (int d = 0; d < h; d++){
        if(d > 0 && tim[d] == 0)
            continue;
        for (long long i = (t2 - 1) / t1 + 1;; i++){
            long long t = t1 * i;
            long long k = t / t2 - 1;
            long long dmg = 1ll * (i - 1) * (p1 - s) + k * (p2 - s) + p1 + p2 - s;
            long long newd = d + dmg;
            if(newd >= h){
                ans = min(ans, tim[d] + t);
                break;
            }
            else if(newd >= 0 && (!tim[newd] || tim[newd] > tim[d] + t))
                tim[newd] = tim[d] + t;
        }
        for (int i = 1;; i++){
            long long t = t2 * i;
            long long k = t / t1 - 1;
            long long dmg = 1ll * (i - 1) * (p2 - s) + k * (p1 - s) + p1 + p2 - s;
            long long newd = d + dmg;
            if(newd >= h){
                ans = min(ans, tim[d] + t);
                break;
            }
            else if(newd >= 0 && (!tim[newd] || tim[newd] > tim[d] + t))
                tim[newd] = tim[d] + t;
        }
        long long t = tim[d];
        long long now = d;
        long long c1 = t1, c2 = t2;
        while(now < h){
            if(c1 < c2){
                t += c1;
                c2 -= c1;
                c1 = t1;
                now += p1 - s;
            }
            else if(c2 < c1){
                t += c2;
                c1 -= c2;
                c2 = t2;
                now += p2 - s;
            }
            else{
                t += c1;
                c1 = t1;
                c2 = t2;
                now += p1 + p2 - s;
            }
        }
        ans = min(ans, t);
    }
    printf("%lld", ans);
    return 0;
}