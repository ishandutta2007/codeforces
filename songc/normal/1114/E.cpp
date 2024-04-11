#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, Q=58;
int Xn, d;
bool visit[1010101];

int main(){
    scanf("%d", &N);
    mt19937 gen(time(NULL));
    uniform_int_distribution<> rng(1, N);
    int l=0, h=1000000000;
    while (l <= h){
        int mid = (l+h)/2;
        printf("> %d\n", mid);
        fflush(stdout);
        Q--;
        int ret;
        scanf("%d", &ret);
        if (ret) l = mid+1;
        else{
            h = mid-1;
            Xn = mid;
        }
    }
    while (Q--){
        printf("? %d\n", rng(gen));
        fflush(stdout);
        int ret;
        scanf("%d", &ret);
        d = __gcd(d, Xn-ret);
    }
    printf("! %lld %d\n", Xn-(LL)d*(N-1), d);
    fflush(stdout);
    return 0;
}