#include<bits/stdc++.h>
using namespace std;
int b[100009], f[100009], h[100009],g[100009],ans[100009],val[100009];
void solve(){
    int n,x,y;
    cin >> n >> x >> y;

    for(int i = 1; i <= n+1; i++){
        f[i] = 0;
        h[i] = 0;
        g[i] = 0;
        ans[i] = 0;
        val[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        f[b[i]]++;
    }
    int s = 0;
    for(int i = 1; i <= n + 1; i++){
        if(!f[i]) continue;
        g[i] = min(f[i], n - x - f[i]);
        s += g[i];
    }
    int sx = 0;
    if(s > y){
        for(int i = 1; i <= n + 1; i++){
            int d = s - y;
            if(d > g[i]) {
                s -= g[i];
                g[i] = 0;
            }
            else{
                g[i] -= d;
                s = y;
            }
            h[i] = min(g[i], x - sx);
            sx += h[i];
        }
    }
    else{
        if(s + 2*x < y){
            cout << "NO" << endl;
            return;
        }
        int X = x;
        for(int i = 1; i <= n + 1; i++){
            while(X  && s + 2 <= y && g[i] + 2 <= f[i])
                X--, g[i] += 2, s += 2, h[i]++;
        }
        for(int i = 1; i <= n + 1; i++){
            while(X && s < y && g[i] < f[i])
                X--, g[i] ++ , s ++, h[i]++;
        }
        if(s < y){
            cout<<"NO"<<endl;
            return;
        }
        for(int i = 1; i <= n+ 1; i++){

            int d = min(g[i] - h[i], X);
            h[i] += d;
            X -= d;
        }
    }
    for(int i = 1; i <= n + 1; i++){
        if(f[i] == 0) {g[i] = n - y; break;}
    }
    set<pair<int,int> > S;
    for(int i = 1; i <= n +1; i++){
        val[i] = g[i] + f[i] - 2*h[i];
        g[i] -= h[i];
        if(g[i])
            S.insert({val[i], i});
    }
    for(int i = 1; i <= n; i++){
        int c = b[i];
        if(h[c]){
            h[c] --;
            ans[i] = c;
            continue;
        }
        auto it = (--S.end());
        if(it-> second == c){
            it--;
        }
        int x = it->first, y = it->second;
        ans[i] = y;
        S.erase(it);
        val[y]--;
        g[y]--;
        if(g[y]) S.insert({x-1, y});
        if(g[c]){
            S.erase(S.find({val[c],c}));
            val[c]--;
            S.insert({val[c], c});
        }
    }
    cout<<"YES"<<endl;
    for(int i =1 ; i <= n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;

}
main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}