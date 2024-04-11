#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,q;
int a, b;

int main(){
    scanf("%d%d", &n, &q);
    if(n % 2 == 0){
        while(q--){
            ll res = 0;
            scanf("%d%d", &a, &b);
            a--, b--;
            if((a + b) % 2 == 0) res = 1LL * a * (n / 2) + (b / 2);
            else res = 1LL * n * n / 2 + 1LL * a * (n / 2) + (b / 2);
            printf("%I64d\n", res + 1);
        }
    }
    else{
        while(q--){
            ll res = 0;
            scanf("%d%d", &a, &b);
            a--, b--;
            if(a % 2 == 0 && b % 2 == 0){
                res = 1LL * a / 2 * n + b / 2;
            }
            else if(a % 2 == 1 && b % 2 == 1){
                res = 1LL * a / 2 * n + (n / 2 + 1) + b / 2;
            }
            else if(a % 2 == 1 && b % 2 == 0){
                res = (1LL * n * n / 2 + 1) + 1LL * a / 2 * n + n / 2 + b / 2;

            }
            else{
                res = (1LL * n * n / 2 + 1) + 1LL * a / 2 * n + b / 2;
            }
            printf("%I64d\n", res + 1);
        }
    }


}