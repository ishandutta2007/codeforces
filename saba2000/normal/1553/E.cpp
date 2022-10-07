#include<bits/stdc++.h>
using namespace std;
int f[300009],g[300009];
int p[300009],q[300009];
int n, m;
bool check(){
    for(int i = 1; i <= n; i++){
        g[i] = 0;
    }
    int pas = 0;
    for(int i = 1; i <= n; i++){
        if(g[i]) continue;
        pas++;
        int x = i;
        while(1){
            g[x] = 1;
            x = q[x];
            if(x == i) break;
        }
    }
    if(n - pas <= m) return 1; else return 0;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            f[i] = 0;
        for(int i = 1; i <= n; i++){
            cin >> p[i];
            f[(i - p[i]+n)%n]++;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(f[i]>=n-2*m){
                for(int j = 1; j <= n; j++){
                    q[j] = (p[j] +i - 1+n)%n+1;
                }
                if(check()) ans.push_back(i);
            }
        }
        
        cout<<ans.size()<<endl;
        for(int x : ans)
            cout<<x<<" ";
        cout<<endl;


    }

}