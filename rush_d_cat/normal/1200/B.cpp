#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;
const int N = 100 + 10;
int t,n,m,k,h[N];
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&h[i]);
        }
        bool ok=1;
        for(int i=1;i<n;i++){
            if(h[i]>=h[i+1]-k){
                int mn = max(0,h[i+1]-k);
                m += h[i] - mn;
            } else {
                m -= (h[i+1]-k) - h[i];
                if(m<0) ok=0;
            }
            //printf("m=%d\n", m);
        }
        printf("%s\n", ok?"YES":"NO");
    }
}