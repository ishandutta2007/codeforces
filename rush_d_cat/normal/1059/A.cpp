#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100000 + 10;
typedef long long LL;
int n,L,a;
int t[N],l[N];
int main() {
    scanf("%d%d%d",&n,&L,&a);
    for(int i=1;i<=n;i++) scanf("%d%d",&t[i],&l[i]);
    LL ans=0;
    t[n+1]=L;
    for(int i=1;i<=n+1;i++){
        int len = t[i] - (t[i-1]+l[i-1]);
        ans += len / a;
    }
    cout << ans << endl;
}