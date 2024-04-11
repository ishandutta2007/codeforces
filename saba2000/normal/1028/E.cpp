#include<bits/stdc++.h>
using namespace std;
long long a[800009];
long long ans[800009];
main(){
    long long n;
    cin >> n;
    for(long long i = 1; i <= n; i++){
        cin>> a[i];
        a[i+n] = a[i];
    }
    long long fl = 0, mx = 0;
    a[0] = a[n];
    for(long long i = 1;i  <= n; i++){
        mx = max(mx, a[i]);
    }
    long long K = 0;
    for(long long i = 1; i <= n; i++){
        if(a[i] == mx && a[i - 1] != mx)  K =i;
    }

    if(K == 0){
        if(mx == 0){
            cout<<"YES"<<endl;
            for(int i = 1; i <= n; i++)
                cout<<1<<" ";
                cout<<endl;
                return 0;
        }
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    ans[K] = a[K];
    ans[K + n] = a[K];
    for(long long i =K + n; i > K+1; i--){
        ans[i - 1] = ans[i] + a[i - 1];
        if(ans[i - 1] <= mx) ans[i - 1] +=ans[i];
    }
    for(long long i = 1; i <= n; i++){
        cout << max(ans[i], ans[i+n]) << " ";
    }
    cout<<endl;
}