#include<bits/stdc++.h>
using namespace std;
main(){
    long long n, m, k;
    cin >> n >> m >> k;

    if((2 * n * m) % (k) == 0){
        n *= 2;
        long long k1 = __gcd(n, k);
        long long k2 = k / k1;
        if(k1 == 1) m *= 2, n/= 2;
        cout << "YES\n0 0\n"<<"0 "<<m/k2<<"\n"<<n / k1<<" "<<0<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}