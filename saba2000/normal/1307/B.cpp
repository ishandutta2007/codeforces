#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,x;
    cin >> n >>x;
    int m = 0;
    int flag = 0;
    for(int i =1 ; i <= n; i++){
        int a;
        cin >> a;
        m = max(m, a);
        if(a==x) flag =1;
    }
    if(flag)cout<<1<<endl; else
    cout << max(2,(x+m-1)/m)<<endl;
}
main(){
   int t;
   cin >> t;
   while(t--){
    solve();
   }


}