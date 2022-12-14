//In the name of God
#include <iostream>
using namespace std;
int main(){
    long long a,b,m;
    cin >> a >> b >> m;
    if(a < b)
        swap(a,b);
    if(a >= m || b >= m){
        cout << 0 << endl;
        return 0;
    }
    if(a <= 0 && b <= 0){
        cout << -1 << endl;
        return 0;
    }
    long long ans = 0;
    if(b < 0){
        ans += (-b)/a + 1;
        b %= a;
        b += a;
    }
    while(a < m){
        long long c = a;
        a = a + b;
        b = c;
        ans++;
    }
    cout << ans << endl;
    return 0;
}