#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int T,h,n,p[N];
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&h,&n);
        for(int i=1;i<=n;i++)scanf("%d",&p[i]);
        int ans=0;
        for(int i=1,j=1;i<=n;i=j) {
            j++;
            while(j<=n && p[j]+1==p[j-1]) j++;
            int add = i == 1 ? 1 : 0;
            // printf("[%d,%d)\n", i,j);
            if((j-i+add)%2 == 1) {
                if(! (j==n+1 && p[n]==1))
                ans ++;
            }
        }
        printf("%d\n", ans);
    }
}