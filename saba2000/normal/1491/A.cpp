
#include<bits/stdc++.h>
using namespace std;
int a[100009];
main(){
    int s= 0;
    int n,q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin >>a[i];
        s+=a[i];
    }
    for(int i =1; i <=q; i++){
        int t;
        cin >>t;
        if(t==1){
            int x;
            cin >> x;
            s -= a[x];
            a[x]^=1;
            s+=a[x];
        }
        else{
            int k;
            cin >> k;
            if(s >= k) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
}