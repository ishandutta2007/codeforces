#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<LL, int> pii;
LL x, y; vector<pii> v;
LL gcd(LL x, LL y) {
    return y == 0 ? x : gcd(y, x%y);
}
int main() {
    cin >> x >> y;
    if (gcd(x, y) > 1) {
        return !printf("Impossible\n");
    }
    while (x && y) {
        if (x > y) {
            LL c = (y == 1) ? x - 1 : x / y;
            v.push_back(make_pair(c,0));
            x %= y;
        } else {
            LL c = (x == 1) ? y - 1 : y / x;
            v.push_back(make_pair(c,1));
            y %= x;
        }
    }
    for (int i=0;i<v.size();i++) {
        printf("%lld%c", v[i].first, v[i].second == 0 ? 'A' : 'B');
    }
    printf("\n");
}