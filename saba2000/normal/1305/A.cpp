#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int a[N],b[N];
main(){

    int t;
    cin>>t;
    while(t--){
int n;cin>>n;
    for(int i = 1; i <= n; i++){
        cin >>a[i];
    }
    for(int i = 1;i  <= n; i++){
        cin>>b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i = 1; i<= n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
     for(int i = 1; i<= n; i++)
        cout<<b[i]<<" ";
    cout<<endl;
    }
}