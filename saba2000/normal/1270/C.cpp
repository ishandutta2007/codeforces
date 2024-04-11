#include<bits/stdc++.h>
#define ll long long
#define fr first
#define se second
#define pb push_back
using namespace std;
int a[200009];
main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        ll x= 0;
        ll s = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s += a[i];
            x ^= a[i];
        }
        cout<<2<<endl<<x<<" "<<s+x<<endl;
    }
}
//S 0
//S