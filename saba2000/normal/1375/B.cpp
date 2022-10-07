#include<bits/stdc++.h>
using namespace std;
int a[309][309];
void solve(){
    int n, m;
    cin >> n >> m;
    int ok = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            int x = 4;
            if(i == 1 || i == n) x--;
            if(j == 1 || j == m) x--;
            if(a[i][j] > x)
                ok = 0;

            a[i][j] = x;
        }
    }
    if(!ok){ cout<<"NO"<<endl; return;}
    cout<<"YES"<<endl;
    for(int i = 1; i <= n; i++){
        for(int  j= 1 ; j <= m; j++)
        cout<<a[i][j]<<" ";
    cout<<endl;
    }
}
main(){
    int t;
    cin>>t;
    while(t--){
    solve();
}
}