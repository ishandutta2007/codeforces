#include <iostream>
using namespace std;
typedef long long LL;
LL n, s;
int cac(LL x) {
    int sum = 0;
    LL temp = x;
    while(temp) {
        sum += temp % 10;
        temp /= 10;
    }
    if(x - sum >= s) return 1;
    return 0;
}

int main() {
    cin >> n >> s;
    LL ans = 0, x = s;
    for(x = s; x <= min(s + 200, n); x++) {
        if(cac(x)) ans ++; 
    }
    if(x <= n+1)
        ans += n - x + 1;
    cout << ans << endl;
}