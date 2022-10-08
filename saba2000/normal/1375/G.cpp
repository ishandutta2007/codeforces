#include<bits/stdc++.h>
using namespace std;
int H[200009];
vector<int> v[200009];
void dfs(int x, int p){
    H[x] = H[p] + 1;
    for(int y : v[x])
        if(y != p) dfs(y, x);
}
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    int a  = 0, b= 0;
    for(int i = 1; i <= n; i++)
        if(H[i] % 2 == 0) a++;
    else b++;
    cout << n - 1 - max(a,b);

}