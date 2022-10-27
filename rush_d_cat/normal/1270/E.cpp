#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n;
LL x[N], y[N];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x[i],&y[i]);
    }
    while(1) {
        vector<int> r;
        for(int i=1;i<=n;i++){
            if((x[i]+y[i])%2==0) r.push_back(i);
        }
        if(r.size()==0 || r.size()==n) {
            for(int i=1;i<=n;i++){
                LL tx = x[i];
                LL ty = y[i];
                x[i] = tx - ty;
                y[i] = tx + ty; 
            }
            /*
            for (int i=1;i<=n;i++){
                printf("(%lld, %lld)\n", x[i],y[i]);
            }
            */
            if (x[1] % 2 != 0) {
                for (int i = 1; i <= n; i ++) {
                    x[i] ++, y[i] ++;
                    x[i] /= 2, y[i] /= 2;
                }
            } 
            
            while (1) {
                bool ok = 1;
                for (int i = 1; i <= n; i ++) {
                    if (x[i] % 2 || y[i] % 2) ok = 0;
                }
                if (ok) {
                    for (int i = 1; i <= n; i ++) {
                        x[i] /= 2, y[i] /= 2;
                    }
                } else {
                    break;
                }
            }
            /*
            for (int i=1;i<=n;i++){
                printf("(%lld, %lld)\n", x[i],y[i]);
            }
            */
            continue;
        }
        printf("%d\n", r.size());
        for(auto x: r){
            printf("%d ", x);
        }
        return 0;
    }
}