#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,a[N];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        bool fg=0;
        for(int i=2;i<=n;i++){
            if(abs(a[i]-a[i-1])>=2){
                printf("YES\n%d %d\n", i-1,i); fg=1;
                break;
            }
        }
        if(!fg) printf("NO\n");
    }   
}