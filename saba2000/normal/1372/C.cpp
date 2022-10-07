#include<bits/stdc++.h>
using namespace std;
int a[200009],f[200009];
main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int k = 0, l = n, r = 1;
        for(int i= 1; i <= n; i++){
            cin >> a[i];
            if(a[i] != i) k++, l =min(l, i), r = max(r, i);
        }
        if(!k) cout<<0<<endl;
        else if(k == r - l + 1) cout<<1<<endl;
        else cout<<2<<endl;

    }


}