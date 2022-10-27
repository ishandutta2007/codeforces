#include <iostream>
using namespace std;
typedef long long LL;
LL n, k;
LL a[300000+10], b[300000+10];

int main() {

    scanf("%lld %lld", &n, &k);
    for(int i=0;i<=n;i++) scanf("%lld", &a[i]), b[i] = a[i];
    
    for(int i=0;i<=n+100;i++) {
        
        LL d = 0;

        if(a[i] % 2 == 0) {
            d = (+0 - a[i]) / 2; a[i] = +0;
        } else if(a[i] < 0 && i > n + 50) {
            d = (-1 - a[i]) / 2; a[i] = -1;
        } else {
            d = (+1 - a[i]) / 2; a[i] = +1;
        }
        a[i+1] -= d;
        //cout << a[i+1] << endl;
    }

    int lim = 0;
    for(lim = 0; lim <= n+100 && a[lim] == 0; lim ++) {}

    //printf("lim: %d\n", lim);
    //for(int i=0;i<=n+20;i++) printf("%d ", a[i]);
    //printf("\n");

    LL ans = 0; int cnt = 0;
    for(int i=n+100;i>=0;i--) 
    {
        ans = ans * 2L; 

        if(abs(ans) > 1e17) break;

        if(a[i] == 1) ans --;

        if(a[i] == -1)ans ++;

        //if(i <= lim)
        //cout << i << " -> " << (b[i]+ans) << endl;

        if(i <= n && i <= lim && b[i] + ans <= k && b[i] + ans >= -k && (b[i] + ans != 0 || i != n)) {
            cnt ++; 
        }

    }

    cout << cnt << endl;

}