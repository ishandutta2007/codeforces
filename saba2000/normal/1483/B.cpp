#include<bits/stdc++.h>
using namespace std;
int nxt[100009], prv[100009];
int a[100009];
void solve(){
    int n;
    cin >> n;
    set<int> s;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        nxt[i] = i+1;
        prv[i] = i-1;
    }
    prv[1] = n;
    nxt[n] = 1;
    for(int i = 1; i <= n; i++){
        if(__gcd(a[i], a[nxt[i]]) == 1)
            s.insert(nxt[i]);
    }
    int j = 1;
    vector<int> ans;
    while(s.size() && ans.size() < n){
        int x;
        auto it = s.lower_bound(j+1);
        if(it == s.end())
            x = *s.begin();
        else
            x = *it;
        s.erase(x);
        ans.push_back(x);
        int N = nxt[x], P = prv[x];
        if(__gcd(a[N], a[x]) == 1) s.erase(N);
        prv[N] = P;
        nxt[P] = N;
        if(__gcd(a[P], a[N]) == 1) s.insert(N);
        j = N;

    }
    cout<<ans.size()<<" ";
    for(int x : ans)
        cout<<x<<" ";
    cout<<endl;



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