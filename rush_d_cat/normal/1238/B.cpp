#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int T,n,r,x[N];
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&r);
        for(int i=1;i<=n;i++)scanf("%d",&x[i]);
        sort(x+1,x+1+n);
        int cnt = 0;
        for(int i=n,j=n;i>=1;i=j) {
            if (1LL * cnt * r >= x[i]) break;
            while(j>=1 && x[j]==x[i]) -- j;
            cnt ++;
        }
        printf("%d\n", cnt);
    }
}