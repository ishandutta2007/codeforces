#include <iostream>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,k1,k2;
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&k1,&k2);
        int f1=0,f2=0;
        for(int i=1;i<=k1;i++){
            int x;scanf("%d",&x);f1=max(f1,x);
        }
        for(int i=1;i<=k2;i++){
            int x;scanf("%d",&x);f2=max(f2,x);
        }
        printf("%s\n", f1>=f2?"YES":"NO");
    }
}