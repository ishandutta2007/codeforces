#include<bits/stdc++.h>
using namespace std;
int a[300009];
main(){
    int t;
    cin>>t;
    while(t--){int n;
    cin>>n;
    int ok = 0;
    for(int i =1; i <= n; i++){
        cin>>a[i];
        if(i > 1 && a[i] !=a[i-1]) ok=1;
    }
    if(ok) cout<<1<<endl;
    else cout<<n<<endl;
    }


}