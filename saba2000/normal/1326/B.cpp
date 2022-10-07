#include<bits/stdc++.h>
using namespace std;
long long a[300009],b[300009];
main(){
    long long n;
    cin >> n;
    for(long long i = 1; i <= n; i++){
        cin >> b[i];
    }
    long long m =0;
    for(long long i = 1; i <= n; i++){
        cout<<b[i]+m<<" " ;
        m = max(m, b[i]+m);
    }
}