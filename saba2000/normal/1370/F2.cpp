#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v[1009],A,B[1009];
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
    if(!a.size()) {x = -1, y = 1e9; return;}
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
    for(int i = 1; i <= n; i++){
        B[H[i] - 1].push_back(i);
    }
    int l = d+1, s = -1;

    for(int i = 256; i > 0; i/=2){
        A.clear();
        for(int j = max(0, l - i); j <= d; j++){
            for(int x : B[j])
                A.push_back(x);
        }
        int u, d1;
        ask(A, u, d1);
        if(d1 != d) l -= i;
        else s = u;
    }
    int z = d - (H[s] - 1) + 1;

    if(z == 1) ans(s, x); else{
    A.clear();

    for(int i = 1; i <= n; i++){
        if( H[i] == z && (s == x || (!par(i, s) && !par(s, i))))
            A.push_back(i);
    }
    int t;
    ask(A, t, tmp);
    ans(s, t);
    }
    for(int i= 0; i <= n; i++)
        v[i].clear(),H[i] = 0,P[i] = 0, in[i] = 0, out[i] = 0, B[i].clear();
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