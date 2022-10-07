#include<bits/stdc++.h>
#define Fi first
#define Se second
using namespace std;
long long f[10];
main(){
    long long n;
    cin >> n;
    string a,b;
    cin>>a>>b;
    for(long long i = 0; i < n; i++){
        a[i] -= '0'; b[i] -='0';
        f[a[i]*2+b[i]]++;
    }
    cout<<f[0]*f[3]+f[0]*f[2]+f[1]*f[2]<<endl;
}
//01
//00
//