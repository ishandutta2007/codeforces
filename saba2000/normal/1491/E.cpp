
#include<bits/stdc++.h>
using namespace std;
int f[200009], sz[200009], P[200009], F[209];
vector<int> v[200009];
void dfs(int x, int p, vector<int> &A){
    P[x] = p;
    A.push_back(x);
    sz[x] = 1;
    for(int y : v[x]){
        if(y == p || f[y] == 1) continue;
        dfs(y,x,A);
        sz[x] += sz[y];
    }
}
void dfs1(int x, int p, vector<int> &A){
    A.push_back(x);
    sz[x] = 1;
    for(int y : v[x]){
        if(y == p || f[y] == 1) continue;
        dfs1(y,x,A);
    }
}
bool dc(int x, int k){
    if(k <= 3) return 1;
    vector<int> A;
    dfs(x,0,A);
    int z = -1;
    for(int y : A){
        if(sz[y] == F[k-1]) z = y;
        if(sz[y] == F[k-2]) z = y;
    }
    if(z == -1) return 0;
    vector<int> L,R;
    int lk, rk;
    if(sz[z] == F[k-1]) lk = k-1, rk = k-2;
    else lk = k-2, rk = k-1;
    dfs(z, P[z],L);
    dfs(P[z],z, R);
    for(int y : L)
        f[y] = 1;
    int lef = dc(P[z], rk);
    for(int y : L)
        f[y] = 0;
    for(int y : R)
        f[y] = 1;
    int rig = dc(z, lk);
    return lef & rig;


}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n <= 3){
        cout << "Yes"<<endl;
        return 0;
    }
    F[0] = 1;
    F[1] = 1;
    int x = 0;
    for(int i = 2; i <= 34; i++){
        F[i] = F[i-1] + F[i-2];
        if(F[i] == n) x = i;
    }
    if(!x){
        cout <<"No"<<endl;
        return 0;
    }
    for(int i = 1; i < n; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(dc(1, x)) cout<<"Yes"<<endl;
    else cout <<"No"<<endl;
}