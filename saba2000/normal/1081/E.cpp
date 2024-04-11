#include<bits/stdc++.h>
using namespace std;
long long a[500009];
main(){
    long long n;
    cin >> n;
    for(long long i =1;i  <= n/2; i++){
        cin >> a[2*i];
    }
    long long S = 0;
    for(long long i = 1; i <= n; i+=2){
        long long mn = sqrt(S) + 1,fl = 0;
        for(long long j = sqrt(a[i+1]); j >= 1; j--){
            if(a[i+1] % j == 0){
                long long A = j, B = a[i+1] / j;
                if(A % 2 != B % 2) continue;
                long long x = (B - A) / 2, y = (A + B) / 2;
                if(x >= mn) {
                    a[i] = x * x - S;
                    S = y * y;
                    fl = 1;
                    break;
                }
            }
        }
        if(fl == 0){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    for(long long i = 1; i <= n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}