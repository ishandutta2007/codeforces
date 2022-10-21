#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;
    if(k == 1){
        cout << n;
        return 0;
    }
    else{
        int times = 0;
        ll tmpn = n;
        while(tmpn > 0){
            tmpn /= 2;
            times++;
        }
        cout << ((ll)1 << (ll)times) - 1;
        return 0;
    }
}