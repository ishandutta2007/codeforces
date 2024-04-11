#include <iostream>
using namespace std;
typedef long long LL;
#define max(a,b) ((a)>(b)?(a):(b))
LL n;
LL v[11] = {0,9,99,999,9999,99999,999999,9999999,99999999,999999999,9999999999}; 
LL t[11] = {0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

LL cac(LL msum) {
    long long L = max(1, msum-n);
    long long R = min(n, msum-1);  
    //printf("%lld %lld\n", L, R);  
    return max((R - L + 1) / 2, 0);
}
int main() {
    cin >> n;

    LL msum = n + (n - 1);
    int c = 0;

    while (msum > v[c]) {
        c ++;
    }

    if (msum == v[c]) {
        printf("%lld\n", cac(msum));
        return 0;
    }


    LL ans = 0;
    for (int pos = c; pos <= c; pos ++) {
        LL tmp = v[c] - 9LL*t[pos];
        //cout <<tmp << endl;
        for (int i = 1; i <= 9; i ++) {
            if (tmp > msum) break;
            // cout << tmp << endl;
            //cout << tmp << " " << cac(tmp) << endl;
            ans += cac(tmp); 
            tmp += t[pos];
        }
    }   

    printf("%lld\n", ans);


}