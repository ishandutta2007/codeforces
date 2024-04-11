#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, h, l, r; cin >> n >> h >> l >> r;
    priority_queue<array<int,3>> Q;
    vector<int> v(n);
    for(auto &x : v)cin >> x;
    vector<vector<bool>> vis(2005, vector<bool>(2005,0));
    Q.push({0,0,0});
    int ans = 0;
    while(!Q.empty()){
        auto x = Q.top();
        Q.pop();
        if(vis[-x[0]][x[2]] || x[0] == -n){ans = max(ans,x[1]);continue;}
        vis[-x[0]][x[2]] = true;
        x[2]+=v[-x[0]];
        x[2]%=h;
        x[1]+=(x[2] <= r && x[2] >= l);
        x[0]--;
        Q.push(x);
        x[1]-=(x[2] <= r && x[2] >= l);
        x[2]--;
        x[2]+=h;
        x[2]%=h;
        x[1]+=(x[2] <= r && x[2] >= l);
        Q.push(x);
    }
    cout << ans << "\n";
        
    
}