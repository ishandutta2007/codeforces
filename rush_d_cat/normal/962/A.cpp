#include <iostream>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int n; LL a[N], tot=0;

int main() {
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        tot += a[i];
    }
    LL s=0;
    for(int i=1;i<=n;i++){
        s+=a[i];
        if(2*s>=tot){
            return !printf("%d\n", i);
        }
    }
}