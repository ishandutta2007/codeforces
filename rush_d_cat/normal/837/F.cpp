#include <iostream>
using namespace std;
typedef long long LL;
LL a[200000+10];
int main() {
    LL n, k; scanf("%lld %lld", &n, &k);

    int first = 0;
    for(int i=1;i<=n;i++) {
        scanf("%lld", &a[i]);
        if(a[i] >= k) return 0*printf("0\n");
        if(a[i] && !first) first = i;
    }
    
    //cout << first << " " << n << endl;


    if(n - first >= 3) {
        
        for(int t=1;t<=10000000;t++) {
            for(int i=first+1;i<=n;i++) {
                a[i] = a[i] + a[i-1];
                if(a[i] >= k) {
                    return 0*printf("%d\n", t);
                }
            }
        }

    } else {
        if(n - first == 2) {
            LL a1 = a[n - 2];
            LL a2 = a[n - 1];
            LL a3 = a[n];

            LL L = 1, R = 2e9;
            while(R - L > 1) {
                LL mid = (L + R) / 2;
                LL tmp = (mid * mid + mid) / 2;
                if((LL)2e18 / a1 < tmp) {
                    R = mid;
                } else
                if(tmp * a1 + a3 + a2 * mid >= k) {
                    R = mid;
                } else {
                    L = mid;
                }
            }

            if((L*L+L)/2*a1 + L*a2 + a3 >= k) {
                R = L;
            }
            printf("%lld\n", R);


        }

        if(n - first == 1) {
            LL a1 = a[n - 1];
            LL a2 = a[n];
            printf("%lld\n", (k - a2 + a1 - 1) / a1);
        }

    }


}