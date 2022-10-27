#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
int n,m,a[N],c[N];
set<int> st[N];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]), st[c[i]].insert(i);

    int low=0;

    for(int i=1;i<=m;i++){
        int t,d;
        scanf("%d%d",&t,&d);
        if(a[t]>=d) {
            a[t]-=d; 
            printf("%lld\n", 1LL*d*c[t]);
            if(a[t]==0) st[c[t]].erase(t);
        } else {
            LL ans=1LL*a[t]*c[t];
            d -= a[t]; a[t]=0;

            while(d && low<=1000000) {
                while(st[low].size() == 0 && low<=1000000) low ++;
                if (low>1000000) {
                    ans=0; break;
                }
                vector<int> del;
                for(auto x: st[low]) {
                    if(a[x] <= d) {
                        d -= a[x]; ans += 1LL*a[x]*c[x]; a[x]=0; del.push_back(x);
                    } else {
                        a[x] -= d; ans += 1LL*d*c[x]; d = 0; break;
                    }
                }
                for(auto x: del)
                    st[low].erase(x);
            }

            printf("%lld\n", ans);
        }
    
        //for(int j=1;j<=n;j++) printf("%d ", a[j]); printf("\n");
    }
}