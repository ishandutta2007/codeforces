#include <iostream>
#include <vector>
using namespace std;
const int N = 150000+10;
typedef long long LL;
int n;
int a[N],b[N];
vector<LL> fac;

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&a[i],&b[i]);
    }

    for(LL i=2;i*i<=a[1];i++) {
        if (a[1]%i==0) {
            fac.push_back(i);
            while(a[1]%i==0) a[1]/=i;
        }
    }
    if(a[1]>1) fac.push_back(a[1]);

    for(LL i=2;i*i<=b[1];i++) {
        if (b[1]%i==0) {
            fac.push_back(i);
            while(b[1]%i==0) b[1]/=i;
        }
    }
    if(b[1]>1) fac.push_back(b[1]);

    for(int i=0;i<fac.size();i++) {
        bool ok = 1;
        for(int j=2;j<=n;j++) {
            if(a[j]%fac[i] && b[j]%fac[i]) ok = 0;
        }
        if (ok) return !printf("%lld\n", fac[i]);
    }
    printf("-1\n");

}