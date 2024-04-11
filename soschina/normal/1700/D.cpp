#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
const int N = 2e5 + 1;

int n, q, x;
long long v[N], extv[N], t[N];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &v[i]);
    t[1] = v[1];
    for (int i = 2; i <= n; i++){
        extv[i] = extv[i - 1] + t[i - 1] - v[i];
        t[i] = t[i - 1];
        if(extv[i] < 0){
            t[i] += (-extv[i] - 1) / i + 1;
            extv[i] += ((-extv[i] - 1) / i + 1) * i;
        }
    }
    for (int i = n - 1; i; i--){
        if(extv[i] < v[i + 1])
            t[i] += (v[i + 1] - extv[i] - 1) / i + 1;
        v[i] += v[i + 1];
    }
    scanf("%d", &q);
    while(q--){
        scanf("%d", &x);
        int p = lower_bound(t + 1, t + 1 + n, x, greater<long long>()) - t;
        if(p == n + 1)
            puts("-1");
        else
            printf("%d\n", p);
    }
    return 0;
}