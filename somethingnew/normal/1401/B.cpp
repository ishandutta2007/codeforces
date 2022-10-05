#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int long long
using namespace std;
void solve(){
    int a1,a2,a0;
    int b1,b2,b0;
    cin >> a0 >> a1 >> a2 >> b0 >> b1 >> b2;
    int ans = 0;
    int k = min(a2,b1);
    ans += k * 2;
    a2-=k;
    b1-=k;
    if(a0 && b2){
        k = min(a0,b2);
        a0-=k;
        b2-=k;
    }
    if(b0 && a1){
        k = min(a1,b0);
        a1-=k;
        b0-=k;
    }
    if(b1 && a1){
        k = min(b1,a1);
        a1-=k;
        b1-=k;
    }
    if(a2 && b2){
        k = min(a2,b2);
        a2-=k;
        b2-=k;
    }
    k = min(a1,b2);
    cout << ans - k * 2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}