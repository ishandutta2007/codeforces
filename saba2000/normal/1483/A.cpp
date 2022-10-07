#include<bits/stdc++.h>
using namespace std;
vector<int> v[100009];
int freq[100009];
int ans[100009];

void solve(){

    int n, m;
    cin >> n >> m;
    vector<pair<int,int> > w;
    for(int i = 1; i <= m; i++){
        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
        w.push_back({v[i].size(), i});
    }
    sort(w.begin(), w.end());
    int ok = 1;
    for(int i = 0; i < w.size(); i++){
        int x = w[i].second;
        int j = v[x][0];
        for(int y : v[x]){
            if(freq[y] < freq[j]) j = y;
        }
        ans[x] = j;
        freq[j] ++;
        if(freq[j] > (m+1)/2){
            ok = 0;
        }
    }
    if(ok){
        cout << "YES" << endl;
        for(int i = 1; i <= m; i++){
            cout << ans[i] << " ";
        }
        cout<<endl;
    }
    else {
        cout << "NO" << endl;
    }
    for(int i = 1; i <= m; i++){
        v[i].clear();
    }
    for(int i = 1; i <= n; i++){
        freq[i] = 0;
    }


}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}