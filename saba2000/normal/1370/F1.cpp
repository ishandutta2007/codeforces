#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v[1009],A;
int x, d, H[1009],P[1009], in[1009],out[1009], tim = 0, tmp;
void dfs(int x, int p){
    H[x] = H[p] + 1;
    in[x] = ++tim;
    P[x] = p;
    for(int y : v[x]){
        if(y == p) continue;
        dfs(y, x);
    }
    out[x] = ++tim;

}
void ask(vector<int> a, int &x, int &y){
    cout<<"? "<<a.size()<<" ";
    for(int v: a)
        cout<<v<<" ";
    cout<<endl;
    cin>>x>>y;
    assert(x != -1 && y != -1);
}
bool par(int u, int v){
    return in[v] >= in[u] && out[v] <= out[u];
}
void ans(int x, int y){
    cout<<"! "<<x<<" "<<y<<endl;
    string cor;
    cin>>cor;
    assert(cor == "Correct");
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        A.push_back(i);
    }
    ask(A, x, d);
    dfs(x, 0);
    vector<pair<int,int> > B;
    for(int i = 1; i <= n; i++){
        B.push_back({H[i], i});
    }
    sort(B.rbegin(), B.rend());
    int lo = 0, hi = n-1;
    while(lo < hi){
        int mid = (lo + hi)/2;
        A.clear();
        for(int i = 0 ;i <= mid; i++){
            A.push_back(B[i].second);
        }
        int d1;
        ask(A, tmp, d1);
        if(d1 == d) hi = mid;
        else lo = mid + 1;
    }
    int s = B[lo].second;
    int z = d - (H[s] - 1) + 1;
    if(z == 1) ans(s, x); else{
    A.clear();
    
    for(int i = 1; i <= n; i++){
        if(H[i] == z && !par(i, s) && !par(s, i))
            A.push_back(i);
    }
    int t;
    ask(A, t, tmp);
    ans(s, t);
    }
    for(int i= 1; i <= n; i++)
        v[i].clear(),H[i] = 0,P[i] = 0, in[i] = 0, out[i] = 0;
    tim = 0;
    A.clear();
    x = 0;
    d = 0;
    
}
main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }


}