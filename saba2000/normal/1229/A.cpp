
#include<bits/stdc++.h>
using namespace std;
long long a[7009],b[7009],f[7009];
main(){
    int n;
    cin >> n;
    for(int i =1 ; i <= n; i++){

        cin>>a[i];
    }
    long long ans = 0,S=0;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        S +=b[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((a[i] &a[j]) != a[i])f[i]++;

        }
    }
    for(int i =1 ;i <= n ;i++){
        int fl = 0;
        for(int  j= 1; j <= n ;j++){

            if(f[j] >= n - i){
                S -= b[j];
                f[j] = -1;
                for(int i = 1; i <= n ;i ++)
                    if((a[i] & a[j])!=a[i]) f[i]--;
                fl = 1;
                break;
            }
        }
        if(!fl) break;
    }
    cout<<max(ans, S)<<endl;
}