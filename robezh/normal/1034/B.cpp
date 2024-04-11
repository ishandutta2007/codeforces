#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    ll tot = 1LL * n * m;
    if(n > m){
        int tmp = m; m = n, n = tmp;
    }
    if(n >= 3){
        if(n % 2 == 1 && m % 2 == 1) cout << 1LL * n * m - 1 << endl;
        else cout << 1LL * n * m << endl;
        return 0;
    }
    if(n == 1){
        int rem = m % 6;
        if(rem == 0) cout << tot << endl;
        else if(rem == 1 || rem == 5) cout << tot - 1 << endl;
        else if(rem == 2 || rem == 4) cout << tot - 2 << endl;
        else cout << tot - 3 << endl;

        return 0;
    }
    if(n == 2){
        if(m == 2) cout << tot - 4 << endl;
        else if(m == 3 || m == 7) cout << tot - 2 << endl;
        else cout << tot << endl;
        return 0;
    }



}