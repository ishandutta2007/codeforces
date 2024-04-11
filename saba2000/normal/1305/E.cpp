#include<bits/stdc++.h>
using namespace std;

main(){
    int n,m;
    cin >> n>> m;
    int mx = 0;
    for(int i = 1; i <= n; i++){
        mx += (i-1)/2;
    }
    if(m > mx){
        cout<< -1<<endl;
        return 0;
    }
    int fl = 0;
    for(int i = 1; i <= n; i++){
        if(fl){
            cout<<100000000+i*10*n+1<<" ";
            continue;
        }
        if(m >= (i-1)/2){
            m -= (i-1)/2;
            cout<< i<<" ";
            continue;
        }
        cout<<(i-1) + (i-2*m)<<" " ;
        fl = 1;


    }
    cout<<endl;

}