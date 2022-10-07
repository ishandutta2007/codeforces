#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    string a, b;
    cin >> n;
    cin >> a >> b;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int x;
        if(i % 2 == 0){
            x = i/2;
        }
        else x = n - (i+1)/2;
        int c = a[x] - '0';
        if(i % 2 == 1) c ^= 1;
        if(c == b[n-i-1] - '0')
            ans.push_back(1);
        ans.push_back(n-i);
    }
    cout<<ans.size()<<" ";
    for(int x : ans)
        cout<<x<<" ";
    cout<<endl;
}
main(){
    int t;
    cin >> t;
    while(t--){
       solve();

    }
}