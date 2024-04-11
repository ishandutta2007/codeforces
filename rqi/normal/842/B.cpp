#include <bits/stdc++.h>
using namespace std;
int sqrtt(int x){
    int i = 0;
    while(i < 99999){
        if(i*i >x){
            return i-1;
        }
        i++;
    }
}
int main() {
    int r, d, n;
    cin >> r >> d >> n;
    int ans = 0;
    int x, y, ri;
    for(int i = 0;i < n; i++){
        cin >> x >> y >> ri;
        if(sqrtt(x*x+y*y) * sqrtt(x*x+y*y) == x*x + y*y){
            if(sqrtt(x*x + y * y) - ri >= r-d && sqrtt(x*x+y*y) + ri <= r){
                ans++;
                
            }
           
        }
        else {
            if(sqrtt(x*x + y * y) - ri >= r-d && sqrtt(x*x+y*y) + 1 + ri <= r){
                ans++;
                
            }
        }
    }
    cout << ans;
}