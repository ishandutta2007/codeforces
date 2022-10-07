#include<bits/stdc++.h>
using namespace std;
int F[200009],P[200009],H[200009];
vector<int> V[200009];
void dfs(int x,int p){
    F[x] = 1;
    P[x] = p;
    H[x] = H[p] + 1;
    for(int y : V[x]){
        if(F[y]) continue;
        dfs(y, x);
    }
}
main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    dfs(1, 0);
    vector<int> ans,ans1;
    for(int i = 1; i <= n; i++){
        if(H[i] % 2 == 1 && H[i] <= k)
            ans.push_back(i);
        if(H[i] % 2 == 0 && H[i] <= k)
            ans1.push_back(i);
        for(int j : V[i]){
            if(H[i] >= H[j]) continue;
            if(H[j] == H[i] + 1) continue;
            if(H[j] - H[i] + 1 <= k){
                cout << 2<<endl<<H[j] - H[i] + 1 << endl;
                int x = j;
                while(1){
                    cout<<x<<" ";
                    if(x == i) break;
                    x = P[x];
                }
                return 0;
            }

        }
    }
    cout<<1<<endl;
    if(ans1.size() > ans.size()) ans = ans1;
    for(int i = 0; i < (k+1)/2; i++)
        cout<<ans[i]<<" ";
    cout<<endl;

}