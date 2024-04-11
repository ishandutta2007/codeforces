#include<bits/stdc++.h>
using namespace std;
int a[3009],f[3009];
void solve(){
    int n;
    cin >> n;
    vector<int> ans;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    while(1){
        int ok = 1;
        for(int i = 1; i < n; i++)
            if(a[i] > a[i+1]) ok = 0;
        if(ok) break;
        for(int j = 0; j <= n; j++)
            f[j] = 0;
        for(int j = 1; j <= n; j++)
            f[a[j]] = 1;
        int mex = 0;
        while(f[mex]) mex++;

        if(mex == n){
            ans.push_back(n);
            a[n] = n;
            n--;
        } else{
            ans.push_back(mex+1);
        a[mex+1] = mex;
        }

    }
    cout<<ans.size()<<endl;
    for(int x : ans)
        cout<<x<<" ";
    cout<<endl;


}
main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    solve();
}
}