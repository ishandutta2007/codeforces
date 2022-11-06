#include <cstdio>
#include <map>
using namespace std;
const int N = 2e5 + 2;

int t, n, c, q, m;
map<long long, long long> mp;
char s[N];
long long l, r, p;

int main(){
    scanf("%d", &t);
    while(t--){
        mp.clear();
        scanf("%d%d%d%s", &n, &c, &q, s + 1);
        long long now = n;
        while(c--){
            scanf("%lld%lld", &l, &r);
            now += r - l + 1;
            mp[now] = r;
        }
        while(q--){
            scanf("%lld", &p);
            while(p > n){
                long long q = (*mp.lower_bound(p)).first;
                p = mp[q] - (q - p);
            }
            putchar(s[p]);
            putchar('\n');
        }
    }
    return 0;
}