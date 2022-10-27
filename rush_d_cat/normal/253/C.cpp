#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
const int N=100000 + 10;
int n,a[N];
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int r1,c1,r2,c2; scanf("%d%d%d%d",&r1,&c1,&r2,&c2); a[r1]=c1-1;
    int mn1=N; for(int i=min(r1,r2);i<=max(r1,r2);i++) mn1=min(mn1,a[i]+1);
    int ans=1e9;
    //printf("mn1=%d\n", mn1);

    int mn2=mn1;
    for(int i=r1;i>=1;i--) {
        mn2=min(mn2,a[i]+1);
        //printf("# %d\n", mn2);
        ans=min(ans,(r1-i)+abs(r2-i)+abs(mn2-c2));
    }
    mn2=mn1;
    for(int i=r1;i<=n;i++) {
        mn2=min(mn2,a[i]+1);
        //printf("mn2=%d\n", mn2);
        ans=min(ans,(i-r1)+abs(r2-i)+abs(mn2-c2));
    }
    
    printf("%d\n", ans);
}