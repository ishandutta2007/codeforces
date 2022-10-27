#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
map<LL, int> mp;
const int N = 200000+10;
int n;
LL x[N];
LL p[N];
int main() {
    p[0]=1;
    
    for (int i=1;i<=32;i++)
        p[i]=p[i-1]*2LL;

    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        scanf("%lld", &x[i]);
        mp[x[i]] = 1;
    }

    LL ans1=-1,ans2=-1,ans3=-1;
    for (int i=1;i<=n;i++) {
        for(int j=0;j<=32;j++) {
            if (mp.find(x[i]+p[j]) != mp.end()) {
                ans1=x[i];
                ans2=x[i]+p[j];
                break;
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for(int j=0;j<=32;j++) {
            if (mp.find(x[i]+p[j]) != mp.end()
                && mp.find(x[i]-p[j]) != mp.end()) {
                ans1=x[i];
                ans2=x[i]+p[j];
                ans3=x[i]-p[j];
                printf("3\n");
                printf("%lld %lld %lld\n", ans1,ans2,ans3);
                return 0;
            }
        }
    }
    if (ans1 == -1) {
        printf("1\n%lld",x[1]);
    } else {
        printf("2\n");
        printf("%lld %lld\n", ans1, ans2);
    }
}