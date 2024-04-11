#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;

LL t, a, b;
vector<LL> cof;

int main() {
    cin >> t >> a >> b; 
    if(t==1&&a==1&&b==1) return 0 * printf("inf\n");
    if(t!=1&&a==1&&b==1) return 0 * printf("1\n");
    if(a==1&&b>1) return  0 * printf("0\n");

    int ans = 0;
    LL b_ = b; while(b_) {cof.push_back(b_%a); b_/=a;}
    LL tmp = 1, sum = 0;
    for(int i=0;i<cof.size();i++) {
        sum += tmp * cof[i];
        tmp *= t;
    }

    if(sum == a) ans ++; // b in base-a
    if(a == b) ans ++; // constant functon!

    tmp = a;
    while(t == 1 && a <= b) 
    {
        if(2e18 / tmp < a) break;
        a *= tmp;        
        if(a == b) { ans ++; break;}
    }

    printf("%d\n", ans);
}

/*

a[0] + a[1]*t + a[2]*t^2 + .... + a[n]*t^n = 1
a[0] + a[1] + a[2] + ...  + a[n] = 5

a[0] = 5;
a[0] = 0, a[1] = 1.

a[j] = x
a[j] * x ^ j = y
y = x ^ (j + 1)

a[0] + a[1]*2 + .. = 2
a[0] + a[1]*2 + .. = 2

a[1] = 1
*/