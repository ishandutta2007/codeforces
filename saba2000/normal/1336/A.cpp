#include<bits/stdc++.h>
using namespace std;
vector<int> v[200009];
int h[200009], S[200009];
void dfs(int x, int p){
    h[x] = h[p] + 1;
    S[x] = 1;
    for(int y : v[x]){
        if(y == p) continue;
        dfs(y, x);
        S[x] = S[x] + S[y];
    }
}
main(){
    int n, k;
    cin >> n >> k;
    for(int i =1; i < n; i++){
        int a,b;
        cin >>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    vector<int > V;
    for(int i = 2; i <=n ; i++){
        V.push_back(h[i] - S[i]);
    }
    sort(V.rbegin(), V.rend());
    long long ans = 0;
    for(int i =0 ; i < k; i++)
        ans += V[i];
    cout<<ans<<endl;

}