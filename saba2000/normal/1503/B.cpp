#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<pair<int,int> > v[2];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            v[(i+j)%2].push_back({i,j});
        }
    }
    int k = n*n;
    while(k--){
        int a;
        cin>>a;
        int t, c;
        if(a == 1){
            if(v[1].size()) t=1,c=2;
            else t=0,c=3;
        }
        else if(a == 2){
            if(v[0].size()) t=0,c=1;
            else t=1,c=3;
        }
        else{
            if(v[0].size()) t=0,c=1;
            else t=1,c=2;
        }
        auto X = v[t].back();
        v[t].pop_back();
        cout<<c<<" "<<X.first<<" "<<X.second<<endl;
    }
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--){
        solve();
    }
}