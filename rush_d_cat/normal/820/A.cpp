#include <iostream>
using namespace std;
int c, v0, v1, a, l;
int cur = 0, ans = 1;
int main() {
    cin>>c>>v0>>v1>>a>>l;
    while(cur + v0 < c) {
        cur += v0; ans ++;
        cur -= l;
        v0 += a;
        if(v0 > v1) v0 = v1; 
    }
    cout << ans << endl;
}