#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[300009],b[300009];
int l[300009],r[300009];
int on[300009], ans;
int A[300009];
vector<int> v[300009],w[300009];
int tim = 0;
void dfsB(int x){
    l[x] = ++tim;
    A[l[x]] = x;
    r[x] = l[x];
    for(int y : w[x]){
        dfsB(y);
        r[x] = r[y];
    }
}
set<int> S;
void dfsA(int x){
    S.insert(l[x]);
    int flag = 0, P;
    if(x != 1){
        auto it = S.lower_bound(l[x]);
        if(it != S.begin()){
            it--;
            P = A[*it];
            if(r[P] >= l[x]){
                S.erase(S.find(l[P]));
                flag = 1;
            }
        }
    }
    ans = max(ans, (int)S.size());
    for(int y : v[x])
        dfsA(y);

    S.erase(S.find(l[x]));
    if(flag) S.insert(l[P]);
}
void solve(){
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    for(int i = 2; i <= n; i++){
        cin >> b[i];
        w[b[i]].push_back(i);
    }
    dfsB(1); dfsA(1);
    cout<<ans<<endl;
    tim = 0; ans = 0;
    S.clear();
    for(int i =1 ; i <= n; i++){
        v[i].clear();
        w[i].clear();
        l[i] = 0, r[i] = 0, on[i] = 0; A[i] = 0;
    }

}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}