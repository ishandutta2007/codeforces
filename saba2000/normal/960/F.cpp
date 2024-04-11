#include<bits/stdc++.h>
#define ll long long
using namespace std;
set<pair<int,int > > S[100009];
void ad (int u, int v, int l){
    //a1 a2 a3   a ...
    //l1 l2 l3   L...
    auto X = S[u].lower_bound({v,-1});
    if(X!=S[u].begin()){
        X --;
        if((*X).second >= l) return;
        X++;
    }
    while(1){
        auto  X = S[u].lower_bound({v,-1});
        if(X == S[u].end()) break;
        if(l < (*X) . second) break;
        S[u].erase(X);
    }
    S[u].insert({v,l});
}
main(){
    int n,m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        int P = 1;
        auto X = S[u].lower_bound({w,-1});
        if(X != S[u].begin()){
            X --;
            P = (*X).second + 1;
        }
        ans = max(ans, P);
      //  cout << v <<" "<< w <<"   "<<P << endl;
        ad(v, w, P);
    }
    cout << ans << endl;

}