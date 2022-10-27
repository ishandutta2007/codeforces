#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int k;
int c[N], a[N];

map<LL, pair<int,int> > mp;

int main() {
    scanf("%d",&k);
    for(int i=1;i<=k;i++) {
        scanf("%d",&c[i]);
        LL sum=0;
        for(int x=1;x<=c[i];x++) {
            scanf("%d",&a[x]);
            sum += a[x];
        }
        for(int x=1;x<=c[i];x++) {
            if (mp.find(sum-a[x]) == mp.end()) {
                mp[sum-a[x]] = make_pair(i, x);
            } else {
                if (mp[sum-a[x]].first == i) continue;
                printf("YES\n");
                printf("%d %d\n", mp[sum-a[x]].first, mp[sum-a[x]].second);
                printf("%d %d\n", i, x); return 0;
            }
        }
    }
    printf("NO\n");
}