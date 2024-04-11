#include<bits/stdc++.h>
using namespace std;
main(){
    long long n, m;
    cin >> n >> m;
    if(n > m) swap(n, m);
    if(n == 1){
        long long ans = (m / 6)*6;
        m%=6;
        cout << ans + 2*max(0ll, m - 3)<<endl;
        return 0;
    }
    if(n % 4 == 0 || m % 4 == 0){
        cout << n * m << endl;
        return 0;
    }
    if(n == 2){
        if(m <= 2) cout << 0 << endl; else
        if(m == 3 || m == 7) cout << m * n - 2 << endl;
        else cout << m * n << endl;
        return 0;
    }
    if(n % 2 == 0 || m % 2 == 0){
        cout << n * m << endl;
        return 0;
    }
    cout << n * m - 1 << endl;


}