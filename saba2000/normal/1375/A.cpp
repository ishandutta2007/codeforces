#include<bits/stdc++.h>
using namespace std;
int a[100009];
main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] > 0 && i % 2 == 0 ||
           a[i] < 0 && i % 2 == 1) a[i] = -a[i];

    }
    for(int i = 1; i <= n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
}