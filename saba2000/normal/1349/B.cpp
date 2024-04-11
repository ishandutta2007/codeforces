#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200009],s[200009];

void solve(){
    int n, k;
    cin >> n >> k;
    int ok = 0;
    int bad =  0;
    for(int i =1;i <= n; i++){
        int x;
        cin>>x;
        if(x < k) a[i] = -1, bad = 1;
        if(x >= k) a[i] = 1;
        if(x == k) ok = 1;
    }
    if(!ok){
        cout<<"no"<<endl;
        return;
    }
    if(!bad){
        cout<<"yes"<<endl;
        return;
    }
    int m = 1e9;
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1] + a[i];
        if(s[i] > m){
            cout<<"yes"<<endl;
            return;
        }
        m = min(m, s[i-1]);
    }
    cout<<"no"<<endl;
}
main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}
/*

*/