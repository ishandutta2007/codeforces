#include <iostream>
using namespace std;
typedef long long LL;
LL m, b;
int main() {
    cin >> m >> b;
    LL mx = -1;
    for(LL k = 0; k <= b; k ++) {
        LL tmp = (b-k)*m*((b-k)*m+1)/2 * (k+1) + k*(k+1)/2 * ((b-k)*m + 1);
        if(tmp > mx) {
            mx = tmp;
        }
    }
    cout << mx << endl;
}