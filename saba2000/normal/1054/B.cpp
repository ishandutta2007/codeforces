#include<bits/stdc++.h>
using namespace std;
int a[500009];
main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];

    }
    int M = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == M) M++;
        else if(a[i] > M){
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    
}