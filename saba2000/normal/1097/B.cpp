#include<bits/stdc++.h>
using namespace std;
int a[109];
main(){
    int n;
    cin >> n;
    int flag = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < (1 << n); i++){
        int k = 0;
        for(int j = 0; j < n; j++){
            if((1<< j) & i) k += a[j];
            else k -= a[j];
        }
        if(k % 360 == 0) flag = 1;
    }
    if(flag) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
}