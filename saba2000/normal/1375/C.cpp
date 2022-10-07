#include<bits/stdc++.h>
using namespace std;
int a[300009];
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    vector<pair<int,int> > v;

    int x = 1;
    for(int i = 1; i <= n - 1; i++){
        if(a[i] < a[i+1]) continue;
        v.push_back({a[x], a[i]});
        x = i + 1;

    }
    v.push_back({a[x], a[n]});
    stack<pair<int,int> > S;
    S.push(v[0]);
    for(int i = 1; i <v.size(); i++){

        int x = v[i].first, y = v[i].second;
        while(S.size()){
            pair<int,int>  u = S.top();
            if(u.first > y) break;
            S.pop();
            x = u.first;

        }
        S.push({x,y});
    }
    cout << (S.size()  == 1  ? "YES" : "NO" ) <<endl;
}
main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    solve();
}
}