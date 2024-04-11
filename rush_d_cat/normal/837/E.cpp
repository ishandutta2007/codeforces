#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
map<LL, int> mp;

LL gcd(LL x, LL y) {
    return y==0?x:gcd(y, x%y);
}

LL x, y;
int cnt = 0;

int isprime(LL x) {
    if(x == 2) return mp[x] = 1;
    for(LL t=2;t*t<=x;t++) {
        if(x % t == 0) return mp[x] = -1;
    }
    return mp[x] = 1;
}

LL f(LL x, LL y) {
    //cout << x << " " << y << endl;
    if(y == 0) return 0;
    if(y >= x) return f(x, y%x) + y / x;
    //cout << x << " " << mp[x] << endl;
    if(mp[x] == 0) isprime(x);    
    if(mp[x] == 1) return y;

    LL tmp = gcd(x, y);
    
    if(tmp != 1) return f(x/tmp, y/tmp);

    return 1 + f(x, y - tmp);
}


int main() {
    
    cin >> x >> y;
    cout << f(x, y) << endl;

}