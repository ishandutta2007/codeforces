#include<bits/stdc++.h>
using namespace std;
long long s[200009];
int a[200009];
int l[200009];
int r[200009];
vector<int> v[200009];
queue<int> q;
set<int> S;
void upd(int k){
    s[k] = 0;
    for(auto c : v[k]){
        if(s[l[c]-1] == 0 && s[r[c]] == 0)
            q.push(c);
    }
    S.erase(k);
}
void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    S.clear();
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        a[i] -= x;
        s[i] = s[i-1] + a[i];
        if(s[i] != 0) S.insert(i);
    }
    //0....0
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &l[i], &r[i]);
        v[l[i]-1].push_back(i);
        v[r[i]].push_back(i);
        if(s[l[i]-1] == 0 && s[r[i]] == 0) q.push(i);
    }
    while(q.size()){
        int x = q.front();
        q.pop();
        int L = l[x]-1, R = r[x];
        while(1){
            auto it = S.lower_bound(L);
            if(it == S.end() || *it > R) break;
            upd(*it);
        }
    }
    if(S.size()) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    for(int i = 0; i <= n; i++)
        v[i].clear();
 
}
main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}