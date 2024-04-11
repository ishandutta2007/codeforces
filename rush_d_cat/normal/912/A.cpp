#include <iostream>
using namespace std;
typedef long long LL;
LL A, B; LL x, y, z;
LL max(LL a, LL b) {return a>b?a:b;}
int main() {
    cin >> A >> B >> x >> y >> z;
    LL AA = 2L * x + y;
    LL BB = y + 3L * z;
    LL ans = max(AA - A, 0) + max(BB - B, 0);
    cout << ans << endl;
}