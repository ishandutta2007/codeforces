#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
ll a, b, c, d, e;

int main(){
    cin >> a >> b >> c;
    //scanf("%lld %lld %lld", &a, &b, &c);
    d = (ll)sqrt(a * b * c);
    e = d / a + d / b + d / c;
    cout << e * 4 << endl;
    //printf("%lld\n", e * 4);
    return 0;
}