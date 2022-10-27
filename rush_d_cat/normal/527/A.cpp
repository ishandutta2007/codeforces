#include <iostream>
using namespace std;
typedef long long LL;
LL x, y, ans;
LL gcd(LL x, LL y) {
    if(y) ans += x / y;
    return y==0?x:gcd(y,x%y);
}
int main() {
    cin>>x>>y;
    gcd(x,y);
    cout<<ans<<endl;
}